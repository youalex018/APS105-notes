#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
    double score;
    struct node* next;
} Node;

typedef struct linkedlist {
    Node* head;
} LinkedList;

double findLargestIterative(LinkedList *list);
double findLargestRecursive(Node* current);

int main() {
    LinkedList scores;
    
    Node* s1 = (Node*)malloc(sizeof(Node));
    Node* s2 = (Node*)malloc(sizeof(Node));
    Node* s3 = (Node*)malloc(sizeof(Node));
    Node* s4 = (Node*)malloc(sizeof(Node));
    
    scores.head = (Node*)malloc(sizeof(Node));
    scores.head = s1;
    
    s1->score = 4.2;
    s1->next = s2;
    s2->score = 5.8;
    s2->next = s3;
    s3->score = 8.6;
    s3->next = s4;
    s4->score = 3.1;
    s4->next = NULL;
    
    printf("%lf\n", s3->score);
    printf("Largest score: %lf\n", findLargestIterative(&scores));
    printf("Largest score: %lf\n", findLargestRecursive(s1));

    free(s1);
    free(s2);
    free(s3);
    free(s4);
    free(scores.head);
    return 0;
}

double findLargestIterative(LinkedList *list) {
    Node* current = list->head;
    if (current == NULL) {
        return -1;
    }
    double largest = current->score;
    while (current != NULL) {
        if (current->score > largest) {
            largest = current->score;
        }
        current = current->next;
    }
    return largest;
}

double findLargestRecursive(Node* current) {
    if (current == NULL) {
        return -1;
    }
    if (current->next == NULL) {
        return current->score;
    }
    return fmax(findLargestRecursive(current->next), current->score);
}