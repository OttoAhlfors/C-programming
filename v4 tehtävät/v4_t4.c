#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50

typedef struct tunnus {
    int ID;
    char username[MAX];
    char password[MAX];
} TUNNUS;

int main(void) {
    TUNNUS accounts[MAX];
    TUNNUS *pAc = accounts;
    int valinta = -1;
    int i = 0, id = 1;
    //char password, username;

    printf("Käyttäjätunnuksen hallinta.\n");
    while (valinta != 0) {
        printf("Valitse alla olevasta valikosta haluamasi toiminto:\n");
        printf("1) Lisää uusi tunnus\n");
        printf("2) Tulosta tunnukset\n");
        printf("0) Lopeta\n");
        printf("Valintasi: ");
        scanf("%d", &valinta);
        switch (valinta) {
            case 0:
                printf("Lopetetaan\n");
                return 0;
            case 1:
                printf("Anna käyttäjätunnus: ");
                scanf("%s", pAc->username);
                printf("Anna salasana: ");
                scanf("%s", pAc->password);
                pAc->ID = i;
                printf("Tunnus '%s' lisättiin listaan.\n\n", pAc->username);
                i++;
                pAc++;
                break;
            case 2:
                printf("Listalla olevat tunnukset:\n");
                for (i = 0; i < MAX; i++) {
                    printf("%d. tunnus '%s', salasana '%s', ID '%d'.\n", i, accounts[i].username, accounts[i].password, accounts[i].ID);
                }
                i = 0;
                printf(" \n");
                break;
            default:
                printf("Tuntematon valinta.\n\n");
                break;
        }
    }
}