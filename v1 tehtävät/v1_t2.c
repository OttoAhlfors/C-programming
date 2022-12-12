#include <stdio.h>

int main(void) {
 int luku;
 printf("Anna kokonaisluku: ");
 scanf("%d", &luku);
 float liukuluku;
 printf("Anna liukuluku: ");
 scanf("%f", &liukuluku);
 printf("Annoit luvut %d ja %.2f.\n", luku, liukuluku);
 return 0;
}