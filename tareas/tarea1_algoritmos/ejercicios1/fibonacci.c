#include<stdio.h>
int main(void){
    int n;
    printf("Ingrese un numero n: ");
    scanf("%d",&n);

    int a=0,b=1,c=1;

    if(n==0)
        printf("%d",a);
    else if(n==1)
        printf("%d,%d",a,b);
    else{
        printf("%d,%d",a,b);
        n-=1;
        while(n--){
            printf("%d",c);
            a=b;
            b=c;
            c=a+b;
        }
    }
    return 0;
}