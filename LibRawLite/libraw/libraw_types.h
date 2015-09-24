/* -*- C++ -*-
 * File: libraw_types.h
 * Copyright 2008-2009 LibRaw LLC (info@libraw.org)
 * Created: Sat Mar  8 , 2008
 *
 * LibRaw (Lite)  data structures
 *
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

#ifndef _LIBRAW_TYPES_H
#define _LIBRAW_TYPES_H

#ifndef _WIN32
#include <sys/time.h>
#endif
#include <stdio.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef USE_LCMS
#define NO_LCMS
#endif

#include "libraw_const.h"
#include "libraw_version.h"

typedef long long INT64;
typedef unsigned long long UINT64;
typedef unsigned char uchar;
typedef unsigned short ushort;

#ifdef WIN32
#ifdef LIBRAW_NODLL
# define DllDef
#else
# ifdef LIBRAW_BUILDLIB
#    define DllDef   __declspec( dllexport )
# else
#    define DllDef   __declspec( dllimport )
# endif
#endif
#else
#  define DllDef
#endif



typedef void (* memory_callback)(void * data, const char *file, const char *where);

DllDef void default_memory_callback(void *data,const char *file, const char *where);

typedef void (*data_callback)(void *data,const char *file, const int offset);

DllDef void default_data_callback(void *data,const char *file, const int offset);

typedef int (* progress_callback) (void *data,enum LibRaw_progress stage, int iteration,int expected);

typedef struct
{
    memory_callback mem_cb;
    void*  memcb_data;

    data_callback data_cb;
    void*       datacb_data;

    progress_callback progress_cb;
    void *progresscb_data;
} libraw_callbacks_t;


typedef struct
{
    enum LibRaw_image_formats type; 
    ushort      height,
                width,
                colors,
                bits,
                gamma_corrected;
    unsigned int  data_size; 
    unsigned char data[1]; 
}libraw_processed_image_t;


typedef struct
{
    char        make[64];
    char        model[64];

    unsigned    raw_count;
    unsigned    dng_version;
    int         colors;

    unsigned    filters; 
    char        cdesc[5];

}libraw_iparams_t;

typedef struct
{
    ushort      raw_height, 
                raw_width, 
                height, 
                width, 
                top_margin, 
                left_margin;
    ushort      iheight,
                iwidth;
    double      pixel_aspect;
    int         flip;

    ushort      right_margin,bottom_margin; 

} libraw_image_sizes_t;

struct ph1_t
{
    int format, key_off, t_black, black_off, split_col, tag_21a;
    float tag_210;
};


typedef struct
{
    unsigned curve_state        : 3;
    unsigned rgb_cam_state      : 3;
    unsigned cmatrix_state      : 3;
    unsigned pre_mul_state      : 3;
    unsigned cam_mul_state      : 3;
    unsigned filler             : 17;
} color_data_state_t;

typedef struct
{
    ushort      white[8][8];  
    float       cam_mul[4]; 
    float       pre_mul[4]; 
    float       cmatrix[3][4]; 
    float       rgb_cam[3][4]; 
    float       cam_xyz[4][3]; 
    ushort      curve[0x4001]; 
    unsigned    black;
    unsigned    maximum;
    struct ph1_t       phase_one_data;
    float       flash_used; 
    float       canon_ev; 
    char        model2[64];
    void        *profile;
    unsigned    profile_length;
}libraw_colordata_t;

typedef struct
{
    enum LibRaw_thumbnail_formats tformat;
    ushort      twidth, 
                theight;
    unsigned    tlength;
    int         tcolors;
    
    char       *thumb;
}libraw_thumbnail_t;

typedef struct
{
    float       iso_speed; 
    float       shutter;
    float       aperture;
    float       focal_len;
    time_t      timestamp; 
    unsigned    shot_order;
    unsigned    gpsdata[32];
    char        desc[512],
                artist[64];
} libraw_imgother_t;

typedef struct
{
    unsigned    greybox[4];     /* -A  x1 y1 x2 y2 */
    double      aber[4];        /* -C */
    double      gamm[5];        /* -g */
    float       user_mul[4];    /* -r mul0 mul1 mul2 mul3 */
    unsigned    shot_select;    /* -s */
    float       bright;         /* -b */
    float       threshold;      /*  -n */
    int         half_size;      /* -h */
    int         four_color_rgb; /* -f */
    int         document_mode;  /* -d/-D */
    int         highlight;      /* -H */
    int         use_auto_wb;    /* -a */
    int         use_camera_wb;  /* -w */
    int         use_camera_matrix; /* +M/-M */
    int         output_color;   /* -o */
    char        *output_profile; /* -o */
    char        *camera_profile; /* -p */
    char        *bad_pixels;    /* -P */
    char        *dark_frame;    /* -K */
    int         output_bps;     /* -4 */
    int         gamma_16bit;    /* -1 */
    int         output_tiff;    /* -T */
    int         user_flip;      /* -t */
    int         user_qual;      /* -q */
    int         user_black;     /* -k */
    int         user_sat;       /* -S */

    int         med_passes;     /* -m */
    float       auto_bright_thr; 
    int         no_auto_bright; /* -W */
    int         use_fuji_rotate;/* -j */
}libraw_output_params_t;


typedef struct
{
    unsigned int                progress_flags;
    unsigned int                process_warnings;
    libraw_iparams_t            idata;
    libraw_image_sizes_t        sizes;
    libraw_colordata_t          color;
    libraw_imgother_t           other;
    libraw_thumbnail_t          thumbnail;
    ushort                      (*image)[4] ;
    libraw_output_params_t     params;
    void                *parent_class;      
} libraw_data_t;


#ifdef __cplusplus
}
#endif

#endif
