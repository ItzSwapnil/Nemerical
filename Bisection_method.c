//
// Bisection method
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double bisect ( double num)
{
    return (pow(num, 3) - num - 1);
}

int main ()
{
    printf ( " \n Display the real roots of the given equation using the Bisection method: ");
    printf ( " \n x ^ 3 - x - 1 = 0 \n ");
    double x0, x1;

    printf ( " \n Enter the first approximation of the root: ");
    scanf (" %lf", &x0);


    printf ( " \n Enter the second approximation of the root: ");
    scanf (" %lf", &x1);

    int iterate;
    printf (" \n Input the number of iteration you want to perform: ");
    scanf (" %d", &iterate);


    int count = 1;
    double a = x0;
    double b = x1;
    double r, f1, f2, f3;

    if (bisect (a) == 0)
    {
        r = a;
    }
    else if ( bisect (b) == 0)
    {
        r = b;
    }

    else
    {
        while (count <= iterate)
        {
            f1 = bisect (a);
            r = (a + b) / 2.0;
            f2 = bisect (r);
            f3 = bisect (b);

            if (f2 == 0)
            {
                r = f2;
                break;
            }

            printf (" \n The root after %d iterations is %lf. \n", count, r);

            if ( f1 * f2 < 0)
            {
                b = r;
            }
            else if (f2 * f3 < 0)
            {
                a = r;
            }
            count++;
        }
    }
    printf (" \n The approximation of the root is: %lf \n ", r);
    return 0;
}

/*
            Output:
Display the real roots of the given equation using the Bisection method:
 x ^ 3 - x - 1 = 0

 Enter the first approximation of the root:1


 Enter the second approximation of the root:2


 Input the number of iteration you want to perform:3


 The root after 1 iterations is 1.500000.

 The root after 2 iterations is 1.250000.

 The root after 3 iterations is 1.375000.

 The approximation of the root is: 1.375000

*/