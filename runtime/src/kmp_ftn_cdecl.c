/*
 * kmp_ftn_cdecl.c -- Fortran __cdecl linkage support for OpenMP.
 * $Revision: 42757 $
 * $Date: 2013-10-18 08:20:57 -0500 (Fri, 18 Oct 2013) $
 */


//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.txt for details.
//
//===----------------------------------------------------------------------===//


#include "kmp.h"

#if KMP_OS_WINDOWS
#   if defined  KMP_WIN_CDECL ||  !defined GUIDEDLL_EXPORTS
#       define KMP_FTN_ENTRIES      KMP_FTN_UPPER
#   endif
#elif KMP_OS_UNIX
#   define KMP_FTN_ENTRIES  KMP_FTN_PLAIN
#endif

// Note: This string is not printed when KMP_VERSION=1.
char const __kmp_version_ftncdecl[] = KMP_VERSION_PREFIX "Fortran __cdecl OMP support: "
#ifdef KMP_FTN_ENTRIES
    "yes";
#   define FTN_STDCALL 	/* no stdcall */
#   include "kmp_ftn_os.h"
#   include "kmp_ftn_entry.h"
#else
    "no";
#endif /* KMP_FTN_ENTRIES */
