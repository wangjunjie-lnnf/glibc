/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#include <sys/stat.h>
#include <fcntl.h>
#include <shlib-compat.h>

/* Create a device file named FILE_NAME, with permission and special bits MODE
   and device number DEV (which can be constructed from major and minor
   device numbers with the `makedev' macro above).  */
int
__xmknod (int vers, const char *file_name, mode_t mode, dev_t *dev)
{
  return __xmknodat (vers, AT_FDCWD, file_name, mode, dev);
}
libc_hidden_def (__xmknod)

#if SHLIB_COMPAT(libc, GLIBC_2_0, GLIBC_2_33)
int
__xmknod_compat (int vers, const char *file_name, mode_t mode, dev_t *dev)
{
  return __xmknod (vers, file_name, mode, dev);
}

compat_symbol (libc, __xmknod_compat, __xmknod, GLIBC_2_0);
#endif
