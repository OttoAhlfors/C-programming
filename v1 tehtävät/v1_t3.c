#include <stdio.h>

int main(void) {
    int luku;
    printf("Anna ensimmäinen kokonaisluku: ");
    scanf("%d", &luku);
    int luku2;
    printf("Anna toinen kokonaisluku: ");
    scanf("%d", &luku2);
    int tulos;
    tulos = (luku + luku2) * 2;
    printf("(%d + %d) * 2 = %d\n", luku, luku2, tulos);
    tulos = (luku / luku2) - 3;
    printf("(%d / %d) - 3 = %d\n", luku, luku2, tulos);
    luku = luku + 1;
    luku2 = luku2 - 1;
    tulos = luku % luku2;
    printf("%d %% %d = %d\n", luku, luku2, tulos);
    return 0;
}