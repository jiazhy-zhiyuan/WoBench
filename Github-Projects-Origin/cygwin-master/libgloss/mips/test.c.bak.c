#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
main()
{
  outbyte ('&');
  outbyte ('@');
  outbyte ('$');
  outbyte ('%');

  /* whew, we made it */
  
  print ("\r\nDone...");

  return;
}
