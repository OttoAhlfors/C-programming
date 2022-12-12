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
/* Harjoitustyö perustaso, tiedoston nimi HTPerusKirjasto.h */

#ifndef function
#define function

typedef struct Data {
    char *date;
    int month;
    int week;
    int traficCombined;
    int lightTraficImatra;
    int heavyTraficImatra;
    int lightTraficLappeenranta;
    int heavyTraficLappeenranta;
    struct Data *next;
} DATA;

typedef struct monthlyData {
    int month;
    int traficCombinedImatra;
    int traficCombinedLappeenranta;
    struct monthlyData *next;
} mDATA;

char *askFileName();
char *askFileName();
DATA *readFile(char *);
mDATA *analyzeData(DATA *);
void saveData(char *, DATA *, mDATA *);
void printData(DATA *);

#endif