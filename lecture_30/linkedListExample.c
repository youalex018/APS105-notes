// Linked List Example

#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct list {
    Node* head;
} linkedList;

// Free all nodes in the linked list
void freeLinkedList(linkedList *ll) {
    Node* current = ll->head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    ll->head = NULL; // Head must be set to NULL
}

// Push to the front of the linked list
void pushfront(linkedList* ll, int data) {
    Node* newNode = createNode(data);
    newNode->next = ll->head;
    ll->head = newNode;
}

// Push to the back of the linked list
void pushback(linkedList *ll, Node *node) {
    // Linked list cannot be NULL and node cannot be NULL
    if (ll == NULL || node == NULL) return;
    node->next = NULL;

    if (ll->head == NULL) {
        ll->head = node;
        return;
    }

    Node* current = ll->head;
    // Loop through linked list to find the last node
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
}

// Push a value to the end of the linked list
Node* pushend(linkedList *ll, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return NULL;
    newNode->data = val;
    newNode->next = NULL;

    if (ll->head == NULL) {
        ll->head = newNode;
    } else {
        Node* current = ll->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return newNode;
}

// Pop the first node of the linked list
Node* popfront(linkedList *ll) {
    if (ll == NULL || ll->head == NULL) return NULL;
    Node* firstNode = ll->head;
    ll->head = ll->head->next;
    firstNode->next = NULL;
    return firstNode;
}

// Find the length of the linked list
int length(linkedList *ll) {
    int count = 0;
    Node* current = ll->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void insertBefore(linkedList *ll, Node *before, Node *node) {
    if (ll == NULL || before == NULL || node == NULL) return;

    // If we insert a node before the head, update the head
    if (ll->head == before) {
        node->next = ll->head;
        ll->head = node;
        return;
    }

    Node* current = ll->head;
    // Loop through to find next node
    while (current != NULL && current->next != before) {
        current = current->next;
    }

    if (current != NULL) {
        node->next = before;
        current->next = node;
    }
}

void insertAfter(Node *after, Node *node) {
    if (after == NULL || node == NULL) return;
    node->next = after->next;
    after->next = node;
}