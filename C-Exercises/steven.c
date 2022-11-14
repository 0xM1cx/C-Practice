#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


int main () { 
  
    char ans;
    char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; 
   
   
 

    printf("------------------------------------------------\n");
    printf("\tGuess the Word\n");
    printf("\tGuessing Game of Group 6\n");
    printf("-----------------------------------------------");


    printf("\nY= Yes, N = No\n");
    printf("\nDo you want to play? : "); 
    scanf ("%c", &ans); 
    
        switch (ans) { 
            case 'Y' : case 'y': 
            printf("\nLet the game begin!\n");
           
            printf("--------------------------------------------------------------------\n");
            printf("Instructions: This game is a guessing game\n");
            
            printf("In this game you will guess the word with the help of the riddles\n");
            
            printf("Enter a Letter only and it will automatically show you if the letter you chose is correct or wrong\n");
           
            printf("Lets begin!\n");
            printf("--------------------------------------------------------------------");
           
        
            printf("\nEnter small letters only\n");    
            printf("\nI do program just like you, who am I?");
            printf("\n_ _ _ _ _  _ _ _ _  _ _ _ _ _ _");
            printf("\nEnter enter letter here: ");
            scanf("%c", &letters); 
            int res = strcmp(letters, 's');
                if (res == 0) { 
                    printf("Congratulations you are correct!\n");
                    printf("S _ _ _ _  _ _ _ _  _ _ _ _ _ _");
                    } else {
                        printf("\nYou are wrong try again!");
            }
            
           }
            
    return 0; 
 }