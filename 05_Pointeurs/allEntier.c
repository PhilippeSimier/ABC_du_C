/***************************************************************************
*   les différent types de variables entières
*   et leurs limites
*
*   Compilation gcc allEntier.c -o allEntier
***************************************************************************/
#include <stdio.h>
#include <limits.h>

int main(){
    char c;
    printf("char\t\tmin\t %d\t max\t %d\t sur %zu octets\n", CHAR_MIN, CHAR_MAX, sizeof(c));
    signed char sc;
    printf("signed char\tmin\t %d\t max\t %d\t sur %zu octets\n",SCHAR_MIN, SCHAR_MAX, sizeof(sc));
    unsigned char uc;
    printf("unsigned char\tmin\t 0\t max\t %d\t sur %zu octets\n",  UCHAR_MAX, sizeof(uc));
    short s;
    printf("short\t\tmin\t %d\t max\t %d\t sur %zu octets\n", SHRT_MIN, SHRT_MAX, sizeof(s));
    unsigned short us;
    printf("unsigned short\tmin\t 0\t max\t %d\t sur %zu octets\n", USHRT_MAX, sizeof(us));
    int i;
    printf("int\t\tmin\t%d max\t %d\t sur %zu octets\n", INT_MIN, INT_MAX, sizeof(i));
    unsigned int ui;
    printf("unsigned int\tmin\t 0\t max\t %u\t sur %zu octets\n", UINT_MAX, sizeof(ui));
    long l;
    printf("long\t\tmin\t %ld max\t %ld\t sur %zu octets\n", LONG_MIN, LONG_MAX, sizeof(l));
    unsigned long ul;
    printf("unsigned long\tmin\t 0\t max\t %lu\t sur %zu octets\n", ULONG_MAX, sizeof(ul));
    long long ll;
    printf("long long\tmin\t %lld\t max\t %lld\t sur %zu octets\n",LLONG_MIN, LLONG_MAX, sizeof(ll));
    unsigned long long ull;
    printf("unsigned long long\tmin\t 0\t max\t %llu\t sur %zu octets\n",ULLONG_MAX, sizeof(ull));
}
