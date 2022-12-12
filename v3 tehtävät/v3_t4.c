#include <stdio.h>

int stringLenght(char *);
char* copyString(char *, char *, int);

int main() {
    char string1[100], string2[100];
    char *ptr;
    int lenght;

    printf("Anna kopioitava merkkijono: ");
    //gets(string1);
    scanf("%[^\n]%*c", string1);

    ptr = string1;
    lenght = stringLenght(ptr);

    copyString(string2, string1, lenght);
  
    printf("Merkkijono 1 on '%s'.\n", string1);
    printf("Merkkijono 2 on '%s'.\n", string2);
    printf("Kiitos ohjelman käytöstä.\n");  
    return 0;
}

int stringLenght(char ptr[]) {
    int i;

    while (*ptr != '\0') {
        ptr++;
        i++;
    }

    return i;
}

char* copyString(char string2[], char string1[], int length) {
    char i;

    //Kopioidaan merkkijonosta kirjain kerrallaan kunnes vastaan tulee loppumerkki
    for (i = 0; i < length; ++i) {
        string2[i] = string1[i];
    }

    //Lisätään loppumerkki merkkijonoon 2
    string2[i] = '\0';

    return string2;
}