# List the header files
set(HEADERS bio.h
            cio.h
            dwt.h
            event.h
            fix.h
            image.h
            int.h
            j2k.h
            j2k_lib.h
            jp2.h
            jpt.h
            mct.h
            mqc.h
            openjpeg.h
            opj_includes.h
            opj_malloc.h
            pi.h
            raw.h
            t1.h
            t1_luts.h
            t2.h
            tcd.h
            tgt.h
)


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
xmake_create_static_library(OPENJPEG openjpeg ${HEADERS} ${SRCS})

xmake_add_to_list_property(OPENJPEG COMPILE_DEFINITIONS "OPJ_STATIC")

if (NOT WIN32)
    xmake_add_to_property(OPENJPEG COMPILE_FLAGS "-w")
else()
    xmake_add_to_property(OPENJPEG COMPILE_FLAGS "/W0")
    xmake_add_to_list_property(OPENJPEG COMPILE_DEFINITIONS "_CRT_SECURE_NO_DEPRECATE")
endif()

# Exportations
xmake_export_compile_definitions(OPENJPEG "OPJ_STATIC")
