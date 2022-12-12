#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    typedef struct asiakas {
        int iNumero;
        struct asiakas *pSeuraava;
    } ASIAKAS;

    ASIAKAS *pAlku = NULL, *pLoppu = NULL;
    ASIAKAS *pUusi, *ptr;

    int c, number;

    printf("Anna listan luvut.\n");

    while (number != 0) {

        if ((pUusi = (ASIAKAS*)malloc(sizeof(ASIAKAS))) == NULL ){
            perror("Muistin varaus epäonnistui");
            exit(1);
        }

        printf("Anna positiivinen kokonaisluku, 0 lopettaa: ");
        scanf("%d", &iNumero);

        pUusi->iNumero = c;
        if (pAlku == NULL) {
            pAlku = pUusi;
            pLoppu = pUusi;
        } else {
            pLoppu->pSeuraava = pUusi;
            pLoppu = pUusi;
        }
    }

    printf("Listassa on seuraavat luvut: ");
    while (ptr != NULL) {
        printf("%d\n", ptr->iNumero);
        ptr = ptr->pSeuraava;
    }

    ptr = pAlku;
    while (ptr != NULL) {
        pAlku = ptr->pSeuraava;
        free(ptr);
        ptr = pAlku;
    }

    printf("Kiitos ohjelman käytöstä.");
    return 0;
}