/*
-Scope-

In C, refers to the specific region or block within a program where a variable is declared, defined, and can be accessed. 
Outside of this designated area, the variable is not recognized and cannot be used.
Block scope is a variable defined within braces {}, cannot be accessed outside of it

int b = 1;
{
    int b = 0;
}
b value is re-assigned, new variable

Global variables - can be used within any block scope

Addresses - &
- we can find a variable's address within the memory

Pointers - points to a location in the memory
int* x = NULL;

*x = qpweqowe
*/

#include <stdio.h>

static int globalVariable = 100;

void function1() {
    printf("%d", globalVariable);
}

int main(void) {
    function1();

    return 0;
}
