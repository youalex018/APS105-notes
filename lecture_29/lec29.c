/*
-Linked Lists-
- Linear data structure where elements (nodes) are linked using pointers
- The head is the first node, if the list is empty the head is NULL

Advantages:
- Is dynamic in size, no need to pre-allocate memory
- Efficient insertion and deletion of elements

Disadvantages:
- High memory usage and slower access time compared to arrays
- Cannot directly access elements by index, must traverse the list through pointers

Basic Syntax:

struct node {
    int data;
    struct node *next;
}

typedef Example:

typedef struct node {
    int data;
    struct node *next;
} Node;

*/

#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Need a pointer to a pointer to change the head
void insertFront(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    *head = newNode;
}

void insertBack(Node* head, int data) {
    Node* newNode = createNode(data);
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}