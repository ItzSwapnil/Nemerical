//
// Inverse of a matrix
//

#include <stdio.h>

void displayMatrix(int n, float A[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", A[i][j]);
        }
        printf("\n");
    }
}

void swapRows(int n, float A[n][n], int row1, int row2) {
    for (int i = 0; i < n; i++) {
        float temp = A[row1][i];
        A[row1][i] = A[row2][i];
        A[row2][i] = temp;
    }
}

void makeDiagonalOne(int n, float A[n][n], float inv[n][n], int row, float factor) {
    for (int j = 0; j < n; j++) {
        A[row][j] /= factor;
        inv[row][j] /= factor;
    }
}

void makeElementsBelowZero(int n, float A[n][n], float inv[n][n], int row, int col) {
    float factor = A[col][col];
    for (int i = 0; i < n; i++) {
        if (i != col) {
            float mult = A[i][col] / factor;
            for (int j = 0; j < n; j++) {
                A[i][j] -= mult * A[col][j];
                inv[i][j] -= mult * inv[col][j];
            }
        }
    }
}

void inverseMatrix(int n, float A[n][n], float inv[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                inv[i][j] = 1;
            else
                inv[i][j] = 0;
        }
    }

    for (int col = 0; col < n; col++) {
        if (A[col][col] == 0) {
            printf("Inverse does not exist.\n");
            return;
        }
        makeDiagonalOne(n, A, inv, col, A[col][col]);
        for (int row = 0; row < n; row++) {
            if (row != col) {
                makeElementsBelowZero(n, A, inv, row, col);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    float A[n][n], inv[n][n];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    inverseMatrix(n, A, inv);

    printf("Inverse of the matrix:\n");
    displayMatrix(n, inv);

    return 0;
}

/*
        Output:
Enter the size of the square matrix:2

Enter the elements of the matrix:
1 2
3 4

Inverse of the matrix:
-2.00 1.00
1.50 -0.50

*/

