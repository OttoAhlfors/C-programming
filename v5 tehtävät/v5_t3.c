#include <stdio.h>
#include <string.h>

struct HENKILO {
    char name[30];
    int age;
    int *memory;
};

int copy();

int main(void) {
    typedef struct HENKILO dude;
    dude person1, person2, person3;
    char *memory_slot = NULL;
    int a;

    printf("Anna ensimmäisen henkilön etunimi: ");
    scanf("%s", person1.name);
    printf("Anna ensimmäisen henkilön ikä: ");
    scanf("%d", &person1.age);
    printf("Anna toisen henkilön etunimi: ");
    scanf("%s", person2.name);
    printf("Anna toisen henkilön ikä: ");
    scanf("%d", &person2.age);

    a = memcmp(person1.name, person2.name, 30);

    if (person1.age == person2.age) {
        printf("Annetut tiedot ovat samoja.\n");
    } else {
        if (a == 0) {
        printf("Annetut tiedot ovat samoja.\n");            
        } else {
            printf("Annetut tiedot eivät ole samoja.\n");
        }
    }

    int ammount_of_memory = (strlen(person1.name)+1) * sizeof(char);
    memory_slot = (char *)malloc(ammount_of_memory);
    strcpy(memory_slot, person1.name);

    if ((memory_slot = (char *)malloc(ammount_of_memory)) == NULL) {
        perror("Muistinvaraus epäonnistui");
        exit(0);
    }
 

    person3 = person1;

    a = memcmp(person1.name, person3.name, 30);

    if (&person1.age == &person3.age) {
        printf("Kopioinnin jälkeen tietueiden tiedot ovat samoja.\n");
    } else {
        if (a == 0) {
        printf("Kopioinnin jälkeen tietueiden tiedot ovat samoja.\n");            
        } else {
            printf("Kopioinnin jälkeen tietueiden tiedot eivät ole samoja.\n");
        }
    }

    if (person1.memory == person3.memory) {
        printf("Kopioinnin jälkeen tietueiden osoitteet eivät ole samoja.\n");
    } else {
        printf("Kopioinnin jälkeen tietueiden osoitteet ovat samoja.\n");
    }

    free(memory_slot);
    printf("Muisti vapautettu.\nKiitos ohjelman käytöstä.\n");
    return 0;
}