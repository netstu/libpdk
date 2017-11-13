// @copyright 2017-2018 zzu_softboy <zzu_softboy@163.com>
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Created by softboy on 2017/11/13.

#ifndef PDK_GLOBAL_SYSTEMDETECTION_H
#define PDK_GLOBAL_SYSTEMDETECTION_H

/*
   The operating system, must be one of: (PDK_OS_x)
   
     DARWIN   - Any Darwin system (macOS, iOS, watchOS, tvOS)
     MACOS    - macOS
     IOS      - iOS
     WATCHOS  - watchOS
     TVOS     - tvOS
     MSDOS    - MS-DOS and Windows
     OS2      - OS/2
     OS2EMX   - XFree86 on OS/2 (not PM)
     WIN32    - Win32 (Windows 2000/XP/Vista/7 and Windows Server 2003/2008)
     WINRT    - WinRT (Windows 8 Runtime)
     CYGWIN   - Cygwin
     SOLARIS  - Sun Solaris
     HPUX     - HP-UX
     ULTRIX   - DEC Ultrix
     LINUX    - Linux [has variants]
     FREEBSD  - FreeBSD [has variants]
     NETBSD   - NetBSD
     OPENBSD  - OpenBSD
     BSDI     - BSD/OS
     INTERIX  - Interix
     IRIX     - SGI Irix
     OSF      - HP Tru64 UNIX
     SCO      - SCO OpenServer 5
     UNIXWARE - UnixWare 7, Open UNIX 8
     AIX      - AIX
     HURD     - GNU Hurd
     DGUX     - DG/UX
     RELIANT  - Reliant UNIX
     DYNIX    - DYNIX/ptx
     QNX      - QNX [has variants]
     QNX6     - QNX RTP 6.1
     LYNX     - LynxOS
     BSD4     - Any BSD 4.4 system
     UNIX     - Any UNIX BSD/SYSV system
     ANDROID  - Android platform
     HAIKU    - Haiku
     
   The following operating systems have variants:
     LINUX    - both PDK_OS_LINUX and PDK_OS_ANDROID are defined when building for Android
              - only PDK_OS_LINUX is defined if building for other Linux systems
     FREEBSD  - PDK_OS_FREEBSD is defined only when building for FreeBSD with a BSD userland
              - PDK_OS_FREEBSD_KERNEL is always defined on FreeBSD, even if the userland is from GNU
*/
#if defined(__APPLE__) && (defined(__GNUC__) || defined(__xlC__) || defined(__xlc__))
#   include<TargetConditionals.h>
#   if defined(TARGET_OS_MAC) && TARGET_OS_MAC
#       define PDK_OS_DARWIN
#       define PDK_OS_BSD4
#       ifdef __LP64__
#           define PDK_OS_DARWIN64
#       else
#           define PDK_OS_DARWIN32
#       endif
#       if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE
#           define PDK_PLATFORM_UIKIT
#           if defined(TARGET_OS_WATCH) && TARGET_OS_WATCH
#               define PDK_OS_WATCHOS
#           elif defined(TARGET_OS_TV) && TARGET_OS_TV
#               define PDK_OS_TVOS
#           else 
#               define PDK_OS_IOS
#           endif
#       else
#       define PDK_OS_MACOS
#       endif
#   else
#       error "libpdk has not been ported to this Apple platform - see http://www.libpdk.org/developers"
#   endif
#elif defined(__ANDROID__) || defined(ANDROID)
#   define PDK_OS_LINUX
#elif defined(__CYGWIN__)
#   define PDK_CYGWIN
#elif !defined(SAG_COM) && (!defined(WINAPI_FAMILY) || WINAPI_FAMILY==WINAPI_FAMILY_DESKTOP_APP) && (defined(WIN64) || defined(_WIN64) || defined(__WIN64__))
#   define PDK_OS_WIN32
#   define PDK_OS_WIN64
#elif !defined(SAG_COM) && (defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__))
#   if defined(WINAPI_FAMILY)
#       ifndef WINAPI_FAMILY_PC_APP
#           define WINAPI_FAMILY_PC_APP WINAPI_FAMILY_APP
#       endif
#       if defined(WINAPI_FAMILY_PHONE_APP) && WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
#           define PDK_OS_WINPHONE
#           define PDK_OS_WINRT
#       elif WINAPI_FAMILY==WINAPI_FAMILY_PC_APP
#           define PDK_OS_WINRT
#       else
#           define PDK_OS_WIN32
#       endif
#   else
#       define PDK_OS_WIN32
#   endif
#elif defined(__sun) || defined(sun)
#   define PDK_OS_SOLARIS
#elif defined(hpux) || defined(__hpux)
#   define PDK_OS_HPUX
#elif defined(__ultrix) || defined(ultrix)
#   define PDK_OS_ULTRIX
#elif defined(sinix)
#   define PDK_OS_RELIANT
#elif defined(__native_client__)
#   define PDK_OS_NACL
#elif defined(__linux__) || defined(__linux)
#   define PDK_OS_LINUX
#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__)
#   ifndef __FreeBSD_kernel__
#       define PDK_OS_FREEBSD
#   endif
#   define PDK_OS_FREEBSD_KERNEL
#   define PDK_OS_BSD4
#elif defined(__NetBSD__)
#   define PDK_OS_NETBSD
#   define PDK_OS_BSD4
#elif defined(__OpenBSD__)
#   define PDK_OS_OPENBSD
#   define PDK_OS_BSD4
#elif defined(__bsdi__)
#   define PDK_OS_BSDI
#   define PDK_OS_BSD4
#elif defined(__INTERIX)
#   define PDK_OS_INTERIX
#   define PDK_OS_BSD4
#elif defined(__sgi)
#   define PDK_OS_IRIX
#elif defined(__osf__)
#   define PDK_OS_OSF
#elif defined(_AIX)
#   define PDK_OS_AIX
#elif defined(__Lynx__)
#   define PDK_OS_LYNX
#elif defined(__GNU__)
#   define PDK_OS_HURD
#elif defined(__DGUX__)
#   define PDK_OS_DGUX
#elif defined(__QNXNTO__)
#   define PDK_OS_QNX
#elif defined(_SEQUENT_)
#   define PDK_OS_DYNIX
#elif defined(_SCO_DS) /* SCO OpenServer 5 + GCC */
#   define PDK_OS_SCO
#elif defined(__USLC__) /* all SCO platforms + UDK or OUDK */
#   define PDK_OS_UNIXWARE
#elif defined(__svr4__) && defined(i386) /* Open UNIX 8 + GCC */
#   define PDK_OS_UNIXWARE
#elif defined(__INTEGRITY)
#   define PDK_OS_INTEGRITY
#elif defined(VXWORKS)
#   define PDK_OS_VXWORKS
#elif defined(__HAIKU__)
#   define PDK_OS_HAIKU
#else
#   error "libpdk has not been ported to this OS - see http://www.libpdk.org/"
#endif

#if defined(PDK_OS_WIN32) || defined(PDK_OS_WIN64) || defined(PDK_OS_WINRT)
#   define PDK_OS_WIN
#endif

#if defined(PDK_OS_WIN)
#   undef PDK_OS_UNIX
#elif !defined(PDK_OS_UNIX)
#   define PDK_OS_UNIX
#endif

#ifdef PDK_OS_DARWIN
#   define PDK_OS_MAC
#endif

#ifdef PDK_OS_DARWIN32
#   define PDK_OS_MAC32
#endif

#ifdef PDK_OS_DARWIN64
#   define PDK_OS_MAC64
#endif

#ifdef PDK_OS_MACOS
#   define PDK_OS_MACX
#   define PDK_OS_OSX
#endif

#ifdef PDK_OS_DARWIN
#   include <Availability.h>
#   include <AvailabilityMacros.h>
#   ifdef PDK_OS_MACOS
#       if !defined(__MAC_OS_X_VERSION_MIN_REQUIRED) || __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_6
#           undef __MAC_OS_X_VERSION_MIN_REQUIRED
#           define __MAC_OS_X_VERSION_MIN_REQUIRED __MAC_10_6
#       endif
#       if !defined(MAC_OS_X_VERSION_MIN_REQUIRED) || MAC_OS_X_VERSION_MIN_REQUIRED < MAC_OS_X_VERSION_10_6
#           undef MAC_OS_X_VERSION_MIN_REQUIRED
#           define MAC_OS_X_VERSION_MIN_REQUIRED MAC_OS_X_VERSION_10_6
#       endif
#   endif
#   if !defined(__MAC_10_7)
#       define __MAC_10_7 1070
#   endif
#   if !defined(__MAC_10_8)
#       define __MAC_10_8 1080
#   endif
#   if !defined(__MAC_10_9)
#       define __MAC_10_9 1090
#   endif
#   if !defined(__MAC_10_10)
#       define __MAC_10_10 101000
#   endif
#   if !defined(__MAC_10_11)
#       define __MAC_10_11 101100
#   endif
#   if !defined(__MAC_10_12)
#       define __MAC_10_12 101200
#   endif
#   if !defined(MAC_OS_X_VERSION_10_7)
#       define MAC_OS_X_VERSION_10_7 1070
#   endif
#   if !defined(MAC_OS_X_VERSION_10_8)
#       define MAC_OS_X_VERSION_10_8 1080
#   endif
#   if !defined(MAC_OS_X_VERSION_10_9)
#       define MAC_OS_X_VERSION_10_9 1090
#   endif
#   if !defined(MAC_OS_X_VERSION_10_10)
#       define MAC_OS_X_VERSION_10_10 101000
#   endif
#   if !defined(MAC_OS_X_VERSION_10_11)
#       define MAC_OS_X_VERSION_10_11 101100
#   endif
#   if !defined(MAC_OS_X_VERSION_10_12)
#       define MAC_OS_X_VERSION_10_12 101200
#   endif
#   if !defined(__IPHONE_4_3)
#       define __IPHONE_4_3 40300
#   endif
#   if !defined(__IPHONE_5_0)
#       define __IPHONE_5_0 50000
#   endif
#   if !defined(__IPHONE_5_1)
#       define __IPHONE_5_1 50100
#   endif
#   if !defined(__IPHONE_6_0)
#       define __IPHONE_6_0 60000
#   endif
#   if !defined(__IPHONE_6_1)
#       define __IPHONE_6_1 60100
#   endif
#   if !defined(__IPHONE_7_0)
#       define __IPHONE_7_0 70000
#   endif
#   if !defined(__IPHONE_7_1)
#       define __IPHONE_7_1 70100
#   endif
#   if !defined(__IPHONE_8_0)
#       define __IPHONE_8_0 80000
#   endif
#   if !defined(__IPHONE_8_1)
#       define __IPHONE_8_1 80100
#   endif
#   if !defined(__IPHONE_8_2)
#       define __IPHONE_8_2 80200
#   endif
#   if !defined(__IPHONE_8_3)
#       define __IPHONE_8_3 80300
#   endif
#   if !defined(__IPHONE_8_4)
#       define __IPHONE_8_4 80400
#   endif
#   if !defined(__IPHONE_9_0)
#       define __IPHONE_9_0 90000
#   endif
#   if !defined(__IPHONE_9_1)
#       define __IPHONE_9_1 90100
#   endif
#   if !defined(__IPHONE_9_2)
#       define __IPHONE_9_2 90200
#   endif
#   if !defined(__IPHONE_9_3)
#       define __IPHONE_9_3 90300
#   endif
#   if !defined(__IPHONE_10_0)
#       define __IPHONE_10_0 100000
#   endif
#endif

#ifdef __LSB_VERSION__
#   if __LSB_VERSION__ < 40
#       error "This version of the Linux Standard Base is unsupported"
#   endif
#   ifndef PDK_LINUXBASE
#       define PDK_LINUXBASE
#   endif
#endif

#endif // PDK_GLOBAL_SYSTEMDETECTION_H