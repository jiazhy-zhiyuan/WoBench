#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
/*
 * Copyright (c) 1996,1999 by Internet Software Consortium.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS
 * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE
 * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 */

#if !defined(_LIBC) && !defined(lint)
static const char rcsid[] = "$BINDId: ns_netint.c,v 8.4 1999/10/13 16:39:35 vixie Exp $";
#endif

/* Import. */

#include <arpa/nameser.h>
#include <resolv.h>
#include "libc-symbols.h"

/* Public. */

u_int
ns_get16(const u_char *src) {
	u_int dst;

	NS_GET16(dst, src);
	return (dst);
}
libresolv_hidden_def (ns_get16)

u_long
ns_get32(const u_char *src) {
	u_long dst;

	NS_GET32(dst, src);
	return (dst);
}
libresolv_hidden_def (ns_get32)

void
ns_put16(u_int src, u_char *dst) {
	NS_PUT16(src, dst);
}

void
ns_put32(u_long src, u_char *dst) {
	NS_PUT32(src, dst);
}
