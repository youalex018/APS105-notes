#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct point {
    int z;
    int y;
    int x;
} Point;

typedef struct student {
    char* lastName;
} Student;

typedef struct node {
    int data; 
    struct node* next;
} Node;

typedef struct linkedList {
    Node* head;
    Node* tail;
} LinkedList;

void removeTail(LinkedList *list) {
    Node* current = list->head;
    Node* prev = NULL;
    if (list->head == NULL) {
        return;
    }
    
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    if (current == list->head) {
        list->head = NULL;
    } else {
        prev->next = NULL;
    }
    free(current);
}

bool isCycle(LinkedList *list) {
    if (list->head == NULL || list->head->next == NULL) {
        return false;
    }
    Node* current = list->head;
    while (current->next != NULL) {
        if (current->next == list->head) {
            return true;
        }
    }
    return false;
}

void removeVal(LinkedList *list, int value) {
    if (list->head == NULL) {
        return;
    }
    Node* prev = NULL;
    Node* current = list->head;
    while (current->next != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            
            if (current == list->tail) {
                list->tail = prev;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

bool isMagicSquare(int n, int square[][n]) {
    int sum = 0;
    int sumBottomDiag = 0;
    for (int i = 0; i < n; ++i) {
        sum += square[i][i];
        sumBottomDiag += square[i][n-1-i];
    }
    if (sum != sumBottomDiag) {
        return false;
    }
    for (int i = 0; i < n; ++i) {
        int sumRow = 0;
        int sumCol = 0;
        for (int j = 0; j < n; ++j) {
            sumRow += square[i][j];
            sumCol += square[j][i];
        }
        if (sumRow != sum || sumCol != sum) {
            return false;
        }
    }
    return true;
}

void recurCount(int num) {
    if (num == 0) {
        return;
    }
    printf("Count Down: %d\n", num);
    recurCount(num - 1);
    if (num % 2 == 0) {
        printf("Count Up: %d\n", num/2);
    }
}

typedef struct database {
    int* arr;   
    int length;
    int size;
} Database;

void addElement(Database* x, int num) {
    int ogSize = x->size;
    int* newArr = NULL;
    if (x->length == ogSize) {
        x->size *= 2;
        newArr = (int*)malloc(x->size*sizeof(int));
        for (int i = 0; i < ogSize; i++) {
            newArr[i] = x->arr[i];
        }
        free(x->arr);
        x->arr = newArr;
    }
    newArr[x->length] = num;
    x->length++;
}

void getNames(Student students[]) {
    char str[20];
    for (int i = 0; i < 2; i++) {
        printf("Enter last name: ");
        scanf("%s", str);
        //(a) Correct the following line in the box
        students[i].lastName = malloc(20*sizeof(char));
        strcpy(students[i].lastName, str);
    }
}

char* removeStrDuplicates(char* str, char* search) {
    while (strstr(str, search) != NULL) {
        int indFound = strstr(str, search) - str;
        int i = 0;
        while (str[indFound + i + strlen(search)] != '\0') {
            str[indFound + i] = str[indFound + i + strlen(search)];
            i++;
        }
        str[indFound + i + strlen(search)] = '\0';
    }
    return str;
}

int main() {
    // int arr[100] = {1, 3, 10};
    // Point p1 = {3, 2, 1};
    
    // Student* students = (Student*)malloc(2 * sizeof(Student));
    // getNames(students);
    // for (int i = 0; i < 2; i++) {
    //     printf("%s\n", students[i].lastName);
    // }
    // // (b) Deallocate dynamically allocated memory in the box
    // for (int i = 0; i < 2; i++) {
    //     free(students[i].lastName);
    // }
    // free(students);
    // students = NULL;
    
    recurCount(5);
    
    printf("%s\n", removeStrDuplicates("This is an apple", "is"));
    
    return 0;
}