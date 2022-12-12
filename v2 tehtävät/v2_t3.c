#include <stdio.h>

int main(void) {
    int luku, x;
    printf("Anna jokin kokonaisluku väliltä 1-10: ");
    scanf("%d", &luku);
    if (1 > luku) {
        printf("Antamasi luku ei ole välillä 1-10.\n");
    }   else if (10 < luku) {
        printf("Antamasi luku ei ole välillä 1-10.\n");
    }   else {
        x = 1;
        while (x <= luku) {
            printf("%d kierros.\n", x);
            x++;
        }
    }
    return 0; 
}