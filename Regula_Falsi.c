//
// Regula Falsi
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define f(x) ((x*x*x)-2*x+1)
int main(){
    float a=0,b=0,error=0,c,cold;
    int i=0;
    printf("Input Interval: ");
    scanf("%f %f",&a,&b);
    if((f(a)*f(b))>0){
        printf("Invalid Interval Exit!");
        exit(1);
    }
    else if(f(a)==0 || f(b)==0){
        printf("Root is one of interval bounds. Root is %f\n",f(a)==0?a:b);
        exit(0);
    }
    printf("Ite\ta\t\tb\t\tc\t\tf(c)\t\terror\n");
    do{
        cold=c;
        c=(((a*f(b))-(b*f(a)))/(f(b)-f(a)));
        printf("%2d\t%4.6f\t%4.6f\t%4.6f\t%4.6f\t",i++,a,b,c,f(c));
        if(f(c)==0){
            break;
        }else if(f(a)*f(c)<0){
            b=c;
        }else a=c;
        error=fabs(c-cold);
        if(i==1){
            printf("----\n");
        }else printf("%4.6f\n",error);

    }while(error>0.00005);
    printf(" Root is %4.6f \n",c);
    return 0;
}

/*
Output:
 Input Interval:-2

2

Ite     a               b               c               f(c)            error
 0      -2.000000       2.000000        -0.500000       1.875000        ----
 1      -2.000000       -0.500000       -1.076923       1.904870        0.576923
 2      -2.000000       -1.076923       -1.435412       0.913290        0.358489
 3      -2.000000       -1.435412       -1.567177       0.285301        0.131765
 4      -2.000000       -1.567177       -1.604764       0.076833        0.037587
 5      -2.000000       -1.604764       -1.614633       0.019852        0.009870
 6      -2.000000       -1.614633       -1.617167       0.005075        0.002533
 7      -2.000000       -1.617167       -1.617813       0.001293        0.000646
 8      -2.000000       -1.617813       -1.617978       0.000330        0.000165
 9      -2.000000       -1.617978       -1.618020       0.000084        0.000042
 Root is -1.618020

*/