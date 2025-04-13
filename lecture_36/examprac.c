#include <stdio.h>

// Question 9
void recurCount(int num) {
    if (num == 0) {
        return; // Base case: stop recursion when num is 0
    }

    printf("Count Down: %d\n", num); // Print the current number
    recurCount(num - 1); // Recursive call with num - 1
    if (num % 2 == 0) {
        printf("Count Up: %d\n", num / 2);
    }
}


// Question 12
typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct linkedlist {
    Node* head;
    Node* tail;
} LinkedList;

void removeVal(LinkedList *list, int value) {
    Node* current = list->head;
    Node* prev = NULL;
    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                list->head = current->next; // Update head if removing the first node
            } else {
                prev->next = current->next;
            }
            
            if (current == list->tail) {
                list->tail = prev; // Update tail if removing the last node
            }
            // free(current); // Should be uncommented in the real solution
            return;
        }
        prev = current;
        current = current->next;
    }
}

void printList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    printf("Head: %d, Tail: %d\n", list->head->data, list->tail->data);
}

// Question 14
void mergeLines(char* merged, char* lineOne, char* lineTwo) {
    /* Base Case */
    if (*lineOne == '\0' && *lineTwo == '\0') {
        *merged = '\0'; // End of both strings
        return;
    }
    /* Recursive step */
    if (*lineOne == '\0') {
        *merged = *lineTwo; // If lineOne is empty, copy lineTwo
        mergeLines(merged + 1, lineOne, lineTwo + 1);
        return;
    } else if (*lineTwo == '\0') {
        *merged = *lineOne; // If lineTwo is empty, copy lineOne
        mergeLines(merged + 1, lineOne + 1, lineTwo);
        return;
    } else if (*lineOne < *lineTwo) {
        *merged = *lineOne;
        mergeLines(merged + 1, lineOne + 1, lineTwo);
    } else {
        *merged = *lineTwo;
        mergeLines(merged + 1, lineOne, lineTwo + 1);
    }
}

// 2025 Winter Midterm Question 24
void printPairs(int arr[], int size, int target) {
    for (int left = 0; left < size; left++) {
        for (int right = left + 1; right < size; right++) {
            int sum = arr[left] + arr[right];
            if (sum == target) {
                printf("(%d, %d)\n", arr[left], arr[right]);
                // skip duplicates after that
                while (left + 1 < size && arr[left] == arr[left + 1]) {
                    left++;
                }
  
                while (right + 1 < size && arr[right] == arr[right + 1]) {
                    right++;
                }
            }
        }
    }
}

int main(void) {
    // Question 9
    recurCount(5);

    // Question 12
    LinkedList list = {NULL, NULL};
    Node n1 = {3, NULL};
    Node n2 = {5, NULL};
    Node n3 = {7, NULL};
    Node n4 = {9, NULL};
    list.head = &n1;
    list.tail = &n4;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    printList(&list);
    removeVal(&list, 5);
    printList(&list);

    // Question 14
    char lineOne[] = "ALZ";
    char lineTwo[] = "CPQ";
    char merged[128];
    printf("lineOne: %s\n", lineOne);
    printf("lineTwo: %s\n", lineTwo);
    mergeLines(merged, lineOne, lineTwo);
    printf("Merged: %s\n", merged);

    // Question 24
    int arr[] = {2, 2, 3, 4, 4, 5, 5};
    int size = 7;
    int target = 7;
    printPairs(arr, size, target);

    return 0;
}