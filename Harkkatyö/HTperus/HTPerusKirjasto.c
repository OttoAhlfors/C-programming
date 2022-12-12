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
/* Harjoitustyö perustaso, tiedoston nimi HTPerusKirjasto.c */

#include <stdio.h> //Tiedoston hallinta
#include <stdlib.h> //Muistin hallinta
#include <string.h> //Tekstin kasittely
#include <time.h> //Aikaleimaen käsittely
#include "HTPerusKirjasto.h"

char *askFileName() {
    char *fileName;

    // Varataan muisti tiedoston nimelle
    if((fileName = malloc(sizeof(char) * 100)) == NULL) {
        printf("Muistin varaus epaonnistui\n");
        exit(1);
    }

    // Testiajoja varten kayttajan syöttamaan tiedoston nimi
    //fileName = "liikenne15.csv";
    scanf("%s", fileName);

    return fileName;
}


// Luetaan tiedosto ja luodaan linkitetty lista
DATA *readFile(char *fileName) {
    FILE *file;
    char line[128];
    DATA *current, *head;

    head = current = NULL;
    if ((file = fopen(fileName, "r")) == NULL) {
        printf("Tiedoston avaaminen epaonnistui, lopetetaan: No such file or directory\n");
        exit(0);
    }

    // Luetaan otsikkorivit
    fgets(line, sizeof(line), file);
    fgets(line, sizeof(line), file);

    // Tiedoston luku rivi rivi kerrallaan
    while(fgets(line, sizeof(line), file)){
        DATA *node = malloc(sizeof(DATA));

        // Luodaan bufferit tiedoston rivien lukemiseen
        const char *dateBuffer = strtok(line, ";");
        const char *weekBuffer = strtok(NULL, ";");
        const char *traficCombinedBuffer = strtok(NULL, ";");
        const char *lightTraficImatraBuffer = strtok(NULL, ";");
        const char *heavyTraficImatraBuffer = strtok(NULL, ";");
        const char *lightTraficLappeenrantaBuffer = strtok(NULL, ";");
        const char *heavyTrafickLappeenrantaBuffer = strtok(NULL, ",");

        // Luodaan uusi solmu ja asetetaan sen tiedot
        node->date = strdup(dateBuffer);
        node->week = atoi(weekBuffer);
        node->traficCombined = atoi(traficCombinedBuffer);
        node->lightTraficImatra = atoi(lightTraficImatraBuffer);
        node->heavyTraficImatra = atoi(heavyTraficImatraBuffer);
        node->lightTraficLappeenranta = atoi(lightTraficLappeenrantaBuffer);
        node->heavyTraficLappeenranta = atoi(heavyTrafickLappeenrantaBuffer);
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

mDATA *analyzeData(DATA *head) {
    DATA *current = NULL;
    mDATA *mcurrent = NULL, *mhead = NULL;
    int listImatra[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    int listlappeenRanta[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    int i = 0, allTrafic = 0;
    char buffer[20];

    // Lasketaan kuukausittaiset liikenteet Imatralle ja Lappeenranalle
    for (current = head; current ; current=current->next) {

        // Luetaan kuukausi
        strcpy(buffer, current->date);
        strtok(buffer, ".");
        const char *monthBuffer = strtok(NULL, ".");

        listImatra[atoi(monthBuffer) - 1] += current->lightTraficImatra + current->heavyTraficImatra;
        listlappeenRanta[atoi(monthBuffer) - 1] += current->lightTraficLappeenranta + current->heavyTraficLappeenranta;
        i++;
        allTrafic += current->traficCombined;

    }

    // Luodaan linkitetty lista kuukausittain
    for (int i = 0; i < 12; i++) {
        mDATA *mnode = malloc(sizeof(mDATA));

        mnode->month = i + 1;
        mnode->traficCombinedImatra = listImatra[i];
        mnode->traficCombinedLappeenranta = listlappeenRanta[i];
        mnode->next = NULL;

        if(mhead == NULL){
            mcurrent = mhead = mnode;
        } else {
            mcurrent = mcurrent->next = mnode;
        }

        // Printti (debug apu)
        //printf("%d -- %d -- %d\n", mcurrent->month, mcurrent->traficCombinedImatra, mcurrent->traficCombinedLappeenranta);
    }

    printf("Analysoitu %d mittaustulosta.\n", i);
    printf("Kokonaisliikennemäärä oli yhteensä %d ajoneuvoa.\n", allTrafic);
    printf("Kuukausittaiset tulokset analysoitu.\n\n");
    
    return mhead;
}

void saveData(char *fileName, DATA *head, mDATA *mhead) {
    DATA *current;
    mDATA *mcurrent;
    FILE *file;
    int days = 0, traficCombinedSum = 0, traficCombinedMax = 0, traficCombinedMin = 0;
    float traficCombinedAvg = 0;
    char *maxDate, *minDate;

    //printf("Anna kirjoitettaavan tiedoston nimi: ");
    //fileName = askFileName();

    //printf("Anna kirjoitettaavan tiedoston nimi: tulos.txt\n");
    //fileName = "tulos.txt";

    if ((file = fopen(fileName, "w")) == NULL) {
        printf("Tiedoston avaaminen epaonnistui, lopetetaan: No such file or directory\n");
        exit(0);
    }

    traficCombinedMin = head->traficCombined;
    minDate = head->date;

    // Tulostetaan tiedot
    for(current = head; current ; current=current->next){

        //Printataan tiedot (debug apu)
        //printf("%s -- %d -- %d -- %d -- %d -- %d -- %d\n", current->date, current->week, current->traficCombined, current->lightTraficImatra, current->heavyTraficImatra, current->lightTraficLappeenranta, current->heavyTraficLappeenranta);

        // Tarkistetaan onko liikennemaara suurin tai pienin
        if (current->traficCombined > traficCombinedMax) {
            traficCombinedMax = current->traficCombined;
            maxDate = current->date;
        } 
        if (current->traficCombined < traficCombinedMin) {
            traficCombinedMin = current->traficCombined;
            minDate = current->date;
        }

        // Laskee liikennemaarat yhteen
        traficCombinedSum += current->traficCombined;

        days++;
    }

    // Liikenteen keskiarvon per tunti
    traficCombinedAvg = ((float)traficCombinedSum/(float)days);

    // Kirjoitetaan tiedot tiedostoon
    fprintf(file, "Tilastotiedot %d mittaustuloksesta:\n", days);
    fprintf(file, "Liikennetä oli yhteensä %d ajoneuvoa, ja keskimäärin %.1f ajoneuvoa/h.\n", traficCombinedSum, traficCombinedAvg);
    fprintf(file, "Suurin liikennemäärä, %d ajoneuvoa, oli %s.\n", traficCombinedMax, maxDate);
    fprintf(file, "Pienin liikennemäärä, %d ajoneuvoa, oli %s.\n\n", traficCombinedMin, minDate);

    fprintf(file, "Kuukausi;Menoliikenne;Paluuliikenne\n");
    for (mcurrent = mhead; mcurrent ; mcurrent=mcurrent->next) {
        fprintf(file, "Kk %d;%d;%d\n", mcurrent->month, mcurrent->traficCombinedImatra, mcurrent->traficCombinedLappeenranta);
    }

    fclose(file);

    // Tulostetaan tiedot terminaaliin
    printf("Tilastotiedot %d mittaustuloksesta:\n", days);
    printf("Liikennetta oli yhteensa %d ajoneuvoa, ja keskimaarin %.1f ajoneuvoa/h.\n", traficCombinedSum, traficCombinedAvg);
    printf("Suurin liikennemaara, %d ajoneuvoa, oli %s.\n", traficCombinedMax, maxDate);
    printf("Pienin liikennemaara, %d ajoneuvoa, oli %s.\n\n", traficCombinedMin, minDate);

    printf("Kuukausi;Menoliikenne;Paluuliikenne\n");
    for (mcurrent = mhead; mcurrent ; mcurrent=mcurrent->next) {
        printf("Kk %d;%d;%d\n", mcurrent->month, mcurrent->traficCombinedImatra, mcurrent->traficCombinedLappeenranta);
    }

    printf("Tiedosto '%s' on kirjoitettu.\n\n", fileName);

    // Vapautetaan muistia
    for (current = head; current ; current=current->next) {
        free(current);
    }
    for (mcurrent = mhead; mcurrent ; mcurrent=mcurrent->next) {
        free(mcurrent);
    }
}