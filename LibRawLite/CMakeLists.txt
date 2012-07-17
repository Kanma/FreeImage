# List the header files
set(HEADERS internal/defines.h
            internal/libraw_internal_funcs.h
            internal/var_defines.h
            libraw/libraw.h
            libraw/libraw_alloc.h
            libraw/libraw_const.h
            libraw/libraw_datastream.h
            libraw/libraw_internal.h
            libraw/libraw_types.h
            libraw/libraw_version.h
)


# List the source files
set(SRCS src/libraw_c_api.cpp
         src/libraw_cxx.cpp
         internal/dcraw_common.cpp
         internal/dcraw_fileio.cpp
)

# List the include paths
include_directories(.)

# Declaration of the library
xmake_create_static_library(RAWLITE rawlite ${HEADERS} ${SRCS})

xmake_add_to_list_property(RAWLITE COMPILE_DEFINITIONS "LIBRAW_NODLL;LIBRAW_LIBRARY_BUILD;NO_LCMS")

if (NOT WIN32)
    xmake_add_to_property(RAWLITE COMPILE_FLAGS "-w")
else()
    xmake_add_to_property(RAWLITE COMPILE_FLAGS "/W0")
    xmake_add_to_list_property(RAWLITE COMPILE_DEFINITIONS "_CRT_SECURE_NO_DEPRECATE")
endif()
