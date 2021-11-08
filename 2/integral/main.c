#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Func_Integral(double x);
double left_triangle(double a, double b, int n);
double right_triangle(double a, double b, int n);
double trapeze(double a, double b, int n);
double Homer(double a, double b, int n);
int V3();
double choice();
void Draw(double s);

double Func_Integral(double x){
    return 1/(1 + x);
}
double left_triangle(double a, double b, int n){
    double h = (b - a) / n;
    double s = 0;
    for(int i = 0; i <= n - 1;++i){
        s += h * Func_Integral(a + i * h);
    }
    Draw(s);
    return s;
}
double right_triangle(double a, double b, int n){
    double h = (b - a) / n;
    double s = 0;
    for(int i = 0; i <= n;i++){
        s += h * Func_Integral(a + i * h);
    }
    Draw(s);
    return s;
}
double trapeze(double a, double b, int n){
    double h = (b - a) / n;
    double s = Func_Integral(a) + Func_Integral(b);
    for(int i = 0;i <= n - 1;i++){
        s += 2 * Func_Integral(a+ i * h);
    }
    s *= h / 2;
    Draw(s);
    return s;
}
double Homer(double a, double b, int n){
    double h = (b - a) / n;
    double s = Func_Integral(a) + Func_Integral(b);
    int k = 0;
    for(int i = 0;i <= n - 1;i++){
        k = 2 + 2 * (i % 2);
        s += k * Func_Integral(a + i * h);
    }
    s *= h / 3;
    Draw(s);
    return s;
}
void Draw(double s){
        puts("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        puts("\xBA        F(x)      \xBA          S        \xBA");
        puts("\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBA");
        printf("\xBA      1/(1+x)     \xBA%18.3f \xBA\n",s);
        puts("\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBA");
}
int V3(){
    printf("You think you have a big choice?\n");
    choice();
}

double choice(){
    int choice,n;
    double a,b;
    printf("1 - left triangle\n2 - right triangle\n3 - trapeze\n4 - Simpson");
    printf("\nChoice you variant:\t");
	scanf("%i", &choice);
	printf("Input variables\na:\t");
	scanf("%lf", &a);
	printf("\nb:\t");
	scanf("%lf", &b);
	printf("\nn:\t");
	scanf("%i", &n);
	double Method = choice == 1 ? left_triangle(a,b,n) : choice == 2 ? right_triangle(a,b,n) : choice == 3 ? trapeze(a,b,n) : choice == 4 ? Homer(a,b,n) : V3();
    return Method;
}

int main(){
    //Draw(50);
  choice();
}
