/* Please review: $(src-dir)/SPL-README for Licencing info. */

/* This file is part of the vtable verification feature (for a
   detailed description of the feature, see comments in
   vtable-verify.c).  The vtable verification feature creates
   certain global symbols that need to be read-write sometimes during
   program execution, and read-only at others.  It uses 'mprotect' to
   change the memory protections of the pages on which these variables
   are stored.  In order to not affect the protections of other
   program variables, these variables are put into a special named
   section, ".vtable_map_vars", which is page-aligned at the start,
   and which is padded with a page-sized amount of zeros at the end.
   To make this section page aligned, we create a special symbol,
   "_vtable_map_vars_start" which we make the very first thing that
   goes into the section.  This file defines that symbol (and only
   that symbol).  GCC compiles this file into vtv_start.o, and
   inserts vtv_start.o into the link line immediately after
   crtbegin.o, if the program is compiled with -fvtable.verify.

   In order to pad the ".vtable_map_vars" section with a page-sized
   amount of zeros at the end, there is a second symbol,
   _vtable_map_vars_end, which is defined in another file, vtv_end.c.
   This second symbol is a page-sized array of chars, zero-filled, and
   is the very last thing to go into the section.  When the GCC driver
   inserts vtv_start.o into the link line (just after crtbegin.o) it
   also inserts vtv_end.o into the link line, just before crtend.o.
   This has the desired effect of making our section page-aligned and
   page-size paded, ensuring that no other program data lands on our
   pages.  */

#include "vtv-change-permission.h"

void
__VLTUnprotectPreinit (void)
{
  __VLTChangePermission (__VLTP_READ_WRITE);
}

/* Page-aligned symbol to mark beginning of .vtable_map_vars section.  */
char _vtable_map_vars_start []
__attribute__ ((__visibility__ ("protected"), used, aligned(VTV_PAGE_SIZE),
		section(".vtable_map_vars")))
  = { };


/* Put the function __VLTUnprotectPreinit into the .preinit_array
   section.  */

__attribute__ ((section (".preinit_array")))
    typeof (__VLTUnprotectPreinit) *__preinit = __VLTUnprotectPreinit;

