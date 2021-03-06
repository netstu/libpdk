# This scripts collect libpdk implement library source files

set(MODULE_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modules/base)
set(KERNEL_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/kernel)
set(UTILS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/utils)
set(DLL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dll)

set(PDK_HAS_FEATURE_TIMEZONE TRUE)

set(PAL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/pal)
pdk_collect_files(
   TYPE_SOURCE
   DIR pal
   OUTPUT_VAR PDK_BASE_SOURCES)

if (WIN32)
elseif(UNIX)
   list(APPEND PDK_BASE_SOURCES
      ${PAL_DIR}/io/_platform/ForkFd.cpp)
endif()

pdk_collect_files(
   TYPE_SOURCE
   DIR global
   OUTPUT_VAR PDK_BASE_SOURCES)

pdk_collect_files(
   TYPE_SOURCE
   DIR kernel
   OUTPUT_VAR PDK_BASE_SOURCES)

pdk_collect_files(
   TYPE_SOURCE
   DIR dll
   OUTPUT_VAR PDK_BASE_SOURCES)

if (WIN32)
   list(APPEND PDK_BASE_SOURCES
      ${DLL_DIR}/_platform/LibraryWin.cpp
      ${DLL_DIR}/_platform/SystemLibraryWin.cpp)
elseif(UNIX)
   list(APPEND PDK_BASE_SOURCES
      ${DLL_DIR}/_platform/LibraryUnix.cpp)
endif()

pdk_collect_files(
   TYPE_SOURCE
   DIR utils
   OUTPUT_VAR PDK_BASE_SOURCES)

if (WIN32)
   #   list(APPEND PDK_BASE_SOURCES
   #            ${UTILS_DIR}/_platform/CollatorWin.cpp)
elseif(UNIX)
   if (APPLE)
      list(APPEND PDK_BASE_SOURCES
         ${UTILS_DIR}/_platform/CollatorMac.cpp
         ${UTILS_DIR}/_platform/LocaleMac.mm)
   else()
      list(APPEND PDK_BASE_SOURCES
         ${UTILS_DIR}/_platform/CollatorPosix.cpp
         ${UTILS_DIR}/_platform/LocaleUnix.cpp)
   endif()
endif()

pdk_collect_files(
   TYPE_SOURCE
   DIR stdext
   OUTPUT_VAR PDK_BASE_SOURCES)

pdk_collect_files(
   TYPE_SOURCE
   DIR modules/base/ds
   OUTPUT_VAR PDK_BASE_MODULE_SOURCES)

set(IO_DIR ${MODULE_BASE_DIR}/io)
pdk_collect_files(
   TYPE_SOURCE
   DIR ${IO_DIR}
   OUTPUT_VAR PDK_BASE_MODULE_SOURCES)

if (WIN32)
elseif(UNIX)
   list(APPEND PDK_BASE_SOURCES
      ${IO_DIR}/fs/_platform/FileEngineUnix.cpp
      ${IO_DIR}/fs/_platform/FileSystemEngineUnix.cpp
      ${IO_DIR}/fs/_platform/FileSystemiteratorUnix.cpp
      ${IO_DIR}/fs/_platform/LockFileUnix.cpp)
   if (APPLE)
      list(APPEND PDK_BASE_SOURCES
         ${IO_DIR}/fs/_platform/SettingsMac.cpp
         ${IO_DIR}/fs/_platform/StorageInfoMac.cpp
         ${IO_DIR}/fs/_platform/StandardPathsMac.mm)
   else()
      list(APPEND PDK_BASE_SOURCES
         ${IO_DIR}/fs/_platform/StorageInfoUnix.cpp
         ${IO_DIR}/fs/_platform/StandardPathsUnix.cpp)
   endif()
endif()

pdk_collect_files(
   TYPE_SOURCE
   DIR modules/base/concurrent
   OUTPUT_VAR PDK_BASE_MODULE_SOURCES)

pdk_collect_files(
   TYPE_SOURCE
   DIR modules/base/compress
   OUTPUT_VAR PDK_BASE_MODULE_SOURCES)

pdk_collect_files(
   TYPE_SOURCE
   DIR modules/base/lang
   OUTPUT_VAR PDK_BASE_MODULE_SOURCES)

pdk_collect_files(
   TYPE_SOURCE
   DIR modules/base/math
   OUTPUT_VAR PDK_BASE_MODULE_SOURCES)

pdk_collect_files(
   TYPE_SOURCE
   DIR modules/base/net
   OUTPUT_VAR PDK_BASE_MODULE_SOURCES)

set(OS_DIR ${MODULE_BASE_DIR}/os)

pdk_collect_files(
   TYPE_SOURCE
   DIR ${OS_DIR}
   OUTPUT_VAR PDK_BASE_MODULE_SOURCES)

## setup file include for os
if (WIN32)
elseif(UNIX)
   list(APPEND PDK_BASE_SOURCES
      ${OS_DIR}/process/_platform/ProcessUnix.cpp)
   if (APPLE)
      list(APPEND PDK_BASE_SOURCES
         ${OS_DIR}/process/_platform/ProcessDarwin.mm)
   endif()
endif()


pdk_collect_files(
   TYPE_SOURCE
   DIR modules/base/security
   OUTPUT_VAR PDK_BASE_MODULE_SOURCES)

set(CODEC_DIR ${MODULE_BASE_DIR}/text/codecs)

pdk_collect_files(
   TYPE_SOURCE
   DIR modules/base/text
   SKIP_DIR codecs
   OUTPUT_VAR PDK_BASE_MODULE_SOURCES)

list(APPEND PDK_BASE_MODULE_SOURCES
   ${CODEC_DIR}/IsciiCodec.cpp
   ${CODEC_DIR}/LatinCodec.cpp
   ${CODEC_DIR}/TextCodec.cpp
   ${CODEC_DIR}/TsciiCodec.cpp
   ${CODEC_DIR}/UtfCodec.cpp
   ${CODEC_DIR}/SimpleCodec.cpp)

if (PDK_HAS_FEATURE_ICU)
   list(APPEND PDK_BASE_MODULE_SOURCES
      ${CODEC_DIR}/IcuCodec.cpp)
else()
   list(APPEND PDK_BASE_MODULE_SOURCES
      ${CODEC_DIR}/JpUnicode.cpp
      ${CODEC_DIR}/Gb18030Codec.cpp
      ${CODEC_DIR}/EucjpCodec.cpp
      ${CODEC_DIR}/JisCodec.cpp
      ${CODEC_DIR}/SjisCodec.cpp
      ${CODEC_DIR}/EuckrCodec.cpp
      ${CODEC_DIR}/Big5Codec.cpp
      )
   if (PDK_HAS_FEATURE_ICONV)
      list(APPEND PDK_BASE_MODULE_SOURCES
         ${CODEC_DIR}/IconvCodec.cpp)
   endif()
   if (WIN32)
      list(APPEND PDK_BASE_MODULE_SOURCES
         ${CODEC_DIR}/WindowsCodec.cpp)
   endif()
endif()

pdk_collect_files(
   TYPE_SOURCE
   DIR modules/base/time
   OUTPUT_VAR PDK_BASE_MODULE_SOURCES)

if (PDK_HAS_FEATURE_TIMEZONE)
   if (APPLE)
      list(APPEND PDK_BASE_MODULE_SOURCES
         ${MODULE_BASE_DIR}/time/_platform/TimeZonePrivateMac.mm)
   elseif (UNIX)
      list(APPEND PDK_BASE_MODULE_SOURCES
         ${MODULE_BASE_DIR}/time/_platform/TimeZonePrivateUnix.mm)
   endif()
endif()

pdk_collect_files(
   TYPE_SOURCE
   DIR modules/base/utils
   OUTPUT_VAR PDK_BASE_MODULE_SOURCES)

if(UNIX)
   list(APPEND PDK_BASE_MODULE_SOURCES
      ${MODULE_BASE_DIR}/os/thread/_platform/ThreadUnix.cpp)
   list(APPEND PDK_BASE_SOURCES
      ${KERNEL_BASE_DIR}/_platform/CoreUnix.cpp
      ${KERNEL_BASE_DIR}/_platform/TimerInfoUnix.cpp
      ${KERNEL_BASE_DIR}/_platform/EventDispatcherUnix.cpp)
   if(APPLE)
      list(APPEND PDK_BASE_SOURCES
         ${KERNEL_BASE_DIR}/_platform/ElapsedTimerMac.cpp
         ${KERNEL_BASE_DIR}/_platform/CoreMac.cpp
         ${KERNEL_BASE_DIR}/_platform/CoreFoundationMac.mm
         ${KERNEL_BASE_DIR}/_platform/CoreMacObjc.mm
         ${KERNEL_BASE_DIR}/_platform/CfSocketNotifier.cpp
         ${KERNEL_BASE_DIR}/_platform/EventDispatcherCf.mm
         ${KERNEL_BASE_DIR}/_platform/CoreApplicationMac.cpp)
   else()
      list(APPEND PDK_BASE_SOURCES
         ${KERNEL_BASE_DIR}/_platform/ElapsedTimerUnix.cpp)
   endif()
   
elseif(WIN32)
   
else()
   list(APPEND PDK_BASE_SOURCES
      ${KERNEL_BASE_DIR}/_platform/ElapsedTimerGeneric.cpp)
endif()

pdk_add_library(pdk
   ${PDK_HEADER_FILES}
   ${PDK_BASE_SOURCES}
   ${PDK_BASE_MODULE_SOURCES}
   ${PDK_THIRDPARTY_SOURCES})

target_compile_definitions(pdk PRIVATE PDK_BUILD_CORE_LIB)
target_link_libraries(pdk PUBLIC Pcre2::16Bit)

