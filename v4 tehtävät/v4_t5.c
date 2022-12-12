#include<stdio.h>

rekursio(int n);

int main () {
    int n, Fluku;

    printf ("Anna luku, jolle lasketaan Fibonaccin luku: ");
    scanf ("%d", &n);
    Fluku = rekursio(n);
    printf ("Luvun %d Fibonaccin luku on %d.\n", n, Fluku);
	printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}

rekursio(int n) {

    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return (rekursio(n - 1) + rekursio(n - 2));
    }
}