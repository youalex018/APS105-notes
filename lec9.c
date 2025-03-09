/*
-Control Flow P4-

Two ways to write an infinite loop:
1. while loop
2. for loop

For loops
General structure:
for (expr1; expr2; expr3) {
    //statements
}
- expr1 is executed once before the loop
- expr2 is the condition for execution of the loop
- expr3 is executed in each iteration of the loop, after the statements
- continue skips the remainder of the statements and goes to next iteration
- break exits the loop
*/

#include <stdio.h>

int main (void) {
    // for loop example
    int a = 0;
    for (; a < 10; ++a) {
        printf("%d\n", a);
    }

    return 0;
}
