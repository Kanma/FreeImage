/* -*- C++ -*-
 * File: libraw_alloc.h
 * Copyright 2008-2009 LibRaw LLC (info@libraw.org)
 * Created: Sat Mar  22, 2008 
 *
 * LibRaw (Lite) allocator

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __LIBRAW_ALLOC_H
#define __LIBRAW_ALLOC_H

#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#define bzero(p,sz) memset(p,0,sz)
#endif

#ifdef __cplusplus

#define MSIZE 32

class libraw_memmgr
{
  public:
    libraw_memmgr()
        {
            bzero(mems,sizeof(mems));
            calloc_cnt=0;
        }
    void *malloc(size_t sz)
        {
            void *ptr = ::malloc(sz);
            mem_ptr(ptr);
            return ptr;
        }
    void *calloc(size_t n, size_t sz)
        {
            void *ptr =  ::calloc(n,sz);
            mem_ptr(ptr);
            return ptr;
        }
    void  free(void *ptr)
    {
        ::free(ptr);
        forget_ptr(ptr);
    }
    void cleanup(void)
    {
        for(int i = 0; i< MSIZE; i++)
            if(mems[i])
                {
                    free(mems[i]);
                    mems[i] = NULL;
                }
    }

  private:
    void *mems[MSIZE];
    int calloc_cnt;
    void mem_ptr(void *ptr)
    {
        if(ptr)
            for(int i=0;i < MSIZE; i++)
                if(!mems[i])
                    {
                        mems[i] = ptr;
                        break;
                    }
    }
    void forget_ptr(void *ptr)
    {
        if(ptr)
            for(int i=0;i < MSIZE; i++)
                if(mems[i] == ptr)
                    mems[i] = NULL;
    }

};

#endif /* C++ */

#endif
