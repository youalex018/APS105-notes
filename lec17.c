/*
-Midterm Prep & passing arrays to functions-

This assigns i to 6 and returns the value of i in the if statement
The value is not 0, so j does not become 17
if (i = 6) j = 17;




*/

#include <stdio.h>

void orderArrayByDigit2(int[]);
void pythagoreanTriples(int);

void orderArrayByDigit2(int array[]) {
    int sortedArray[6] = {};
    int n = 0;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j < 6; j++) {
            int secondDigit = (array[j]/10)%10;
            if (secondDigit == i) {
                sortedArray[n] = array[j];
                n++;
            }
        }
    }
    printf("%d", sortedArray[0]);
    for (int i = 0; i < 6; i++) {
        printf("%d", sortedArray[i]);
    }
    printf("%d\n", sortedArray[5]);
}

void pythagoreanTriples(int x) {
    for (int y = 1; y < 100; y++) {
        for (int z = y + 1; z < x*x + y*y; z++) {
            if (z*z == x*x + y*y) {
                printf("");
                return;
            }
        }
    }
    printf("");
}

int main(void) {

    int a[] = {123, 512, 676, 215, 92, 382}; 
    orderArrayByDigit2(a);

    // print the value of e approximated to 0.001
    const double TOLERANCE = 0.001;
    double sum = 0.0;
    double term = 1;
    int n = 0;
    
    while (term > TOLERANCE) {
        n++;
        sum += term;
        term /= n;
    }
    printf("Sum: %lf", sum);
    printf("Term: %lf", term);
    
    return 0;
}
