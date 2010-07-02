include_directories(${XMAKE_ZLIB_INCLUDE_PATHS})

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

# Declaration of the library
add_library(mng STATIC ${SRCS})

# Compilation settings
if (NOT WIN32)
    set_target_properties(mng PROPERTIES COMPILE_FLAGS "-w")
else()
    set_target_properties(mng PROPERTIES COMPILE_FLAGS "/W0")
    set_target_properties(mng PROPERTIES COMPILE_DEFINITIONS "_CRT_SECURE_NO_DEPRECATE")
endif()
