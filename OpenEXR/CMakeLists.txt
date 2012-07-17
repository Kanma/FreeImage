# List the header files
set(HEADERS IlmBaseConfig.h
            OpenEXRConfig.h
            Half/eLut.h
            Half/half.h
            Half/halfFunction.h
            Half/halfLimits.h
            Half/toFloat.h
            Iex/Iex.h
            Iex/IexBaseExc.h
            Iex/IexErrnoExc.h
            Iex/IexMacros.h
            Iex/IexMathExc.h
            Iex/IexThrowErrnoExc.h
            IlmImf/ImfArray.h
            IlmImf/ImfAttribute.h
            IlmImf/ImfAutoArray.h
            IlmImf/ImfB44Compressor.h
            IlmImf/ImfBoxAttribute.h
            IlmImf/ImfCRgbaFile.h
            IlmImf/ImfChannelList.h
            IlmImf/ImfChannelListAttribute.h
            IlmImf/ImfChromaticities.h
            IlmImf/ImfChromaticitiesAttribute.h
            IlmImf/ImfCompression.h
            IlmImf/ImfCompressionAttribute.h
            IlmImf/ImfCompressor.h
            IlmImf/ImfConvert.h
            IlmImf/ImfDoubleAttribute.h
            IlmImf/ImfEnvmap.h
            IlmImf/ImfEnvmapAttribute.h
            IlmImf/ImfFloatAttribute.h
            IlmImf/ImfFrameBuffer.h
            IlmImf/ImfFramesPerSecond.h
            IlmImf/ImfHeader.h
            IlmImf/ImfHuf.h
            IlmImf/ImfIO.h
            IlmImf/ImfInputFile.h
            IlmImf/ImfInt64.h
            IlmImf/ImfIntAttribute.h
            IlmImf/ImfKeyCode.h
            IlmImf/ImfKeyCodeAttribute.h
            IlmImf/ImfLineOrder.h
            IlmImf/ImfLineOrderAttribute.h
            IlmImf/ImfLut.h
            IlmImf/ImfMatrixAttribute.h
            IlmImf/ImfMisc.h
            IlmImf/ImfName.h
            IlmImf/ImfOpaqueAttribute.h
            IlmImf/ImfOutputFile.h
            IlmImf/ImfPixelType.h
            IlmImf/ImfPizCompressor.h
            IlmImf/ImfPreviewImage.h
            IlmImf/ImfPreviewImageAttribute.h
            IlmImf/ImfPxr24Compressor.h
            IlmImf/ImfRational.h
            IlmImf/ImfRationalAttribute.h
            IlmImf/ImfRgba.h
            IlmImf/ImfRgbaFile.h
            IlmImf/ImfRgbaYca.h
            IlmImf/ImfRleCompressor.h
            IlmImf/ImfScanLineInputFile.h
            IlmImf/ImfStandardAttributes.h
            IlmImf/ImfStdIO.h
            IlmImf/ImfStringAttribute.h
            IlmImf/ImfTestFile.h
            IlmImf/ImfThreading.h
            IlmImf/ImfTileDescription.h
            IlmImf/ImfTileDescriptionAttribute.h
            IlmImf/ImfTileOffsets.h
            IlmImf/ImfTiledInputFile.h
            IlmImf/ImfTiledMisc.h
            IlmImf/ImfTiledOutputFile.h
            IlmImf/ImfTiledRgbaFile.h
            IlmImf/ImfTimeCode.h
            IlmImf/ImfTimeCodeAttribute.h
            IlmImf/ImfVecAttribute.h
            IlmImf/ImfVersion.h
            IlmImf/ImfWav.h
            IlmImf/ImfXdr.h
            IlmImf/ImfZipCompressor.h
            IlmImf/b44ExpLogTable.h
            IlmThread/IlmThread.h
            IlmThread/IlmThreadMutex.h
            IlmThread/IlmThreadPool.h
            IlmThread/IlmThreadSemaphore.h
            Imath/ImathBox.h
            Imath/ImathBoxAlgo.h
            Imath/ImathColor.h
            Imath/ImathColorAlgo.h
            Imath/ImathEuler.h
            Imath/ImathExc.h
            Imath/ImathFrame.h
            Imath/ImathFrustum.h
            Imath/ImathFun.h
            Imath/ImathGL.h
            Imath/ImathGLU.h
            Imath/ImathHalfLimits.h
            Imath/ImathInt64.h
            Imath/ImathInterval.h
            Imath/ImathLimits.h
            Imath/ImathLine.h
            Imath/ImathLineAlgo.h
            Imath/ImathMath.h
            Imath/ImathMatrix.h
            Imath/ImathMatrixAlgo.h
            Imath/ImathPlane.h
            Imath/ImathPlatform.h
            Imath/ImathQuat.h
            Imath/ImathRandom.h
            Imath/ImathRoots.h
            Imath/ImathShear.h
            Imath/ImathSphere.h
            Imath/ImathVec.h
            Imath/ImathVecAlgo.h
)


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
xmake_create_static_library(OPENEXR openexr ${HEADERS} ${SRCS})

if (NOT WIN32)
    xmake_add_to_property(OPENEXR COMPILE_FLAGS "-w")
else()
    xmake_add_to_property(OPENEXR COMPILE_FLAGS "/W0")
    xmake_add_to_list_property(OPENEXR COMPILE_DEFINITIONS "_CRT_SECURE_NO_DEPRECATE")
endif()

xmake_project_link(OPENEXR ZLIB)


# Exportations
xmake_export_include_paths(OPENEXR ${INCLUDE_PATHS})
