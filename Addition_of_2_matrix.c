//
// Addition of 2 matrix.
//
#include <stdio.h>

void addMatrix(int m, int n, int p, int q, int A[m][n], int B[p][q], int C[m][q]) {
    if (n != q) {
        printf("Error: Number of columns in A and B must be equal to the number of rows in C.\n");
        return;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main() {
    int m, n, p, q;
    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &m, &n);
    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &p, &q);

    if (n != p) {
        printf("Error: Number of columns in A must be equal to the number of rows in B.\n");
        return 1;
    }

    int A[m][n], B[p][q], C[m][q];
    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    addMatrix(m, n, p, q, A, B, C);

    printf("Resultant matrix C:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
            Output:
Enter the number of rows and columns for matrix A:2 2

Enter the number of rows and columns for matrix B:2 2

Enter the elements of matrix A:
1 2
3 4

Enter the elements of matrix B:
5 6
7 8

Resultant matrix C:
6 8
10 12
*/