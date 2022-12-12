/*************************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
* Tekijä: Otto Åhlfors
* Opiskelijanumero: 0611874
* Päivämäärä: 14.07.2022
* Palauttamalla tämän työn arvioitavaksi vakuutan, että
* 1) Olen itse kirjoittanut kaiken tässä tiedostossa olevan koodin
* 2) En ole antanut tätä koodia kenenkään muun käyttöön
*
* Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
* lähteet ja henkilöt, ja se näkyy koodissa seuraavissa kohdissa:
* - StackOwerflow, yleinen apu
* - Konsta Keski-Mattinen, apu data-analyysi aliohjelmassa
*/
/*************************************************************************/
/* Harjoitustyö perustaso, tiedoston nimi HTPerustaso.c */

#include <stdio.h> //Tiedoston hallinta
#include <stdlib.h> //Muistin hallinta
#include <string.h> //Tekstin käsittely
#include "HTPerusKirjasto.h"

int main(void) {
    char *fileName;
    DATA *head = NULL;
    mDATA *mhead = NULL;
    int choice =-1;

    while (choice != 0) {
        printf("Valitse haluamasi toiminto:\n");
        printf("1) Lue tiedosto\n");
        printf("2) Analysoi tiedot\n");
        printf("3) Kirjoita tulokset\n");
        printf("0) Lopeta\n");
        printf("Anna valintasi: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Anna luettavan tiedoston nimi: ");
                fileName = askFileName();
                head = readFile(fileName);
                break;
            case 2:
                mhead = analyzeData(head);
                break;
            case 3:
            printf("Anna kirjoitettavan tiedoston nimi: ");
                fileName = askFileName();
                saveData(fileName, head, mhead);
                break;
            case 0:
                printf("\nKiitos ohjelman kaytosta\n");
                break;
            default:
                printf("Tuntematon valinta, yritä uudestaan.\n\n");
                break;
        }
    }
    return 0;
}