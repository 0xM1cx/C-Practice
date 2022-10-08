#include <stdio.h>
int assingmentThree(){
    int i = 1;
    int j;
    int rows = 20;
    // An top part han heart
    for(i = rows/2; i <= rows; i+=2){ 
        for(j = 1; j < rows-i; j+=2) {  
            printf(" ");  
        }
        
        for(j = 1; j <= i; j++){  
            printf("*");  
        }  
        
        for(j = 1; j <= rows-i; j++){  
            printf(" ");  
        }  
        
        for(j = 1; j <= i; j++){  
            printf("*");  
        }  
        
        printf("\n");  
    }
    // and ubos na part han heart; bali ine an inverted pyramid.
    for(i = rows; i >= 1; i--){  
        for(j = i; j < rows; j++){  
            printf(" ");  
        }  
        for(j = 1; j <= (i*2)-1; j++){  
            printf("*");  
        }  
       
        printf("\n");  
    }
}
int assingmentTwo(){
    int len;
    int wid;

    printf("What is the length: ");
    scanf("%d", &len);
    printf("What is the Height: ");
    scanf("%d", &wid);

    int area = len * wid;

    printf("The area of the rectangle is: %d\n", area);
}

int exerciseThree(){
    int input;
    scanf("%d", &input);
    for(int b = 1; b <= input; ++b){
        for(int j = 1; j <= b; ++j){
            printf("*");
        }
        printf("\n");
    }
    for(int a = input; a >= 0; --a){
        for(int l = a; l >= 0; --l){
            printf("*");
        }
        printf("\n");
    }
}



int exerciseTwo(){
    /* Write a program to read 10 numbers from the keyboard and find their sum and average.*/
    int sum = 0;
    for(int i = 0; i <= 10; i++){
        int n;
        scanf("Number: %d", &n);
        sum += n;
    }
    float avg = sum / 10;

    printf("The sum of 10 no. is: %d\nThe Average is: %fl", sum, avg);
}

int exerciseOne() {
 /*Write a program to display n terms of natural numbers and their sum*/
    int n;
    printf("What is n? ");
    scanf("%d", &n);
   int sum = 0;

    for(int i = 0; i <= n; i++){
        printf("%d ", i);
        sum += i;
    }
    printf("\n");
    printf("The Sum of Natural Numbers up to 7 terms: %d \n", sum);
}


int main(){
    int Userinput;
    printf("Your choice: ");
    scanf("%d", &Userinput);
    if(Userinput == 1){
        exerciseOne();
    }
    else if(Userinput == 2){
        exerciseTwo();
    }else if(Userinput == 3){
        exerciseThree();
    }else if(Userinput == 4){
        assingmentTwo();
    }else if(Userinput == 5){
        assingmentThree();
    }
}
