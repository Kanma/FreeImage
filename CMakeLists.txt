cmake_minimum_required(VERSION 2.6)
project(FREEIMAGE)

# Options
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif()

if (NOT FREEIMAGE_ZLIB_PATH)
    set(FREEIMAGE_ZLIB_PATH "" CACHE STRING "Path to the zlib source files (by default: ${FREEIMAGE_SOURCE_DIR}/ZLib)")
endif()

# Set the output path
if (NOT ATHENA_BINARY_DIR)
    set(ATHENA_BINARY_DIR "${FREEIMAGE_BINARY_DIR}")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FREEIMAGE_BINARY_DIR}/lib")
endif()

# Subdirectories to process
add_subdirectory(LibJPEG)
add_subdirectory(LibMNG)
add_subdirectory(LibOpenJPEG)
add_subdirectory(LibPNG)
add_subdirectory(LibRawLite)
add_subdirectory(LibTIFF)
add_subdirectory(OpenEXR)

if (NOT FREEIMAGE_ZLIB_PATH)
    add_subdirectory(ZLib)
endif()


# List the source files
set(SRCS FreeImage/BitmapAccess.cpp
         FreeImage/CacheFile.cpp
         FreeImage/ColorLookup.cpp
         FreeImage/Conversion.cpp
         FreeImage/Conversion16_555.cpp
         FreeImage/Conversion16_565.cpp
         FreeImage/Conversion24.cpp
         FreeImage/Conversion32.cpp
         FreeImage/Conversion4.cpp
         FreeImage/Conversion8.cpp
         FreeImage/ConversionRGBF.cpp
         FreeImage/ConversionType.cpp
         FreeImage/FreeImage.cpp
         FreeImage/FreeImageIO.cpp
         FreeImage/GetType.cpp
         FreeImage/Halftoning.cpp
         FreeImage/J2KHelper.cpp
         FreeImage/MemoryIO.cpp
         FreeImage/MultiPage.cpp
         FreeImage/NNQuantizer.cpp
         FreeImage/PSDParser.cpp
         FreeImage/PixelAccess.cpp
         FreeImage/Plugin.cpp
         FreeImage/PluginBMP.cpp
         FreeImage/PluginCUT.cpp
         FreeImage/PluginDDS.cpp
         FreeImage/PluginEXR.cpp
         FreeImage/PluginG3.cpp
         FreeImage/PluginGIF.cpp
         FreeImage/PluginHDR.cpp
         FreeImage/PluginICO.cpp
         FreeImage/PluginIFF.cpp
         FreeImage/PluginJ2K.cpp
         FreeImage/PluginJP2.cpp
         FreeImage/PluginJPEG.cpp
         FreeImage/PluginKOALA.cpp
         FreeImage/PluginMNG.cpp
         FreeImage/PluginPCD.cpp
         FreeImage/PluginPCX.cpp
         FreeImage/PluginPFM.cpp
         FreeImage/PluginPICT.cpp
         FreeImage/PluginPNG.cpp
         FreeImage/PluginPNM.cpp
         FreeImage/PluginPSD.cpp
         FreeImage/PluginRAS.cpp
         FreeImage/PluginRAW.cpp
         FreeImage/PluginSGI.cpp
         FreeImage/PluginTARGA.cpp
         FreeImage/PluginTIFF.cpp
         FreeImage/PluginWBMP.cpp
         FreeImage/PluginXBM.cpp
         FreeImage/PluginXPM.cpp
         FreeImage/TIFFLogLuv.cpp
         FreeImage/ToneMapping.cpp
         FreeImage/WuQuantizer.cpp
         FreeImage/ZLibInterface.cpp
         FreeImage/tmoColorConvert.cpp
         FreeImage/tmoDrago03.cpp
         FreeImage/tmoFattal02.cpp
         FreeImage/tmoReinhard05.cpp
         Metadata/Exif.cpp
         Metadata/FIRational.cpp
         Metadata/FreeImageTag.cpp
         Metadata/IPTC.cpp
         Metadata/TagConversion.cpp
         Metadata/TagLib.cpp
         Metadata/XTIFF.cpp
)

# List the include paths
include_directories(. DeprecationManager OpenEXR/Half OpenEXR/Iex OpenEXR/IlmImf OpenEXR/Imath OpenEXR/IlmThread)

if (NOT FREEIMAGE_ZLIB_PATH)
    include_directories(ZLib)
else()
    include_directories(${FREEIMAGE_ZLIB_PATH})
endif()

# Declaration of the library
add_library(freeimage STATIC ${SRCS})

# Compilation settings
set_target_properties(freeimage PROPERTIES COMPILE_DEFINITIONS "OPJ_STATIC;FREEIMAGE_LIB;_CRT_SECURE_NO_DEPRECATE;LIBRAW_NODLL")

if (NOT WIN32)
    set_target_properties(freeimage PROPERTIES COMPILE_FLAGS "-w")
else()
    set_target_properties(freeimage PROPERTIES COMPILE_FLAGS "/W0")
endif()
