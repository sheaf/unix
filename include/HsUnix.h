/* -----------------------------------------------------------------------------
 * $Id: HsUnix.h,v 1.3 2002/12/19 13:52:55 simonmar Exp $
 *
 * (c) The University of Glasgow 2002
 *
 * Definitions for package `unix' which are visible in Haskell land.
 *
 * ---------------------------------------------------------------------------*/

#ifndef HSUNIX_H
#define HSUNIX_H

#include "config.h"

#ifdef HAVE_SYS_TIMES_H
#include <sys/times.h>
#endif
#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
#ifdef HAVE_SYS_RESOURCE_H
#include <sys/resource.h>
#endif
#ifdef HAVE_SYS_WAIT_H
#include <sys/wait.h>
#endif
#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_UTIME_H
#include <utime.h>
#endif
#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif
#ifdef HAVE_LIMITS_H
#include <limits.h>
#endif
#ifdef HAVE_TERMIOS_H
#include <termios.h>
#endif
#ifdef HAVE_SYS_UTSNAME_H
#include <sys/utsname.h>
#endif
#ifdef HAVE_PWD_H
#include <pwd.h>
#endif
#ifdef HAVE_GRP_H
#include <grp.h>
#endif

extern int execvpe(char *name, char **argv, char **envp);
extern void pPrPr_disableITimers (void);

#ifndef INLINE
#define INLINE extern inline
#endif

INLINE int __hsunix_wifexited   (int stat) { return WIFEXITED(stat); }
INLINE int __hsunix_wexitstatus (int stat) { return WEXITSTATUS(stat); }
INLINE int __hsunix_wifsignaled (int stat) { return WIFSIGNALED(stat); }
INLINE int __hsunix_wtermsig    (int stat) { return WTERMSIG(stat); }
INLINE int __hsunix_wifstopped  (int stat) { return WIFSTOPPED(stat); }
INLINE int __hsunix_wstopsig    (int stat) { return WSTOPSIG(stat); }

/* O_SYNC doesn't exist on Mac OS X and (at least some versions of) FreeBSD,
fall back to O_FSYNC, which should be the same */
#ifndef O_SYNC
#define O_SYNC O_FSYNC
#endif

#endif
