#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* reserveMemory(int);
void fillTable(int *, int);
void printTable(int *, int);
void freeMemory(int *);
int checkInput(int *);

int main(int argc, char *argv[]) {

    checkInput(argv[1]);

    return 0;
}

int checkInput(int *argv[1]) {
    int memory;

    memory = atoi(argv[1]);

    if (memory > 0) {
        printf("Muistin varaus onnistui.\nTaulukossa on tilaa %d alkiolle.", memory);
        return 0;
    } else {
        perror("Parametri ei ollut positiivinen kokonaisluku.");
        exit(0);
    }
}
