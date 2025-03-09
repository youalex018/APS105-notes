/*
-Strings Part I-


*/

// In lecture demo

#include <stdio.h>
#include <stdbool.h>

int borderSum(int n, int mat[][26]) {
    if (n == 0) return 0;
    if (n == 1) return mat[0][0];
    
}

int diagonalSum(int n, int square[][n]) {
    int diagSum1 = 0;
    int diagSum2 = 0;
    for (int i = 0; i < n; i++) {
        diagSum1 += square[i][i];
        diagSum2 += square[i][n-i-1];
    }
    return diagSum1 + diagSum2;
}

bool isMagicSquare(int n, int a[][n]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[0][i];
    }

    for (int i = 0; i < n; i++) {
        int newsum = 0;
        for (int j = 0; j = n; j++) {
            newsum += a[i][j];
        }
        if (sum != newsum) {
            return false;
        }
    }

    int newsum2 = 0;
    int newsum3 = 0;

    for (int i = 0; i < n; i++) {
        int newsum = 0;
        for (int j = 0; j < n; j++) {
            newsum += a[j][i];
            newsum2 += a[i][i];
            newsum3 += a[i][n-i-1];
        }
        if (sum != newsum) {
            return false;
        }
    }
    if (sum != newsum2 || sum != newsum3) {
        return false;
    }

}