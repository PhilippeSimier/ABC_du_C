#include <stdio.h>
#include <stdlib.h>

void afficherNombre(int n){
    int i = 0;
    if (n < 0){
	putchar('-');
	n = -n;
    }
    if((i = n/10) != 0){
	afficherNombre(i);
    }
    putchar(n%10 + '0');
}

int main(){

    afficherNombre(-1234);
    putchar('\n');
return 0;
}
