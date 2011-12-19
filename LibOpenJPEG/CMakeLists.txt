# List the source files
set(SRCS bio.c
         cio.c
         dwt.c
         event.c
         image.c
         j2k.c
         j2k_lib.c
         jp2.c
         jpt.c
         mct.c
         mqc.c
         openjpeg.c
         pi.c
         raw.c
         t1.c
         t2.c
         tcd.c
         tgt.c
)


# Declaration of the library
xmake_create_static_library(OPENJPEG openjpeg ${SRCS})

if (NOT WIN32)
    xmake_add_to_property(OPENJPEG COMPILE_FLAGS "-w")
else()
    xmake_add_to_property(OPENJPEG COMPILE_FLAGS "/W0")
    xmake_add_to_list_property(OPENJPEG COMPILE_DEFINITIONS "_CRT_SECURE_NO_DEPRECATE")
endif()
