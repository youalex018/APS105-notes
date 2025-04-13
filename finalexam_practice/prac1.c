#include <stdio.h>
#include <stdbool.h>

bool checkPlagiarism(char *code1, char *code2) {
    while (*code1 != '\0' && *code2 != '\0') {
        while (*code1 == ' ' || *code1 == '\n') {
            code1++;
        }
        while (*code2 == ' ' || *code2 == '\n') {
            code2++;
        }
        if (*code1 != *code2) {
            return false; 
        }

        code1++;
        code2++;
    }

    return true;
}

int main(void) {

    char c1[] =
      "int main(void) {\n int x = 10; \n int z = x + 5; \n return 0; \n}\n";
    char c2[] =
      "int main(void) {\n int x=10; \n\n int z=x +5; \n\n\n return 0; \n}\n";
    printf("%d\n", checkPlagiarism(c1, c2));

    return 0;
}