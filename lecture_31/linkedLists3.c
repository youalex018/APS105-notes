/*
What are some of the problems that can be solved using linked lists?
1. Implementing stacks and queues
2. Implementing hash tables
3. Implementing adjacency lists for graphs
4. Implementing sparse matrices
5. Implementing undo/redo functionality in applications
6. Implementing memory management systems
7. Implementing file systems
8. Implementing text editors
9. Implementing image processing algorithms

Common edge cases in linked lists:
1. Empty list: The list is empty, and operations like insertion, deletion, or traversal need to handle this case.
2. Single node: The list contains only one node, and operations like deletion or reversal need to handle this case.
3. Head and tail pointers: The list has head and tail pointers, and operations need to update these pointers correctly.
4. Circular linked list: The list is circular, and operations need to handle the circular nature correctly.
5. Duplicate values: The list may contain duplicate values
6. Memory allocation failures: Memory allocation for new nodes may fail
7. Null pointers: Pointers to nodes may be null
8. Deletion of the last node: Deleting the last node in a list needs to update the tail pointer correctly.
*/

// In class linked list examples

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

void reverseList(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // Base case: empty list or single node
    }

    Node* rest = (*head)->next;
    reverseList(&rest); // Recursively reverse the rest of the list

    (*head)->next->next = *head; // Make the next node point to the current head
    (*head)->next = NULL; // Set the current node's next to NULL

    *head = rest; // Update the head to the new first node
}

Node* findMiddle(Node* head) {
    if (head == NULL) {
        return NULL; // Handle empty list case
    }

    Node* slow = head;
    Node* fast = head;

    // Move fast pointer two steps and slow pointer one step
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // Returns middle node
}

void freeListRecursive(Node* head) {
    if (head == NULL) {
        return; // Handle empty list case
    }
    freeListRecursive(head->next); // Recursively free the next node
    free(head); // Free the current node
}