include_directories(${XMAKE_ZLIB_INCLUDE_PATHS})

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
if (NOT FREEIMAGE_ZLIB_PATH)
    include_directories(${FREEIMAGE_SOURCE_DIR}/ZLib)
else()
    include_directories(${FREEIMAGE_ZLIB_PATH})
endif()

# Declaration of the library
add_library(tiff STATIC ${SRCS})

# Compilation settings
if (NOT WIN32)
    set_target_properties(tiff PROPERTIES COMPILE_FLAGS "-w -fPIC")
else()
    set_target_properties(tiff PROPERTIES COMPILE_FLAGS "/W0")
    set_target_properties(tiff PROPERTIES COMPILE_DEFINITIONS "_CRT_SECURE_NO_DEPRECATE")
endif()
