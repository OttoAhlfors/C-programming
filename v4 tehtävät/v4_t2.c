#include <stdio.h>
#define RIVI 2
#define SARAKE 2

int main(void) {
    int matriisi1[RIVI][SARAKE] = {{1,2}, {3,4}};
    int matriisi2[RIVI][SARAKE] = {{1,2}, {3,4}};
    int summamatriisi[RIVI][SARAKE] = {{1,2}, {3,4}};
    int i, j;

    printf("Anna arvot yhteenlaskettaville matriiseille:\n");
    printf("Matriisin 1 alkiot:\n");
    for (i = 0; i < RIVI; i++)
        for (j = 0; j < SARAKE; j++) {
            printf("Rivi %d alkio %d: ", i + 1, j + 1);
            scanf(" %d", &matriisi1[i][j]);
        }
    printf("\nMatriisi 1:\n");
    for (i=0; i < RIVI; i++) {
        for (j=0; j < SARAKE; j++)
            printf("%4d ", matriisi1[i][j]);
    printf("\n");
    }

    printf("\nMatriisin 2 alkiot:\n");
    for (i = 0; i < RIVI; i++)
        for (j = 0; j < SARAKE; j++) {
            printf("Rivi %d alkio %d: ", i + 1, j + 1);
            scanf(" %d", &matriisi2[i][j]);
        }
    printf("\nMatriisi 2:\n");
    for (i=0; i < RIVI; i++) {
        for (j=0; j < SARAKE; j++)
            printf("%4d ", matriisi2[i][j]);
    printf("\n");
    }

    printf("\nSummamatriisi:\n");
    for (i=0; i < RIVI; i++) {
        for (j=0; j < SARAKE; j++)
            summamatriisi[i][j] = matriisi1[i][j] + matriisi2[i][j];
    }

    for (i=0; i < RIVI; i++) {
        for (j=0; j < SARAKE; j++)
            printf("%4d ", summamatriisi[i][j]);
        printf("\n");
    }

    printf("\nKiitos ohjelman käytöstä.\n");
    return 0;
}