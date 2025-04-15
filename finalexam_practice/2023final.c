#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct plant {
    char name[30];
    double height;
} Plant;

typedef struct student {
    char* lastName;
} Student;
    
void getNames(char* lastName, Student students[]) {
    for (int i = 0; i < 4; i++) {
        printf("Enter last name: ");
        scanf("%s", lastName);
        students[i].lastName = (char*)malloc(strlen(lastName)*sizeof(char));
        strcpy(students[i].lastName, lastName);
    }
}

struct element {
    double resistance;
    double reactance;
    double voltage;
    struct Node *next;
};

double calculateMagnitude (double resistance, double reactance) {
    return sqrt(pow(resistance, 2) + pow(reactance, 2));
}

double equivalentMagnitude (struct element *ptr, int n) {
    if (ptr == NULL) {
        return 0.0;
    }
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += calculateMagnitude(ptr->resistance, ptr->reactance);
    }
}

int diagonalsSum(int n, int square[][n]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += square[i][j];
            sum += square[n-1-i][j];
        }
    }
}

void printReverse() {
    int num;
    printf("Enter num: ");
    scanf("%d", &num);
    if (num == 0) {
        printf("Reversed sequence: %d", num);
        return;
    }
    
    printReverse();
    printf(" %d", num);
    
}

char* removeSpecialChars(char* str) {
    int index2 = 0;
    for (int index = 0; index < strlen(str); index++) {
        if (str[index] < 'a' || str[index] > 'z') {
            continue;
        }
        str[index2] = str[index];
        index2++;
    }
    
    str[index2] = '\0';
    return str;
}

int numOccurrences(const char *str, const char *search) {
    if (strlen(str) < strlen(search)) {
        return 0;
    }
    if (strncmp(str, search, strlen(search))) {
        return 1 + numOccurences(str + 1, search);
    }
    return numOccurences(str + 1, search);
}

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct linkedList {
    Node *head;
} LinkedList;

void insertSequence(LinkedList *list, LinkedList* sequence) {
    if (sequence->head == NULL) {
        return;
    }
    if (list->head == NULL) {
        list->head = sequence->head;
        return;
    }
    
    Node* currList = list->head;
    Node* currSeq = sequence->head;
    Node* prevList = NULL;
    
    // Traverse until either list or sequence is used up
    while (currList != NULL && currSeq != NULL) {
        // If the next seq node belongs before currList
        if (currSeq->data < currList->data) {
            // Insert the seq node(s) here
            if (prevList == NULL) {
                // Insert at front
                list->head = currSeq;
            } else {
                prevList->next = currSeq;
            }

            // Move forward in seq while seq->data < currList->data
            // so we can insert consecutive missing nodes
            Node* lastInserted = NULL;
            while (currSeq != NULL && currSeq->data < currList->data) {
                lastInserted = currSeq;
                currSeq = currSeq->next;
            }
            // Link last inserted node to the current list node
            lastInserted->next = currList;
        }

        // Move forward in the main list
        prevList = currList;
        currList = currList->next;
    }

    // If seq has leftover nodes, attach them at the end
    if (currSeq != NULL) {
        // link remainder of seq
        if (prevList == NULL) {
            // Means list was empty, but we handled that earlier, so likely not needed
            list->head = currSeq;
        } else {
            prevList->next = currSeq;
        }
    }
}

int main() {
    // char randomCharacter = (char)(rand() % 27 + 'A');
    // printf("%c\n", randomCharacter);
    
    // int numbers[500] = {1, 2, 3, 4};
    // printf("%d\n", numbers[4]);
    
    //Plant plant1 = {"Cactus", 5.3}, plant2 = {"Rose", 10.2};

    // Student students[4];
    // char lastName[1024];
    // getNames(lastName, students);
    // for (int i = 0; i < 4; i++) {
    //     printf("students[%d].lastName = %s\n", i, students[i].lastName);
    // }
    
    // printReverse();
    
    char str[30] = "a&pp*(leisa(fr*$uit";
    printf("str with special characters: %s\n", removeSpecialChars(str));
    
    return 0;
}