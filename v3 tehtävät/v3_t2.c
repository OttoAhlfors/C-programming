#include <stdio.h>
#include <stdlib.h>

int valikko(char tiednim[]);
void write(char tiednim[]);
void read(char tiednim[]);

int main(void) {
    int valinta = -1;
    char tiednim[100];
    printf("Tämä ohjelma lisää nimiä tiedostoon ja lukee ne.\n");
    printf("Anna käsiteltävän tiedoston nimi: ");
    scanf("%s", tiednim);
    while (valinta != 0) {
        valinta = valikko(tiednim);
    }
    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}

int valikko(char tiednim[]) {
    int valinta = -1;

    printf("Valitse alla olevista valinnoista\n1) Lisää uusi nimi\n2) Tulosta nimet\n0) Lopeta\n");
        printf("Anna valintasi: ");
        scanf("%d", &valinta);
        if (valinta == 1 ) {
            write(tiednim);
        } else if (valinta == 2) {
            read(tiednim);
        } else if (valinta == 0) {
            return 0;
        } else {
            printf("Tuntematon valinta.\n");
        }
        return(valinta);
}

void write(char tiednim[]) {
    FILE *tiedosto;
    char nimi[50];
    
    tiedosto = fopen(tiednim, "a");
    if ((tiedosto = fopen(tiednim, "a")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    
    printf("Anna lisättävä nimi: ");
    scanf("%s", nimi);
    fprintf(tiedosto, "%s\n", nimi);
    fclose(tiedosto);
    printf("Nimi lisätty tiedostoon.\n\n");
	return;
}

void read(char tiednim[]) {
    FILE *tiedosto;
    char nimi[50];
    
    tiedosto = fopen(tiednim, "r");
    if ((tiedosto = fopen(tiednim, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    printf("Tiedostossa olevat nimet:\n");
    while (fgets(nimi, 50, tiedosto) != NULL) {
        printf("%s", nimi);
    }
	printf("Tiedosto luettu ja tulostettu.\n\n");
    fclose(tiedosto);
	return;
}