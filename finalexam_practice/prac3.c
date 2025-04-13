#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct racer {
    char* firstName;
    char* lastName;
    int bib;
    int finishTime;
} Racer;

Racer* createRacer(char firstName[], char lastName[], int bib, int finishTime) {
    Racer* newRacer = (Racer*)malloc(sizeof(Racer));
    if (newRacer != NULL) {
        newRacer->firstName = (char*)malloc(strlen(firstName) + 1);
        newRacer->lastName = (char*)malloc(strlen(lastName) + 1);
        
        strncpy(newRacer->firstName, firstName, strlen(firstName) + 1);
        newRacer->firstName[strlen(firstName)] = '\0';
        strncpy(newRacer->lastName, lastName, strlen(lastName) + 1);
        newRacer->lastName[strlen(lastName)] = '\0';
        newRacer->bib = bib;
        newRacer->finishTime = finishTime;
    }
    return newRacer;
}

void destroyRacer(Racer* racer) {
    if (racer != NULL) {
        free(racer->firstName);
        free(racer->lastName);
        free(racer);
    }
}

int addToRacerList(Racer *racer, Racer *racerList[], int n) {
    for (int i = 0; i < n; i++) {
        if (racerList[i] == NULL) {
            racerList[i] = racer;
            return i;
        }
    }
    return -1;
}

char *duplicateString(const char s[], int n, char separator) {
    int len = strlen(s);
    int newSize = len * n + n;
    char *newString = malloc(sizeof(char)*newSize);
    newString[0] = '\0';
    for (int i = 1; i <= n; i++) {
        strncat(newString, s, len);
        newString[((len + 1)*i) - 1] = separator;
    }
    newString[newSize - 1] = '\0';
    return newString;
}

int main(void) {
    int size = 5;
    Racer *racerList[size];
    for (int i = 0; i < size; i++) {
        racerList[i] = NULL;
    }
    Racer* homer = createRacer("Homer", "Simpson", 742, 239);
    Racer* hi = createRacer("Hello", "World", 1, 2);
    printf("Name: %s %s\n", homer->firstName, homer->lastName);
    addToRacerList(hi, racerList, size);
    int index = addToRacerList(homer, racerList, size);
    printf("%d\n", index);
    if (index - 1 >= 0 && racerList[index - 1] != NULL) {
        destroyRacer(racerList[index - 1]);
    }

    char* string = duplicateString("Hi", 3, '*');
    printf("%s\n", string);
    
    free(string);

    return 0;
}