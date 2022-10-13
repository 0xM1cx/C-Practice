#include <stdio.h>

int exerciseThree(){
    for(int i = 1; i<=50; ++i){
        if(i % 2 == 0){
            printf("%d\n", i);
        }
    }
}
int exerciseTwo(){
    int n;
    printf("What is n? ");
    scanf("%d", &n);
    for(int f = 1; f<=n; f++){
        for(int y = 1; y<=f; y++){
            printf("%d ", f);
        }
        printf("\n");
    }
}
int exerciseOne(){
    for(int b = 1; b<=20; b++){
        for(int a = 1; a<=b; a++){
            printf("*");
        }
        printf("\n");
    }
    for(int a = 20; a>=0; a--){
        for(int j = a; j>=0; j--){
            printf("*");
        }
        printf("\n");
    }
}

int main(){
   int userInput;
   printf("Input: ");
   scanf("%d", &userInput);

   if(userInput == 1){
       exerciseOne();
   } 
   else if(userInput == 2){
       exerciseTwo();
   }
   else if(userInput == 3){
       exerciseThree();
   }
}
