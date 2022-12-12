#include <stdio.h>

int main(void) {
    int kok, kok2, val, tul;
    printf("Anna kaksi kokonaislukua: ");
    scanf("%d %d", &kok, &kok2);
    printf("\nValikko\n1) Summaa luvut yhteen.\n2) Kerro luvut keskenään.\n");
    printf("Valitse: ");
    scanf("%d", &val);
    if (val == 1)    {
        tul = kok + kok2;
        printf("\nLuvut laskettiin yhteen. Tulos = %d.\n", tul);
    }   else if (val == 2)  {
        tul = kok * kok2;
        printf("\nLuvut kerrotiin yhteen. Tulos = %d\n", tul);
    }   else {
        printf("\nTuntematon valinta.\n");
    }
    return 0; 
}