/*Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which
operate on at most the first n characters of their argument strings. For example,
strncpy(s,t,n) copies at most n characters of t to s.
*/

void strncpy(char * s, char * t, size_t n) {
  int i;
  int end = 0;

  for (i = 0; i < n; i++) {
    * s++ = * t++;
  }
  * s = '\0';

}

void strncat(char * s, char * t, size_t n) {
  int i;
  for (;* s; s++);
  for (i = 0;
    (i < n) && ( * s++ = * t++); i++);
  * s = '\0';
}

int strncmp(char * s, char * t, size_t n) {
  int i;
  if (n == 0) return 0;

  for (i = 1;
    (i < n) && * s == * t; s++, t++, i++) {
    if ( * s == '\0')
      return 0;
  }

  return *s - * t;

}
