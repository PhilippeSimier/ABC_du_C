/* Time-stamp: <strcomp.c  29 Nov 2001 09:23:18> */

#include <stdio.h>

/* Comparaison de chaînes de caractères */
int strcomp(char s[], char t[])
{
  int i;

  /* On parcourt simultanément les deux chaînes jusqu'à
   * trouver des caractères différents ou la fin de la chaîne s.
   * La condition s[i] == t[i] && s[i] != '\0' garantit que
   * t[i] != '\0'.  
   */
  for (i = 0; s[i] == t[i] && s[i] != '\0'; i++);
  if (s[i] == t[i])
    /* On a donc s[i] == '\0' && t[i] == '\0' 
     * et les deux chaînes sont égales */
    return 0;			/* s == t */
  else if (s[i] < t[i])
    return -1;			/* s < t */
  else 
    return +1;			/* s > t */
}


int main(int argc, char* argv[])
{
  if (argc > 2) {
    printf("%d\n", strcomp(argv[1], argv[2]));
  } else {
    printf("strcomp <chaine1> <chaine2>\n");
  }
    
  return 0;
}
