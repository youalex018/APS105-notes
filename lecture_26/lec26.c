/*
-Recursion-

Enumeration data type: "make your own data type"

Example:
typedef enum {
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} DayOfWeek;

*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Count number of times a string appears within another string
int countOc(char* haystack, char* needle) {
    // strstr returns the a pointer to the start of needle within haystack
    char* start = strstr(haystack, needle); 
    // If NULL, there are no occurences of needle in haystack
    if (start == NULL) {
        return 0;
    }

    return 1 + countOc(start + 1, needle);
}

// Swap letters in a string
void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Call swap and increment pointers to reverse letters in a string 
void reverse(char* str, int size) {
    if (size < 2) {
        return;
    }

    swap(str, str + size - 1);
    reverse(str + 1, size - 2);
}

// Recursively check if a word is a palindrome
bool isPal(char* str, int size) {
    // Base case: if the word is empty or one letter it is a palindrome
    if (size < 2) {
        return true;
    }

    if (*str != *(str + size - 1)) {
        return false;
    }

    return isPal(str + 1, size - 2);
}

int main(void) {
    char countoc[] = "yoyo";
    printf("%d\n", countOc(countoc, "yo"));

    // no work 
    char str[] = "hello";
    reverse(str, strlen("hello"));
    printf("%s\n", str);

    bool flag = isPal("ee", strlen("ee"));
    if (flag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}