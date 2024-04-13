//
// Transpose of a matrix
//
#include <stdio.h>

void transposeMatrix(int m, int n, int A[m][n], int B[n][m]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            B[j][i] = A[i][j];
        }
    }
}

int main() {
    int m, n;
    printf("Enter the number of rows and columns for the matrix: ");
    scanf("%d %d", &m, &n);

    int A[m][n], B[n][m];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    transposeMatrix(m, n, A, B);

    printf("Transpose of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
            Output:
Enter the number of rows and columns for the matrix:2 2

Enter the elements of the matrix:
1 2
3 4

Transpose of the matrix:
1 3
2 4

 */
