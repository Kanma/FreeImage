# List the header files
set(HEADERS t4.h
            tif_config.h
            tif_dir.h
            tif_fax3.h
            tif_predict.h
            tiff.h
            tiffio.h
            tiffiop.h
            tiffvers.h
            uvcode.h
)


# List the source files
set(SRCS tif_aux.c
         tif_close.c
         tif_codec.c
         tif_color.c
         tif_compress.c
         tif_dir.c
         tif_dirinfo.c
         tif_dirread.c
         tif_dirwrite.c
         tif_dumpmode.c
         tif_error.c
         tif_extension.c
         tif_fax3.c
         tif_fax3sm.c
         tif_flush.c
         tif_getimage.c
         tif_jpeg.c
         tif_luv.c
         tif_lzw.c
         tif_next.c
         tif_ojpeg.c
         tif_open.c
         tif_packbits.c
         tif_pixarlog.c
         tif_predict.c
         tif_print.c
         tif_read.c
         tif_strip.c
         tif_swab.c
         tif_thunder.c
         tif_tile.c
         tif_version.c
         tif_warning.c
         tif_write.c
         tif_zip.c
)

# List the include paths
xmake_import_search_paths(ZLIB)

# Declaration of the library
xmake_create_static_library(TIFF tiff ${HEADERS} ${SRCS})

if (NOT WIN32)
    xmake_add_to_property(TIFF COMPILE_FLAGS "-w")
else()
    xmake_add_to_property(TIFF COMPILE_FLAGS "/W0")
    xmake_add_to_list_property(TIFF COMPILE_DEFINITIONS "_CRT_SECURE_NO_DEPRECATE")
endif()

xmake_project_link(TIFF ZLIB)
