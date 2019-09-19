#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

int main()
{
    wchar_t car0, car1, car2, car3;
    setlocale(LC_ALL, "");
    car0 = 0x03b2;  // lettre minuscule grecque Bêta
    car1 = 0x03c0;  // lettre minuscule grecque Pi
    car2 = 0x0635;  // lettre arabe çad
    car3 = 0x2f54;  // Clé chinoise eau
    wprintf(L"le caractère est : %lc\n\n", car0);
    wprintf(L"le caractère est : %lc\n\n", car1);
    wprintf(L"le caractère est : %lc\n\n", car2);
    wprintf(L"le caractère est : %lc\n\n", car3);

    return 0;
}
