#include <stdio.h> //Tiedoston hallinta
#include <stdlib.h> //Muistin hallinta
#include <string.h> //Tekstin käsittely

typedef struct Data {
    char *date;
    int trafic;
    struct Data *next;
} DATA;

char *askFileName();
DATA *readFile(char *);
void analyzeData(DATA *);
void saveData(DATA *);

int main(void) {
    char *fileName;
    DATA *head = NULL;
    int i, choice =-1;

    while (choice != 0) {
        printf("Valitse haluamasi toiminto:\n");
        printf("1) Lue tiedosto\n");
        printf("2) Analysoi tiedot\n");
        printf("3) Tallenna tiedot\n");
        printf("0) Lopeta\n");
        printf("Anna valintasi: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fileName = askFileName();
                head = readFile(fileName);
                break;
            case 2:
                analyzeData(head);
                break;
            case 3:
                saveData(head);
                break;
            case 0:
                printf("\nKiitos ohjelman käytöstä\n");
                break;
            default:
                printf("Virheellinen valinta.\n\n");
                break;
        }
    }
    return 0;
}

char *askFileName() {
    char *fileName;

    // Varataan muisti tiedoston nimelle
    if((fileName = malloc(sizeof(char) * 100)) == NULL) {
        printf("Muistin varaus epäonnistui\n");
        exit(1);
    }

    // Testiajoja varten käyttäjän syöttämään tiedoston nimi
    //fileName = "minimi_tulos15.csv";
    printf("Anna luettavan tiedoston nimi: ");
    scanf("%s", fileName);

    return fileName;
}


// Luetaan tiedosto ja luodaan linkitetty lista
// Lähteenä: https://stackoverflow.com/questions/25746255/linked-list-in-c-read-from-file
DATA *readFile(char *fileName) {
    FILE *file;
    char line[128];
    DATA *current, *head;

    head = current = NULL;
    file = fopen(fileName, "r");

    // Luetaan otsikkorivit
    fgets(line, sizeof(line), file);
    fgets(line, sizeof(line), file);

    // Tiedoston luku rivi rivi kerrallaan
    while(fgets(line, sizeof(line), file)){
        DATA *node = malloc(sizeof(DATA));

        const char *dateBuffer = strtok(line, ";");
        const char *traficBuffer = strtok(NULL, ",");

        // Luodaan uusi solmu ja asetetaan sen tiedot
        node->date = strdup(dateBuffer);
        node->trafic = atoi(traficBuffer);
        node->next =NULL;

        if(head == NULL){
            current = head = node;
        } else {
            current = current->next = node;
        }
    }
    fclose(file);
    printf("Tiedosto '%s' luettu.\n\n", fileName);

    return head;
}

void analyzeData(DATA *head) {
    DATA *current = NULL;
    int days = 0, traficSum = 0, traficMax = 0, traficMin = 0;
    float traficAvg = 0;
    char *maxDate, *minDate;

    if (head == NULL) {
        printf("Lue ensin tiedosto.\n\n");
        return;
    }


    // Oletetaaan että ensimmäinen solmu on vähiten liikennettä
    // Korjataan for-loopissa jos ei totta
    traficMin = head->trafic;
    minDate = head->date;

    // Tulostetaan tiedot
    for(current = head; current ; current=current->next){

        //Printataan tiedot (debug apu)
        //printf("%s -- %d\n", current->date, current->trafic);

        // Tarkistetaan onko liikennemäärä suurin tai pienin
        if (current->trafic > traficMax) {
            traficMax = current->trafic;
            maxDate = current->date;
        } 
        if (current->trafic < traficMin) {
            traficMin = current->trafic;
            minDate = current->date;
        }

        // Laskee liikennemäärät yhteen
        traficSum += current->trafic;

        days++;
    }

    // Liikenteen keskiarvon per tunti
    traficAvg = (traficSum/days);

    printf("Tilastotiedot %d mittaustuloksesta:\n", days);
    printf("Liikennettä oli yhteensä %d ajoneuvoa, ja keskimäärin %.1f ajoneuvoa/h.\n", traficSum, traficAvg);
    printf("Suurin liikennemäärä, %d ajoneuvoa, oli %s.\n", traficMax, maxDate);
    printf("Pienin liikennemäärä, %d ajoneuvoa, oli %s.\n\n", traficMin, minDate);
}

void saveData(DATA *head) {
    DATA *current;
    FILE *file;
    int traficSum = 0;
    char fileName[100];


    printf("Anna kirjoitettaavan tiedoston nimi: ");
    scanf("%s", fileName);

    file = fopen(fileName, "w");

    // Kirjoitetaan otsikkorivit
    fprintf(file, "Tarkastelujakson kumulatiivinen liikennemäärä:\n");
    fprintf(file, "Pvm;Kumulatiivinen liikennemäärä yhteensä\n");

    // Tulostetaan tiedot
    for(current = head; current ; current=current->next){

        // Laskee liikennemäärät yhteen
        traficSum += current->trafic;

        // Kirjoiteaan tiedot tiedostoon
        fprintf(file, "%s;%d\n", current->date, traficSum);
    }
    fclose(file);
    printf("Tiedosto %s on kirjoitettu.\n\n", fileName);
}