/*
-Review (2024 midterm)-

// close to 0
#include <stdio.h>
#include <math.h>

double myfn(double input) {
    return sin(input - 3.141 / 4.0);
}

int main(void) {
    double highv = 1.0, lowv = 0.0;
    int iterations = 0;
    double halfway;
    const double Tolerance = .01;

    while (fabs(highv - lowv) > Tolerance) {
        halfway = (highv + lowv)/2;
        //myfn(halfway) > 0 ? highv = halfway : lowv = halfway;
        
        if (myfn(halfway) >= 0.0) {
            highv = halfway;
        } else {
            lowv = halfway;
        }
        iterations++;
    }
    
    printf("%d iterations\n", iterations);
    printf("Input at which myfn is close to zero: %lf", halfway);
}

// dot product
#include <stdio.h>

int dotProduct(int arrA[], int arrB[]) {
    int i = 0, j = 0;
    int sizeA = 0;
    int sizeB = 0;
    int sum = 0;
    
    while (arrA[i] != -1) {
        i++;
        sizeA++;
    }
    
    while (arrB[j] != -1) {
        j++;
        sizeB++;
    }
    
    if (sizeA != sizeB) {
        return -1;
    }
    
    for (int n = 0; n < sizeA; n++) {
        sum += (arrA[n] * arrB[n]);
    }
    return sum;
}

int main(void) {
    int arrA[] = {1, 2, 3, -1};
    int arrB[] = {1, 1, 1, -1};
    
    printf("%d", dotProduct(arrA, arrB));
}

// find 12th barcode digit
int barcodeDigit(int barcode) {
    int even_sum = 0, odd_sum = 0;
    for (int i = 0; i < 11; i+=2) {
        odd_sum += barcode%10;
        barcode /= 10;
        even_sum += barcode%10;
        barcode /= 10;
    }
    int M = (odd_sum*3 + even_sum) %10;
    if (M == 0) {
        return M;
    }
    return 10 - M;
}


// print star formation
#include <stdio.h>

int main() {
    int rows;
    int k = 1;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    
    for (int i = 0; i < rows*2-1; i++) {
        printf("*");
    }
    printf("\n");
    for (int i = 0; i < rows-2; i++) {
        printf("*");
        
        for (int j = rows/2-i; j > 0; j--) {
            printf(" ");
        }
        printf("*");
        
        for (int j = 0; j < i+k; j++) {
            printf(" ");
        }
        k++;
        
        printf("*");
        
        for (int j = rows/2-i; j > 0; j--) {
            printf(" ");
        }
        printf("*\n");
    }
    for (int i = 0; i < rows*2-1; i++) {
        printf("*");
    }
    return 0;
}

*/