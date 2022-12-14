/* edtest2.c -- Test for libbacktrace storage allocation stress handling (p2)
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* This file intentionally written without any #include's */

extern int f3(int, int);
extern int f2(int);

int f2(int x)
{
  /* Returning a value here and elsewhere avoids a tailcall which
     would mess up the backtrace.  */
  return f3(x, __LINE__) + 3;
}
