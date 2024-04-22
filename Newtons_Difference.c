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

/*
Output:
Enter the number of values:5

Enter the values of x:
40 50  60  70  80

Enter the values of y:
31  73  124  159  190

 Newton's Forward Differences Table:
40.00           31.00
50.00           73.00           42.00
60.00           124.00          51.00           9.00
70.00           159.00          35.00           -16.00          -25.00
80.00           190.00          31.00           -4.00           12.00           37.00

 Newton's Backward Differences Table:
40.00           31.00
50.00           73.00           42.00
60.00           124.00          51.00           9.00
70.00           159.00          35.00           -16.00          -25.00
80.00           190.00          31.00           -4.00           12.00           37.00

*/
