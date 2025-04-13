/*
-Strings Part III-

Revisiting main:
Main function signature that allows command-line arguments:
int main(int argc, char *argv[])

- argc (argument count) is the number of commandline arguments passed to the program
- includes the program name itself
- argv (argument vector) is an array of strings each storing one command-line argument
- argv[0] is the program's name, following elements contain additional arguments

*/

// In class example - Problem solving with strings

#include <stdio.h>
#include <string.h>

// Question 7
void printNum(char *str) {
    int i = 0;

    while (str[i] == '0') {
        i++;
    }

    if (i == 0 || str[i] == '\0') {
        printf("0\n");
        return;
    }

    str = str + i;

    printf("%s", str);
}

char* lastStringInString(char* str1, char* str2) {
    int lengthstr1 = strlen(str1);
    int lengthstr2 = strlen(str2);
    char* result = NULL;

    for (int i = 0; i < lengthstr1 - lengthstr2; i++) {
        if (strncmp(&str1[i], str2, lengthstr2) == 0) {
            result = &str1[i];
        }
    }
    return result;
}

char* removeSpecialChars(char* str) {
    int read = 0;
    int write = 0;
    int length = strlen(str);
    for (read = 0; read < length; read++) {
        char temp = str[read];
        if (temp <= 'z' && temp >= 'a') {
            str[write] = str[read];
            write++;
        }
    }

    str[write] = '\0';
    return str;
}

char* removeStringDuplicates(char* str, char* search) {
    int l1 = strlen(str);
    int l2 = strlen(search);

    char* result = str;

    for (int i = 0; i < l1 - l2; i++) {
        if (strncmp(&str[i], search, l2) == 0) {
            str[i] = ' ';
        }
    }

    return result;
}

int main(void) {
    // printf("%s\n", lastStringInString("Averylor avery lor", "lor"));

    char s[10] = "000089876";
    printNum(s);
    return 0;
}