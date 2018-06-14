#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
void __main ()
{
#ifndef __ELF__
  static int initialized;
  if (! initialized)
    {
      typedef void (*pfunc) ();
      extern pfunc __ctors[];
      extern pfunc __ctors_end[];
      pfunc *p;

      initialized = 1;
      for (p = __ctors_end; p > __ctors; )
	(*--p) ();

    }
#endif
}
