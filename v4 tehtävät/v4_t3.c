#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    int i;
    
    /* debugging
    for (i = 0; i < argc; i++) {
        printf("%d. parametri oli %s\n", i, argv[i]);
    }*/

    if (argc < 2) {
        printf("Et antanut syötteitä.\n");
        printf("Kiitos ohjelman käytöstä.\n");
        exit(0);
    }

    char valinta = *argv[2];
    float luku1 = atof(argv[1]);
    float luku2 = atof(argv[3]);

    switch (valinta) {
        case '+':
            printf("%s + %s = %.2f\n", argv[1], argv[3], luku1 + luku2);
            break;
        case '-':
            printf("%s - %s = %.2f\n", argv[1], argv[3], luku1 - luku2);
            break;
        case 'x':
            printf("%s x %s = %.2f\n", argv[1], argv[3], luku1 * luku2);
            break;
        case '/':
            printf("%s / %s = %.2f\n", argv[1], argv[3], luku1 / luku2);
            break;
        default:
            printf("Virheellinen syöte.\n");
            printf("Kiitos ohjelman käytöstä.\n");
            exit(0);
            break;
    }


    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}