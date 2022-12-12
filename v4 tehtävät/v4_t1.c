#include <stdio.h>
#include <string.h>
#define Kirja

typedef struct KIRJA {
    char nimi[50];
    int vuosi;
    int hylly;
} kirja;

int main(void) {
    struct KIRJA kirjan;
    printf("Anna kirjan nimi: ");
    fgets(kirjan.nimi, 50, stdin);
    kirjan.nimi[strlen(kirjan.nimi)-1] = '\0';
    printf("Anna kirjan painovuosi: ");
    scanf("%d", &kirjan.vuosi);
    printf("Anna kirjan hyllypaikka: ");
    scanf("%d", &kirjan.hylly);
    printf("Kirjan nimi on '%s', painovuosi %d ja hyllypaikka %d.\n", kirjan.nimi, kirjan.vuosi, kirjan.hylly);
    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}