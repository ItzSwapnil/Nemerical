#include <stdio.h>
#include <math.h>

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}

void forward_differences(int n, double x[], double y[][n]) {
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
        }
    }
}

void backward_differences(int n, double x[], double y[][n]) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
        }
    }
}

int main() {
    int n;
    printf("Enter the number of values: ");
    scanf("%d", &n);

    double x[n], y[n][n];

    printf("Enter the values of x:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    printf("Enter the values of y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &y[i][0]);
    }

    for (int i = 0; i < n; i++) {
        y[i][0] = y[i][0];
    }

    forward_differences(n, x, y);

    printf("Newton's Forward Differences Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%0.2f\t\t", x[i]);
        for (int j = 0; j <= i; j++) {
            printf("%0.2f\t\t", y[i][j]);
        }
        printf("\n");
    }

    backward_differences(n, x, y);

    printf("Newton's Backward Differences Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%0.2f\t\t", x[i]);
        for (int j = 0; j <= i; j++) {
            printf("%0.2f\t\t", y[i][j]);
        }
        printf("\n");
    }

    return 0;
}