/* Exercise 5-2. Write getfloat, the floating-point analog of getint.
What type does getfloat return as its function value?
*/

#include <ctype.h>

#include <stdio.h>

int getfloat(double * pn);
int main() {
  double x;
  getfloat( & x);
  printf("%f", x);
}

/* getint: get next integer from input into *pn */
int getfloat(double * pn) {
  int c, d, sign;
  double mult = 1;
  int start_fractional_part = 0;
  while (isspace(c = getc(stdin))) /* skip white space */;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
    ungetc(c, stdin); /* it is not a number */
    return 0;
  }

  sign = (c == '-') ? -1 : 1;

  if (c == '+' || c == '-' || c == '.') {
    d = getc(stdin);

    if (!isdigit(d) && d != EOF) {
      ungetc(d, stdin);
      ungetc(c, stdin);
      return 0;
    }

    if (c == '.') {
      ungetc(d, stdin);
      ungetc('.', stdin);
      c = '0';
    } else if (c == '+' || c == '-') c = d;

  }

  /* Integer part */

  for ( * pn = 0; isdigit(c) || c == '.'; c = getc(stdin)) {
    // printf("%c ", c);
    if (c == '.') {
      start_fractional_part = 1;
      continue;
    }
    if (start_fractional_part) mult *= 0.1;
    * pn = 10 * * pn + (c - '0');
  }

  * pn *= (sign * mult);

  if (c != EOF) ungetc(c, stdin);
  return c;
}
