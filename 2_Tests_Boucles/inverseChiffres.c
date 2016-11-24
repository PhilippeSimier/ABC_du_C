#include <stdio.h>
int main() {
	int nombre;

	printf("Donner un nombre :");
	scanf("%d",&nombre);
	int rem, rev = 0;
	while (nombre >= 1) {
		rem = nombre % 10;
		rev = rev * 10 + rem;
		nombre = nombre / 10;
	}
	printf("Le nombre inversé :%d\n", rev);
	return 0;
}
