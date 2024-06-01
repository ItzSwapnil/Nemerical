//
// Newton Raphson
//

#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * sin(x) - 1;
}

double f_prime(double x) {
    return sin(x) + x * cos(x);
}

int main() {
    double x0, x1, tolerance;
    int max_iterations, iteration = 0;

    printf("Enter the initial guess: ");
    scanf("%lf", &x0);

    printf("Enter the tolerance: ");
    scanf("%lf", &tolerance);

    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    printf("Iterating using Newton-Raphson Method...\n");

    do {
        if (fabs(f_prime(x0)) < 1e-10) {
            printf("Derivative too small, solution may not converge.\n");
            return -1;
        }
        x1 = x0 - f(x0) / f_prime(x0);
        iteration++;

        printf("Iteration %d: x = %.10lf\n", iteration, x1);

        if (fabs(x1 - x0) < tolerance) {
            printf("Root found: x = %.10lf\n", x1);
            return 0;
        }

        x0 = x1;
    } while (iteration < max_iterations);

    printf("Exceeded maximum iterations. No solution found.\n");
    return -1;
}


/*

Output:
Enter the initial guess:1

Enter the tolerance:0.00001

Enter the maximum number of iterations:10

Iterating using Newton-Raphson Method...
Iteration 1: x = 1.1147286724
Iteration 2: x = 1.1141571268
Iteration 3: x = 1.1141571409
Root found: x = 1.1141571409

*/