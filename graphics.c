#include <stdio.h>
#include <stdlib.h>

void main()
{

    char name[5];

do{
    printf("Rule no.1: Don't enter any invalid input.\n");
    printf("Yes or No[Yes/No]: ");
    scanf("%s", name);

    strcmp();
    if(name == "Yes" || name == "YES" || name == "yes"){
            printf("You're in a loop.");
    }
    else if(name == "No" || name == "NO" || name == "yes"){
           printf("You're in a loop."); 
    }
    else{
        printf("I TOLD YOU, DON'T ENTER ANY INVALID OUTPUT!");
    }
}
while(name == "Yes" || name == "YES" || name == "yes" && name == "No" || name == "NO" || name == "no");        
}
