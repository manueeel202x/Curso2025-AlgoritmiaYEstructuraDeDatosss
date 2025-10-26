#include<stdio.h>
int main(void){

    for (int i = 2; i <= 8; i = i + 2) {
        for (int j = i; j <= 4; j++) {
            for (int k = 1; k <= j; k = k + i) { 
                printf("i: %d, j: %d, k: %d",i,j,k);
                printf("\n");
            }
        }
    }
    
}