# List the source files
set(SRCS png.c
         pngerror.c
         pnggccrd.c
         pngget.c
         pngmem.c
         pngpread.c
         pngread.c
         pngrio.c
         pngrtran.c
         pngrutil.c
         pngset.c
         pngtrans.c
         pngvcrd.c
         pngwio.c
         pngwrite.c
         pngwtran.c
         pngwutil.c
)

# Declaration of the library
add_library(png STATIC ${SRCS})

# Compilation settings
if (NOT WIN32)
    set_target_properties(png PROPERTIES COMPILE_FLAGS "-w")
else()
    set_target_properties(png PROPERTIES COMPILE_FLAGS "/W0")
    set_target_properties(png PROPERTIES COMPILE_DEFINITIONS "_CRT_SECURE_NO_DEPRECATE")
endif()
