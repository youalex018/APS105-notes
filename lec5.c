/*
-Math-

Comments - make code more readable and explains it
- single-line (//) vs multi-line

Function prototype - a statement that tells the compiler about the function's:
- name, return type, data types of its paramenters
void greet(void) - prints a greeting message
int add(int a, int b)
int multiply(int, int)
void printNumber(int num) - prints an integer
float multiplyFloat(float x, float y)

double fmin(double x, double y)
double fmax(double x, double y)

rint - round to nearest even int
round - round to nearest int
rand - returns random integer

Preprocessor directive - command that begins with #
- instruct the compiler on how to process the program
- can be used to define constants and include files

Header files - files that end in .h
- contain function prototypes
- system defined (<>) vs. user defined ("")
*/

#include <stdio.h> // includes the standard input/output library
#include <math.h> // math library
#include <stdlib.h> // for rand and srand
#include <time.h>

// define constants using #define
#define PI 3.14159
#define GREETING "Hello World!"

int main(void) {
    double num, num2;
    int random;

    printf("%lf\n", PI);
    num = sqrt(PI);
    num2 = pow(num, 2);
    printf("%lf %lf", num, num2);

    srand(time(NULL));
    random = rand();
    printf("%d", random);

    return 0;
}
