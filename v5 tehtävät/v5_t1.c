#include <stdio.h>
int side();

int main(int argc, char *argv[]) {
    int square, i, number;

    if (argc == 2) {
        number = atoi(argv[1]);
    	square = side(number);
    	printf("Luku on %d.\n", number);
    	printf("Luvun neliö on %d.\n", square);
    } 
	
	else {
    printf("Et antanut lukua!\n");
    }
    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}

int side(number) {
    int square;
    square = number * number;
    return square;
}