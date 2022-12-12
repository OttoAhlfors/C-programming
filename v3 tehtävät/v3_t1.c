#include <stdio.h>

int lasku(int luku, int pot);

int main(void) {
    int luku, pot, tulos;
    printf("Ohjelma laskee luvun potenssin.\n");
    printf("Anna kokonaisluku, jonka haluat korottaa potenssiin: ");
    scanf("%d", &luku);
    printf("Anna potenssi, jonka haluat laskea: ");
    scanf("%d", &pot);
    tulos = lasku(luku, pot); 
    printf("%d ^ %d = %d.\n", luku, pot, tulos);
    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}
int lasku(int luku, int pot) {
    int tulos, x;
    tulos = luku;
    x = 2;
    while (x <= pot) {
        tulos = tulos * luku;
        x++;
    }    
    return tulos;
}