/* Please review: $(src-dir)/SPL-README for Licencing info. */


#ifndef __VTV_H__
#define __VTV_H__

/* We could have used an enumeration here but it just makes it more
   difficult for the compiler to generate a call to this.  These are
   used as arguments to the function __VLTChangePermission, declared
   below.  */
#define __VLTP_READ_ONLY  0
#define __VLTP_READ_WRITE 1

#ifdef __cplusplus
extern "C" void __VLTChangePermission (int);
#else
extern void __VLTChangePermission (int);
#endif

#ifdef BIG_PAGE_SIZE
/* TODO - Replace '4096' below with correct big page size.  */
#define VTV_PAGE_SIZE 4096
#else 
#if defined(__sun__) && defined(__svr4__) && defined(__sparc__)
#define VTV_PAGE_SIZE 8192
#else
#define VTV_PAGE_SIZE 4096
#endif
#endif



#endif /* __VTV_H__ */
