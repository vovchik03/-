#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.c"

double F(double x);
double ddF(double x);
double Hord(double x0, double x1, double eps);
double The_Half(double x0, double x1, double eps);
double Isaak(double x, double eps);
double choice();
int V3();



int main()
{
    choice();
}


int V3(){
    printf("You think you have a big choice?\n");
    choice();
}
double F(double x){
    return pow(x+2,3)-pow(x,3);
}
double ddF(double x){
    return 3.1415 / 180 * cos(3.1415*x / 180) + 1 / (x*x);
}
double Hord(double x0, double x1, double eps){
    double f0, f;
    int i = 0;

    printf("X0 = %.4f \t X1 = %.4f\n",x0, x1);
    do {
    f = F(x1);
    f0 = F(x0);
    x1 = x1 - f / (f - f0)*(x1 - x0);
    i++;
  } while (fabs(f) > eps && i < 1000);
    printf("resoult = %.4f\n",x1);
    return x1;
}
double The_Half(double x0, double x1, double eps){
    double x, f;
    int i = 0;
    printf("X0 = %.4f \t X1 = %.4f\n",x0, x1);
    do {
    x = (x0 + x1) / 2;
    f = F(x);
    f > 0 ? (x1 = x) : (x0 = x) ;
    i++;
  } while (fabs(f) > eps && i <  1000);
    printf("resoult = %.4f\n",x);
    f0=10;
    return x;
}
double Isaak(double x, double eps){
    double f;
    int i = 0;
    printf("X = %.4f \n",x);
    do{
        f = F(x);
        x = x - F(x)/ddF(x);
        i++;
    }while(fabs(f) > eps && i < 1000);
    printf("resoult = %.4f\n",x);
    return x;
}
double choice(){
    int choice,n;
    double x0,x1,eps;
    printf("1 - Hord\n2 - Half\n3 - Isaak\n");
    printf("\nChoice you variant:\t");
	scanf("%i", &choice);
	printf("Input variables\nx0:\t");
	scanf("%lf", &x0);
	printf("\nx1:\t");
	scanf("%lf", &x1);
	printf("\neps:\t");
	scanf("%i", &eps);
	double Method = choice == 1 ? Hord(x0,x1,eps) : choice == 2 ? The_Half(x0,x1,eps) : choice == 3 ? Isaak(x0,eps) : V3();
    return Method;
}
