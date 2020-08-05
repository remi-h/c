#include <stdio.h>
#include <math.h>
int main(void){
	int a,b,c,D,x1,x2;
	printf("y = ax^2 + bx + c の解を出力します\na,b,cをそれぞれ入力してください \n a=");
	scanf("%d",&a);
    printf("y= %d x^2 + bx + c \n b=",a);
	scanf("%d",&b);
    printf("y= %d x^2 + %d x + c \n c=",a,b);
	scanf("%d",&c);
    printf("y= %d x^2 + %d x + %d \n",a,b,c);
    D=b*b-4*a*c;
	x1=(b+sqrt(D))/2*a;
	x2=(b-sqrt(D))/2*a;
    if(D>0) printf("実数解は2つ");
    if(D==0) printf("実数解は1つ, 重解");
    if(D<0) printf("実数解はなし");
    printf("y = %d x^2 + %d x + %d の",a,b,c);
	printf("解は x = %d, %d \n", x1, x2);
	return 0;
}