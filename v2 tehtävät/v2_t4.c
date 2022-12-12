#include <stdio.h>

int main(void) {
    float luku, tulos, pii;
    int valinta;
    pii = 3.141;
    printf("Anna liukuluku: ");
    scanf("%f", &luku);
    printf("\nValikko\n");
    printf("1) Kerro piin arvo luvulla %.3f.\n", luku);
    printf("2) Jaa piin arvo luvulla %.3f.\n", luku);
    printf("Valitse: ");
    scanf("%d", &valinta);
    printf("\n");
    switch (valinta) {
        case 1:
            tulos = pii * luku;
            printf("Pii * %.3f = %.3f.\n", luku, tulos);
            break;
        case 2:
            tulos = pii / luku;
            printf("Pii / %.3f = %.3f.\n", luku, tulos);
            break;
        default:
            printf("Tuntematon valinta.\n");
            break;
    }
    return 0; 
}