// zisaku1.c
#include <stdio.h>
int main(void){
    int n;
    printf("自然数 N を入力 : ");
    scanf("%d",&n);
        while(n!=1){
            if(n%2==0){
                n = n/2;
                printf("%d \n",n);
            }   
            else{
                n = 3*n+1;
                printf("%d \n",n);
            }
        }       
}