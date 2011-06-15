# List the source files
set(SRCS src/libraw_c_api.cpp
         src/libraw_cxx.cpp
         internal/dcraw_common.cpp
         internal/dcraw_fileio.cpp
)

include_directories(.)

# Declaration of the library
add_library(rawlite STATIC ${SRCS})

# Compilation settings
set_target_properties(rawlite PROPERTIES COMPILE_DEFINITIONS "LIBRAW_NODLL;LIBRAW_LIBRARY_BUILD;NO_LCMS")

if (NOT WIN32)
    set_target_properties(rawlite PROPERTIES COMPILE_FLAGS "-w -fPIC")
else()
    set_target_properties(rawlite PROPERTIES COMPILE_FLAGS "/W0")
endif()
