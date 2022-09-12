#include <stdio.h>

int main(){
    int n;
    printf("Input: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int b = 1; b <=i; b++){
            printf("*");
        }
        printf("\n");
    }
    for(int j = n - 1; j >= 1; j--){
        for(int a = j; a >=1; a--){
            printf("*");
        }
        printf("\n");
    }
}
