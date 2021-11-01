#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Math.h>

int V1();
int V2();
void End();
void End1();
int V3();
double D(double x);
int Choice();


int V1(){
    //printf("F1");
   /* puts("\xBC"); правый низ
    puts("\xBA");палка
    puts("\xCB"); верхушичка
    puts("\xC8");левый низ
    */
    //puts("\xCC"); левая серединная
    //puts("\xCD");горизонтальная Е хрестик
1   //puts("\x9B");
    ;double X1, X2;unsigned int N;
    double step;
    int count = 0;
    printf("Start from:");
    scanf("%lf", &X1);
    printf("Finish in:");
    scanf("%lf", &X2);
    printf("Dots?:");
    scanf("%i", &N);

    if(X2 - X1 > 0 && N > 0){
        puts("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        puts("\xBA         N        \xBA          X        \xBA");
        puts("\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBA");
        step = (X2-X1) / N;
        for(int i = N;i>0;i--){
            X1 += step;
            printf("\n\xBA %17d\xBA%18.3f \xBA\n",count,X1);
            End1();
            count++;
            if(count  % 13 == 1){printf("\nPress any key...\n");_getch();}
        }
    }




 return 0;
}

int V2(){
    //printf("F2");
    double X1, X2, delta,F;
    int N=0;
    printf("Start from:");
    scanf("%lf", &X1);
    printf("Finish in:");
    scanf("%lf", &X2);
    printf("Delta?:");
    scanf("%lf", &delta);
    F = D(X1);
   // printf("%d     %.3      %.3",N, X1, F);
    if(X2-X1 > 0){
        puts("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB"
            "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        puts("\xBA         N        \xBA          X        \xBA        F(x)       \xBA");
        puts("\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE"
            "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBA");
        for (X1;X1<X2;X1 = X1+delta){

                F = D(X1);
                printf("\xBA %17d\xBA%18.3f \xBA%19.3f\xBA\n",N,X1,F);
                N++;
                End();
                if(N % 13 == 1){ printf("\nPress any key...\n"); _getch();}

        }

    }

 return 0;

}
void End1(){
            printf("\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBA");
}
void End (){
            //printf("\n");
            printf("\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE"
            "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBA\n");
 }
int V3(){
    printf("You think you have a big choice?\n");
    Choice();
}
double D(double x){
    double F;
    F = sqrt(x) + 1;
    return F;
}
int Choice(){
    int choice;
    printf("Choice you variant:\t");
	scanf("%i", &choice);
    int V = choice == 1 ? V1() : choice == 2 ? V2() : V3();
}

int main(){
    Choice();
    printf("\n");

}
