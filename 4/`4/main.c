#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int Made(int m1, int m2, int n2);
void Max_Min_A(int **a,int m1);
void Tp(int **b,int m2,int n2);
void sortA(int **a,int m1);
void sum(int **a,int **b,int m1,int m2,int n2);

void main(){
    int m1 = 3, m2 = 1, n2 = 3;
    printf("Input size first matrix:\t");
    scanf("%d",&m1);
    printf("Input size second matrix\nCols:\t");
    scanf("%d",&m2);
    printf("\nRows:\t");
    scanf("%d",&n2);
    Made(m1,m2,n2);



    getch();
}
int Made(int m1, int m2, int n2){
    int choice1,choice2;
    int **a;
    int **b;

    a = malloc(m1 * sizeof(int *));
    for (int i = 0; i < m1; i++){
        a[i] =  malloc(m1 * sizeof(int));
    }
    a[1][1] = 7;
  /*  printf("%d",a[1][1]);
    getch();*/
    b = malloc(n2 * sizeof(int *));
    for (int i = 0; i < n2; i++){
        b[i] =  malloc(m2 * sizeof(int));
    }
    printf("You or me will fill square matrix? (1 - you  0 - me):\t ");
    scanf("%d",&choice1);

    if(choice1 == 0){
         for (int i = 0; i < m1; i++){
            for (int j = 0; j < m1; j++){
                printf("b[%d][%d] = ", i, j);
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 0; i < m1; i++){
            for (int j = 0; j < m1; j++){
                printf("%d \t", a[i][j]);
            }
            printf("\n");
        }
    }if(choice1 == 1){
        for (int i = 0; i < m1; i++){
            for (int j = 0; j < m1; j++){
                printf("b[%d][%d] = %d\n", i, j,i + j);
                a[i][j] = i + j;
            }
        }
        for (int i = 0; i < m1 ; i++){
            for (int j = 0; j < m1; j++){
                printf("%d \t", a[i][j]);
            }
            printf("\n");
        }
    }else{printf("\nBie bie");}
    printf("\nYou or me will fill 2D+ matrix? (1 - you  0 - me):\t ");
    scanf("%d", &choice2);
    printf("\n choice  = %d \n", choice2);
    if(choice2 == 0){
        for (int i = 0; i < n2; i++){
            for (int j = 0; j < m2; j++){
                printf("b[%d][%d] = ", i, j);
                scanf("%d", &b[i][j]);
            }
        }
        for (int i = 0; i < n2; i++){
            for (int j = 0; j < m2; j++){
                printf("%d \t", b[i][j]);
            }
            printf("\n");
        }
    }if(choice2 == 1){
        for (int i = 0; i < n2; i++){
            for (int j = 0; j < m2; j++){
                printf("b[%d][%d] = %d\n", i, j,i + j);
                b[i][j] = i + j;
            }
        }
        for (int i = 0; i < n2 ; i++){
            for (int j = 0; j < m2; j++){
                printf("%d \t", b[i][j]);
            }
            printf("\n");
        }
    }else{printf("\nBie bie");}
    //sortA(a,m1);
    //sum(a,b,m1,m2,n2);
    Mult(a,b,m1,m2,n2);
    for (int i = 0; i < m1; i++)
    free(a[i]);
    free(a);
    for (int i = 0; i < n2; i++)
    free(b[i]);
    free(b);
}

void Max_Min_A(int **a,int m1){
    int max = 1;
    int min = 0;
    for(int i = 0; i < m1; i++ ){
        for (int j = m1 - 1; j > i;j--){
            max = (a[i][j] > max ? a[i][j] : max);
            min = (a[i][j] < min ? a[i][j] : min);
        }

    }
    printf("\nMax up:\t%d\nMin up:\t%d\n",max,min);
    min = 1;
    max = 0;
    for(int i = 0;i < m1;i++){
        for(int j = 0; j < i; j++){
            max = (a[i][j] > max ? a[i][j] : max);
            min = (a[i][j] < min ? a[i][j] : min);
        }
    }
    printf("\nMax down:\t%d\nMin down:\t%d\n",max,min);
}

void Tp(int **b,int m2,int n2){
    int **temp;
     temp = malloc(m2 * sizeof(int *));
    for (int i = 0; i < m2; i++){
        temp[i] =  malloc(n2 * sizeof(int));
    }
    for(int i = 0;i < m2;i++){
        for(int j = 0;j < n2;j++){
            temp[i][j] = b[j][i];
        }
    }
    for(int i = 0;i < m2;i++){
        for(int j = 0;j < n2;j++){
            printf("%d\t",temp[i][j]);
        }
        printf("\n");
    }

for (int i = 0; i < n2; i++)
    free(temp[i]);
    free(temp);
}
void Mult(int **a,int **b,int m1,int m2,int n2){
    int **temp;
    temp = malloc(m2 * sizeof(int *));
    for (int i = 0; i < m2; i++){
        temp[i] =  malloc(n2 * sizeof(int));
    }
    if(m1 != m2 ){
        printf("We cant do this");
        return;
    }
    for(int i = 0; i < m2;i++){
        for (int j = 0;j < n2;j++){
            temp[i][j] = a[i][j] * b[j][i];
        }
    }
    for(int i = 0;i < m2;i++){
        for(int j = 0;j < n2;j++){
            printf("%d\t",temp[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n2; i++)
    free(temp[i]);
    free(temp);
}
void sortA(int **a,int m1){
    int row;
    int arr[m1];
    printf("choose a row: \t");
    scanf("%d",&row);
    row--;
    for(int i = 0 ; i < m1; i++){
       for(int j = 0 ; j < m1 -i ; j++){
           if(a[row][j] > a[row][j+1]){
                int tmp = a[row][j];
                a[row][j] = a[row][j+1];
                a[row][j+1] = tmp;
           }
        }
    }
    printf("\n");
    for (int i = 0;i < m1;i++){
        printf("%d\t",a[row][i]);
    }
}
void sum(int **a, int **b,int m1,int m2,int n2){
    int sum =0;
    printf("\n");
    for (int i = 0;i < m1;i++){
        for(int j = 0;j < m1;j++){
            sum+=a[i][j];
        }
        printf("%d\t",sum);
        sum = 0;
    }
    sum = 0;
    printf("\n\n");
    for (int i = 0;i < m2;i++){
        for(int j = 0;j < n2;j++){
            sum+=b[j][i];
        }
        printf("%d\t",sum);
        sum = 0;
    }

}
