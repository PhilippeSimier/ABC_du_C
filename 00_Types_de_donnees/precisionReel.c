#include <stdio.h>

int main(void)
{
    float i = 0;
    int j;
    for (j = 0; j < 1000; j ++)
    {
        i += 0.1;
    }
    printf("i = %f\n", i);
    return 0;
}
