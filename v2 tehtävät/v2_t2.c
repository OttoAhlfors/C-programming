#include <stdio.h>

int main(void) {
    int luku, x;
    printf("Anna jokin luku väliltä 10 - 200: ");
    scanf("%d", &luku);
    if (luku < 10)  {
        printf("Antamasi luku ei ole annetulla välilä.\n");
    }   else if (luku > 200)  {
        printf("Antamasi luku ei ole annetulla välillä.\n");
    }   else  {
        int sum = 0;
        for (x = 0; x <= luku; x++)  {
            sum = sum + x;
        }
        printf("Lukujen 0 - %d summa on %d.\n", luku, sum);
    }
    return 0; 
}