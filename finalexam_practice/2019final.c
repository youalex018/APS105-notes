#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

const double D2R = 3.1415926535 / 180.0;
// rectangular coordinate structure
typedef struct rectV {
    int x;
    int y;
} RectCoor;
// polar coordinate structure
typedef struct polarC { // angle in radians
    int r;
    int theta;
} PolarCoor;
// polar to rectangular
RectCoor polToRec (PolarCoor polin) {
    RectCoor rv;
    rv.x = polin.r*cos(polin.theta*D2R);
    rv.y = polin.r*sin(polin.theta*D2R);
    return rv;
}

int factorial(int n) { // returns n!
    if (n == 0) return 1;
    int result = n;
    for (int i = 1; i < n; i++) {
        result*=i;
    }

    return result;
}

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct linkedList {
    Node *head;
} LinkedList;

void bubbleSortLinkedList(LinkedList* list) {
    Node* current = list->head;
    int size = 0;
    while (current != NULL && current->next != NULL) {
        if (current->data > current->next->data) {
            int temp = current->data;
            current->data = current->next->data;
            current->next->data = temp;
        }
        size++;
    }
    for (int i = 0; i < size - i; i++) {
        while (current->next != NULL) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }  
        }
    }
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permutateHelper(char *str, int low, int high) {
    if (low == high) {
        printf("%s\n", str);
    }
    else {
        for (int i = low; i <= high; i++) {
            swap(str + low, str + i);
            permutateHelper(str, low + 1, high);
            swap(str + low, str + i);
        }
    }
}

void permutate(char *str) {
    permutateHelper(str, 0, strlen(str) - 1);
}

char *alignText(char *inStrings[], int lineLength){
    char *outString; //assemble the string here
    int charcount = 0; //counts number of characters
    
    int index = 0;
    while (strcmp(inStrings[index], ".") != 0) {
        charcount += strlen(inStrings[index++]);
    }
    
    int buffer = charcount / lineLength + 4;
    outString = (char*)malloc(charcount*sizeof(char) + buffer);
    
    index = 0;
    charcount = 0;
    
    outString[0] = 0;
    do {
        if (charcount + strlen(inStrings[index]) > lineLength) {
            strcat(outString, "\n");
            charcount = 0;
        }
        strcat(outString, inStrings[index]);
        charcount += strlen(inStrings[index]);
    } while (strcmp(inStrings[index++], ".") != 0);
    strcat(outString, "\n");
    return outString;
}



int main(void) {
    int const RowDesired = 8; //counts from 1
    int pascalRow[8]; //hint: row #n has n+1 elements
    for (int r = 0; r < RowDesired; r++) {
        pascalRow[r] = factorial(RowDesired - 1) / (factorial(r) * factorial(RowDesired - 1 - r));
        printf("%d ", pascalRow[r]);
    }
    printf("\n");
    
    LinkedList list;
    Node* n1 = (Node*)malloc(sizeof(Node));
    Node* n2 = (Node*)malloc(sizeof(Node));
    Node* n3 = (Node*)malloc(sizeof(Node));
    Node* n4 = (Node*)malloc(sizeof(Node));
    
    n1->data = 4;
    n1->next = n2;
    n2->data = 2;
    n2->next = n3;
    n3->data = 5;
    n3->next = n4;
    n4->data = 3;
    n4->next = NULL;
    list.head=  n1;

    //bubbleSortLinkedList(&list);
    printf("%d\n", n1->data);
    printf("%d\n", n2->data);
    printf("%d\n", n3->data);
    printf("%d\n", n4->data);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    
    char str[] = "abc";
    
    char* arr[] = {"This", " is", " my", " example", " for", " the", " exam", " question", "."};
    printf("%s\n", alignText(arr, 15));

    return 0;
}