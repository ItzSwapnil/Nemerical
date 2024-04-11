//
//  Lagrange interpolation in c
//

#include <stdio.h>

double lagrangeCoefficient(double x, double* xi, double* yi, int n, int j) {
    double result = 1.0;
    for (int k = 0; k < n; k++) {
        if (k != j) {
            result *= (x - xi[k]) / (xi[j] - xi[k]);
        }
    }
    return result;
}

double lagrangeInterpolation(double x, double* xi, double* yi, int n) {
    double result = 0.0;
    for (int j = 0; j < n; j++) {
        result += yi[j] * lagrangeCoefficient(x, xi, yi, n, j);
    }
    return result;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double xi[n], yi[n];
    printf("Enter the data points in the format (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &xi[i], &yi[i]);
    }

    double x;
    printf("Enter the point at which interpolation is required: ");
    scanf("%lf", &x);

    double interpolatedValue = lagrangeInterpolation(x, xi, yi, n);
    printf("Interpolated value at x = %.2f is %.2f\n", x, interpolatedValue);

    return 0;
}

/*
        Output:
Enter the number of data points:4

Enter the data points in the format (x y):
1 1

2 4

3 9

4 16

Enter the point at which interpolation is required:2.5

Interpolated value at x = 2.50 is 6.25

*/