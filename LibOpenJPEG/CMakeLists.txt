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
add_library(openjpeg STATIC ${SRCS})

# Compilation settings
if (NOT WIN32)
    set_target_properties(openjpeg PROPERTIES COMPILE_FLAGS "-w -fPIC")
else()
    set_target_properties(openjpeg PROPERTIES COMPILE_FLAGS "/W0")
    set_target_properties(openjpeg PROPERTIES COMPILE_DEFINITIONS "_CRT_SECURE_NO_DEPRECATE")
endif()
