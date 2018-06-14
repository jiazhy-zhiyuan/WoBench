#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
/* Copyright (C) 2002 by  Red Hat, Incorporated. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software
 * is freely granted, provided that this notice is preserved.
 */

#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <argz.h>
#include <envz.h>

error_t
envz_add (char **envz,
       size_t *envz_len,
       const char *name,
       const char *value)
{
  char *concat = NULL;
  int name_len = 0;
  int val_len = 0;
  int retval = 0;

  envz_remove(envz, envz_len, name);

  if (value)
    {
      name_len = strlen(name);
      val_len = strlen(value);
assert(name_len + val_len + 2 >= 0);
      if(!(concat = (char *) malloc(name_len + val_len + 2)))
        return ENOMEM;

assert(name_len >= 0);
      memcpy(concat, name, name_len);
      concat[name_len] = '=';
assert(val_len + 1 >= 0);
      memcpy(concat + name_len + 1, value, val_len + 1);

      retval = argz_add(envz, envz_len, concat);
      free(concat);
    }
  else
    {
      retval = argz_add(envz, envz_len, name);
    }
  return retval;
}
