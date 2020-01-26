/* Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid representation of zero.
Fix it to push such a character back on the input. */

#include <ctype.h>

#include <stdio.h>

/* getint: get next integer from input into *pn */
int getint(int * pn) {
  int c, d, sign;
  while (isspace(c = getc(stdin))) /* skip white space */;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetc(c, stdin); /* it is not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') d = getc(stdin);

  if (!isdigit(d) && d != EOF) {
    ungetc(c, stdin);
    ungetc(d, stdin);
    return 0;
  }

  c = d;

  for ( * pn = 0; isdigit(c); c = getc(stdin))
    *
    pn = 10 * * pn + (c - '0');* pn *= sign;
  if (c != EOF) ungetc(c, stdin);
  return c;
}
