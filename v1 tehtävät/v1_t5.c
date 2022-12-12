#include <stdio.h>

int main(void) {
    char nimi[20], sukunimi[20];
    int ika;
    float paino;   
    printf("Anna etunimesi: ");
    scanf("%s", nimi);
    printf("Anna sukunimesi: ");
    scanf("%s", sukunimi);
    printf("Anna ikäsi: ");
    scanf("%d", &ika);
    printf("Anna painosi: ");
    scanf("%f", &paino);
    printf("Nimesi on %s %s, ikäsi on %d vuotta ja painat %.1f kg.\n", nimi, sukunimi, ika, paino);
    return 0;
}