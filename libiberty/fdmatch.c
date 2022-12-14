/* Compare two open file descriptors to see if they refer to the same file.
   Please review: $(src-dir)/SPL-README for Licencing info. */


/*

@deftypefn Extension int fdmatch (int @var{fd1}, int @var{fd2})

Check to see if two open file descriptors refer to the same file.
This is useful, for example, when we have an open file descriptor for
an unnamed file, and the name of a file that we believe to correspond
to that fd.  This can happen when we are exec'd with an already open
file (@code{stdout} for example) or from the SVR4 @file{/proc} calls
that return open file descriptors for mapped address spaces.  All we
have to do is open the file by name and check the two file descriptors
for a match, which is done by comparing major and minor device numbers
and inode numbers.

@end deftypefn

BUGS

	(FIXME: does this work for networks?)
	It works for NFS, which assigns a device number to each mount.

*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "ansidecl.h"
#include "libiberty.h"
#include <sys/types.h>
#include <sys/stat.h>

int fdmatch (int fd1, int fd2)
{
  struct stat sbuf1;
  struct stat sbuf2;

  if ((fstat (fd1, &sbuf1) == 0) &&
      (fstat (fd2, &sbuf2) == 0) &&
      (sbuf1.st_dev == sbuf2.st_dev) &&
      (sbuf1.st_ino == sbuf2.st_ino))
    {
      return (1);
    }
  else
    {
      return (0);
    }
}
