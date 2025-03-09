/*
-Control Flow P3-

Programs follow a sequential flow
The while statement is a control flow that is used to execute a block of code repeatedly
This is active as long as a specified condition evaluates to true 

While loops
- while(1) is the same as while(true) (1 means true)
- while(--n) can be used to increment, when it hits 0 it will stop

Increments
n-- stays at n then evaluates after
--n evaluates before so it starts at n-1

Infinite loops
- needs to be manually "killed" or it will run forever
- an example is ctrl + c in the terminal

do while loops
- executes first, then check if the condition is true after
do {
    statements
} while (expression);
*/

#include <stdio.h>

// how many ones are in the binary representation of positive integer n?
int main(void) {
    int n = 50; 
    int howManyOnes = 0;

    while (n) {
        if (n % 2) {
            howManyOnes++;
        }
        n /= 2; 
        // n = n >> 1; // gets rid of last bit (shifts to the right)
    }
    printf("%d\n", howManyOnes);


    // in class example: palindromes
    int num, rev = 0, original;

    printf("Enter a palindrome");
    scanf("%d", &num);
    original = num;

    while (num) {
        rev = rev * 10 + (num % 10);
        num /= 10;
    }
    if (rev == original) {
        printf("it is a palindrome");
    } 
    else {
        printf("it is not a palindrome");
    }
}
