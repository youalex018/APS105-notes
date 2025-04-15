#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *link;
} Node;

Node *search(Node *head, int key) {
    Node *current = head;
    // insert your code in the line below between the parentheses
    while (current != NULL && current->data != key) {
        current = current -> link;
    }
    return current;
}

int stringLength(char *str) {
    if (str == NULL || *str == '\0') return 0;
    return 1 + stringLength(str + 1);
}

char *preamble(char *str, int n) {
    char* newStr = (char*)malloc((n + 1)*sizeof(char));
    for (int i = 0; i < n; i++) {
        if (i < strlen(str)) {
            newStr[i] = str[i];
        } else {
            newStr[i] = '\0';
        }
    }
    return newStr;
}

const double E = 2.718281828459045;  // Provided constant

// Helper function: read the first 16 digits (ignoring decimal point) into a string
void getFirst16DigitsOfE(char digits[17]) {
    // Use sprintf to convert E to a string with enough precision
    // e.g., up to 20 digits after decimal
    char buffer[32];
    sprintf(buffer, "%.20f", E);

    // buffer will look like "2.7182818284590450000" (approx)
    // we want to copy the first 16 digits ignoring the decimal point

    int idx = 0;       // for buffer
    int digitCount = 0; 
    while (buffer[idx] != '\0' && digitCount < 16) {
        if (buffer[idx] != '.') {
            digits[digitCount++] = buffer[idx];
        }
        idx++;
    }

    // Null-terminate
    digits[16] = '\0';
}

// Returns the first two-digit number in the first 16 digits of E
// whose mirror has already appeared, or 0 if not found.
int firstMirrorInE(void) {
    // 1) Extract first 16 digits of E into a string
    char first16[17];
    getFirst16DigitsOfE(first16); // e.g. "2718281828459045"

    // 2) Check each pair from left to right
    // We'll have 15 pairs of consecutive digits in a 16-digit string
    for (int i = 0; i < 15; i++) {
        // Extract the pair: e.g. digits i and i+1
        char d1 = first16[i];
        char d2 = first16[i + 1];

        // Mirror is d2 d1
        // We'll check if that mirrored pair appears in the substring first16[0 .. i-1]
        // Because we only care if it appeared earlier, i.e. to the left

        // Build a short string for the mirrored 2-digit
        char mirror[3];
        mirror[0] = d2;
        mirror[1] = d1;
        mirror[2] = '\0'; // null-terminate

        // Search earlier pairs 0 .. i-1
        for (int j = 0; j < i; j++) {
            // Compare pair at positions j, j+1
            if (first16[j] == mirror[0] && first16[j + 1] == mirror[1]) {
                // Found the mirror earlier
                // Convert the original pair d1 d2 to an integer
                // e.g. if d1='2' and d2='8', the integer is 28
                int tens = (d1 - '0') * 10;
                int ones = (d2 - '0');
                return (tens + ones);
            }
        }
    }

    // Not found any that satisfies the condition
    return 0;
}

void printDuplicates(Node *head) {
    Node* current = head;
    if (current == NULL || current->link == NULL) return;
    
    while (current != NULL) {
        int currVal = current->data;
        current = current->link;
    
        while (current != NULL) {
            if (current->data == currVal) {
                printf("%d\n", currVal);
                break;
            }
            current = current->link;
        }
    }
}

int recursiveFindIndex(char *string, char c) {
    if (*string == '\0') {
        return -1;
    } else if (*string == c) {
        return 0;
    } else {
        int result = recursiveFindIndex(string + 1, c);
        return (result == -1) ? -1 : (1 + result);    
    }
}

void sortOddEven(int input[], int size) {
    for (int j = 0; j < size; j++) {
        for (int i = j; i < size; i++) {
            if (input[i] % 2 == 0 && i + 1 < size && input[i + 1] % 2 == 1) {
                int temp = input[i];
                input[i] = input[i + 1];
                input[i + 1] = temp;
            }
        }
    }
}

int main() {
    int randomChoice = 2*(rand() % 150) - 150;
    printf("%d\n", randomChoice);
    
    //char c = *(employees[1].lastName[0]);
    
    int* intPtrArray = (int*)malloc(10*sizeof(int*));
    free(intPtrArray);
    
    printf("%d\n", stringLength("HELLO"));
    
    printf("%d\n", '\0' == 0);
    char *newStr = preamble("Toronto", 6);
    printf("%s\n", newStr);
    free(newStr);
    
    printf("%d\n", recursiveFindIndex("helloworld", 'o'));
    
    int size = 8;
    int arr[] = {1, 4, 6, 5, 9, 3, 8, 2};
    sortOddEven(arr, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}