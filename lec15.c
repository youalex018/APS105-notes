/*
-In lecture demo-

Program that finds two prime numbers that can be added up to create an even number (Goldbach Conjecture)
*/

#include <stdio.h>
#include <stdbool.h>

bool goldbachConjecture(int, int*, int*);
int getUserInput(void);
bool isPrime(int);
int nextPrime(int);
void printMessages(bool, int, int);

int main(void) {
    int x = 0;
    x = getUserInput();

    int first, second;
    bool holds = goldbachConjecture(x, &first, &second);
    printMessages(holds, first, second);
}

int getUserInput(void) {
    int x = 0;
    printf("Please enter an even integer greater than two.\n");
    scanf("%d", &x);
    while (x <= 2 || x % 2 == 1) {
        printf("PLEASE enter an even integer greater than two.\n");
    }
    return x;
}

bool isPrime(int x) {
    if (x == 2 || x == 3) {
        return true;
    }
    for (int i = 0; i < x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

// assumption that x is a prime
int nextPrime(int x) {
    x++;
    while (!isPrime(x)) {
        x++;
    }
    return x;
}

bool goldbachConjecture(int x, int* y, int* z) {
    int first, second;
    first = 2;
    second = x - first;

    if (isPrime(second)) {
        *y = first;
        *z = second;
        return true;
    }
    while (first <= second) {
        first = nextPrime(first);
        second = x - first;
        if (isPrime(second)) {
            *y = first;
            *z = second;
            return true;
        }
    }
    *y = first;
    *z = second;
    return false;
}

void printMessages(bool x, int y, int z) {
    if (x) {
        printf("It holds, the two primes are %d %d\n", y, z);
    }
    else {
        printf("naw");
    }
}
