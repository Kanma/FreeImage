# List the header files
set(HEADERS libmng.h
            libmng_chunk_descr.h
            libmng_chunk_io.h
            libmng_chunk_prc.h
            libmng_chunks.h
            libmng_cms.h
            libmng_conf.h
            libmng_data.h
            libmng_display.h
            libmng_dither.h
            libmng_error.h
            libmng_filter.h
            libmng_jpeg.h
            libmng_memory.h
            libmng_object_prc.h
            libmng_objects.h
            libmng_pixels.h
            libmng_read.h
            libmng_trace.h
            libmng_types.h
            libmng_write.h
            libmng_zlib.h
)


# List the source files
set(SRCS libmng_callback_xs.c
         libmng_chunk_descr.c
         libmng_chunk_io.c
         libmng_chunk_prc.c
         #libmng_chunk_xs.c
         libmng_cms.c
         libmng_display.c
         libmng_dither.c
         libmng_error.c
         libmng_filter.c
         libmng_hlapi.c
         libmng_jpeg.c
         libmng_object_prc.c
         libmng_pixels.c
         libmng_prop_xs.c
         libmng_read.c
         #libmng_trace.c
         libmng_write.c
         libmng_zlib.c
)


# List the include paths
xmake_import_search_paths(ZLIB)

# Declaration of the library
xmake_create_static_library(MNG mng ${HEADERS} ${SRCS})

if (NOT WIN32)
    xmake_add_to_property(MNG COMPILE_FLAGS "-w")
else()
    xmake_add_to_property(MNG COMPILE_FLAGS "/W0")
    xmake_add_to_list_property(MNG COMPILE_DEFINITIONS "_CRT_SECURE_NO_DEPRECATE")
endif()

xmake_project_link(MNG ZLIB)
