#include <stdio.h>
#include <stdlib.h>


/*CAVEAT: ayaw ig try ha turbo C kay wry ko gin butngan clrscr() ngan getch()
kun gusto niyo kamo nala pag add hito ;)

JOKE LA INE BANGIN MAY MA PIKON HA IYO
*/
int checkCompatabilityOfTwoPeople(){
    // an ubos na variables para han names an fersons na ig compare
    char firstPerson[50];
    char secondPerson[50];
    printf("Input it names of two people that you want to check the compatability of:  ");
    scanf("%s%s", firstPerson, secondPerson);

    int arbitraryNumber = rand() % 100 + 1;
    printf("The Compatability of %s and %s is %d percent\n", firstPerson, secondPerson, arbitraryNumber);

    if(arbitraryNumber >= 70){
        int i = 1;
        int j;
        int rows = 10;
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
}

int checkCompatabilityOfSomeone(){
    char input[50];
    printf("Input it ngaran han tawo na na-admire ka:  ");
    scanf("%s", input);

    int randomNumber = rand() % 100 + 1;
    printf("Your compatability with %s is %d precent\n", input, randomNumber);
}


int main(){
    int choice;
    printf("Type 0 to check the compatability of two people\nType 1 to check your compatability to one person\nYour choice:  ");
    scanf("%d", &choice);
    if(choice == 0){
        checkCompatabilityOfTwoPeople();
    }
    else if(choice == 1){
        checkCompatabilityOfSomeone();
    }
    else{
        printf("Please follow the instruction!!");
    }

    return 0;

}
