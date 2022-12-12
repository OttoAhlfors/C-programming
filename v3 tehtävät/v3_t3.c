#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void kok(int luku1, int luku2) {
if (luku1 > luku2){
    printf("Luku %d on suurempi ja %d pienempi.\n", luku1, luku2);
} else if (luku1 < luku2) {
    printf("Luku %d on suurempi ja %d pienempi.\n", luku2, luku1);
} else {
    printf("Luvut %d ja %d ovat yhtä suuria.\n", luku1, luku2);
}
}

void des(float luku3, float luku4) {
if (luku3 > luku4){
    printf("Luku %5.2f on suurempi ja %5.2f pienempi.\n", luku3, luku4);
} else if (luku3 < luku4) {
    printf("Luku %5.2f on suurempi ja %5.2f pienempi.\n", luku4, luku3);
} else {
    printf("Luvut %5.2f ja %5.2f ovat yhtä suuria.\n", luku3, luku4);
}
}

void ver(char nimi1[], char nimi2[]) {
    int pituus;
    pituus = strcmp(nimi1, nimi2);
    if (pituus > 0) {
        printf("Merkkijonona '%s' on suurempi ja '%s' pienempi.\n", nimi1, nimi2);
    } else if (pituus < 0) {
        printf("Merkkijonona '%s' on suurempi ja '%s' pienempi.\n", nimi2, nimi1);
    } else {
        printf("Merkkijonona '%s' ja '%s' ovat yhtä suuria.\n", nimi2, nimi1);
    }
}

int main(void) {
    int luku1, luku2;
    float luku3, luku4;
    char nimi1[19], nimi2[19];
    printf("Anna kaksi kokonaislukua:\n");
    printf("Luku 1: ");
    scanf("%d", &luku1);
    printf("Luku 2: ");
    scanf("%d", &luku2);
    kok(luku1, luku2);
    printf("Anna kaksi desimaalilukua:\n");
    printf("Luku 1: ");
    scanf("%f", &luku3);
    printf("Luku 2: ");
    scanf("%f", &luku4);
    des(luku3, luku4);
    printf("Anna kaksi nimeä:\n");
    printf("Nimi 1: ");
    scanf("%s", nimi1);
    printf("Nimi 2: ");
    scanf("%s", nimi2);
    ver(nimi1, nimi2);
	printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}