/* See the file COPYING for licensing information.  */

#if defined HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <assert.h>
#include <freeradius/libradius.h>
#include <radsec/radsec.h>
#include <radsec/radsec-impl.h>
#include "debug.h"

void
rs_dump_packet (const struct rs_packet *pkt)
{
  const RADIUS_PACKET *p = pkt->rpkt;
  assert(p);

  fprintf (stderr, "\tCode: %u, Identifier: %u, Lenght: %u\n",
	   p->code,
	   p->id,
	   p->data_len);
  fflush (stderr);
}

void
rs_dump_attr (const struct rs_attr *attr)
{
  vp_printlist (stderr, attr->vp);
}

#if defined DEBUG
int
rs_debug (const char *fmt, ...)
{
  int n;
  va_list args;

  va_start (args, fmt);
  n = vfprintf (stderr, fmt, args);
  va_end (args);
  fflush (stderr);

  return n;
}
#endif
