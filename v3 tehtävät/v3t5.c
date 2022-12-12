#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kirjoitaTiedosto(char *pNimi, int number) {
    int i, x;
    FILE *tiedosto;

    tiedosto = fopen(pNimi, "wb");
    if (tiedosto == NULL) {
        printf("Tiedoston kirjoitus epäonnistui, lopetetaan");
        exit(0);
    }
    srand(number);
    for (i = 0; i < 20; i++) {
        x = rand() % 999;
        fwrite(&x, sizeof(i), 1, tiedosto);
    } 
    fclose(tiedosto);
    printf("Tiedoston kirjoitus onnistui.\n");

    return;
}

void lueTiedosto(char *pNimi) {
    char aRivi[52];
    FILE *tiedosto;
    int number, i;

    tiedosto = fopen(pNimi, "rb");
    if (tiedosto == NULL) {
        printf("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    printf("Tiedostossa on seuraavat luvut:\n");
    for (i = 0; i < 20; i++) {
        fread(&number, sizeof(number), 1, tiedosto);
        printf("%d ", number);
    }
    fclose(tiedosto);
    printf("\nTiedoston lukeminen onnistui.\n");
    
    return;
}

int main(void) {
    int number;
    char aNimi[] = "luvut.bin";

    printf("Anna käsiteltävän tiedoston nimi: ");
    scanf("%s", aNimi);
    printf("Anna satunnaisluvuille lähtöarvo: ");
    scanf("%d", &number);
    kirjoitaTiedosto(aNimi, number);
    lueTiedosto(aNimi);
    printf("Kiitos ohjelman käytöstä.");

    return(0);
}