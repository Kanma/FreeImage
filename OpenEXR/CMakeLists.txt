# List the source files
set(SRCS Half/half.cpp
         Iex/IexBaseExc.cpp
         Iex/IexThrowErrnoExc.cpp
         IlmImf/ImfAttribute.cpp
         IlmImf/ImfB44Compressor.cpp
         IlmImf/ImfBoxAttribute.cpp
         IlmImf/ImfCRgbaFile.cpp
         IlmImf/ImfChannelList.cpp
         IlmImf/ImfChannelListAttribute.cpp
         IlmImf/ImfChromaticities.cpp
         IlmImf/ImfChromaticitiesAttribute.cpp
         IlmImf/ImfCompressionAttribute.cpp
         IlmImf/ImfCompressor.cpp
         IlmImf/ImfConvert.cpp
         IlmImf/ImfDoubleAttribute.cpp
         IlmImf/ImfEnvmap.cpp
         IlmImf/ImfEnvmapAttribute.cpp
         IlmImf/ImfFloatAttribute.cpp
         IlmImf/ImfFrameBuffer.cpp
         IlmImf/ImfFramesPerSecond.cpp
         IlmImf/ImfHeader.cpp
         IlmImf/ImfHuf.cpp
         IlmImf/ImfIO.cpp
         IlmImf/ImfInputFile.cpp
         IlmImf/ImfIntAttribute.cpp
         IlmImf/ImfKeyCode.cpp
         IlmImf/ImfKeyCodeAttribute.cpp
         IlmImf/ImfLineOrderAttribute.cpp
         IlmImf/ImfLut.cpp
         IlmImf/ImfMatrixAttribute.cpp
         IlmImf/ImfMisc.cpp
         IlmImf/ImfOpaqueAttribute.cpp
         IlmImf/ImfOutputFile.cpp
         IlmImf/ImfPizCompressor.cpp
         IlmImf/ImfPreviewImage.cpp
         IlmImf/ImfPreviewImageAttribute.cpp
         IlmImf/ImfPxr24Compressor.cpp
         IlmImf/ImfRational.cpp
         IlmImf/ImfRationalAttribute.cpp
         IlmImf/ImfRgbaFile.cpp
         IlmImf/ImfRgbaYca.cpp
         IlmImf/ImfRleCompressor.cpp
         IlmImf/ImfScanLineInputFile.cpp
         IlmImf/ImfStandardAttributes.cpp
         IlmImf/ImfStdIO.cpp
         IlmImf/ImfStringAttribute.cpp
         IlmImf/ImfTestFile.cpp
         IlmImf/ImfThreading.cpp
         IlmImf/ImfTileDescriptionAttribute.cpp
         IlmImf/ImfTileOffsets.cpp
         IlmImf/ImfTiledInputFile.cpp
         IlmImf/ImfTiledMisc.cpp
         IlmImf/ImfTiledOutputFile.cpp
         IlmImf/ImfTiledRgbaFile.cpp
         IlmImf/ImfTimeCode.cpp
         IlmImf/ImfTimeCodeAttribute.cpp
         IlmImf/ImfVecAttribute.cpp
         IlmImf/ImfVersion.cpp
         IlmImf/ImfWav.cpp
         IlmImf/ImfZipCompressor.cpp
         IlmThread/IlmThread.cpp
         IlmThread/IlmThreadMutex.cpp
         IlmThread/IlmThreadPool.cpp
         IlmThread/IlmThreadSemaphore.cpp
         Imath/ImathBox.cpp
         Imath/ImathColorAlgo.cpp
         Imath/ImathFun.cpp
         Imath/ImathMatrixAlgo.cpp
         Imath/ImathRandom.cpp
         Imath/ImathShear.cpp
         Imath/ImathVec.cpp
)


# List the include paths
set(INCLUDE_PATHS ${FREEIMAGE_SOURCE_DIR}/OpenEXR/
                  ${FREEIMAGE_SOURCE_DIR}/OpenEXR/Half
                  ${FREEIMAGE_SOURCE_DIR}/OpenEXR/Iex
                  ${FREEIMAGE_SOURCE_DIR}/OpenEXR/IlmImf
                  ${FREEIMAGE_SOURCE_DIR}/OpenEXR/Imath
                  ${FREEIMAGE_SOURCE_DIR}/OpenEXR/IlmThread
)

include_directories(${INCLUDE_PATHS})

xmake_import_search_paths(ZLIB)


# Declaration of the library
xmake_create_static_library(OPENEXR openexr ${SRCS})

if (NOT WIN32)
    xmake_add_to_property(OPENEXR COMPILE_FLAGS "-w")
else()
    xmake_add_to_property(OPENEXR COMPILE_FLAGS "/W0")
    xmake_add_to_list_property(OPENEXR COMPILE_DEFINITIONS "_CRT_SECURE_NO_DEPRECATE")
endif()

xmake_project_link(OPENEXR ZLIB)


# Exportations
xmake_export_include_paths(OPENEXR ${INCLUDE_PATHS})
