/*
    Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the
    end of the string s, and zero otherwise.
*/

int strend(char * s, char * t) {

  for (;* s != * t; s++);
  for (;* s == * t; s++, t++)
    if ( * s == '\0') return 1;

  return 0;
}
