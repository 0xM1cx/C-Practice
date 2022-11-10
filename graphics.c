#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char name[5];
do{
    printf("Rule no.1: Don't enter any invalid input.\n");
    printf("Yes or No[Yes/No]: ");
    gets(name);
    int result = strcmp(name, "Yes");    

    switch (result)
    {
    case 0:
        printf("They are similar");
        break;
    
    default:
        printf("They are disimilar");
        break;
    }
}while(name == "Yes" || name == "YES" || name == "yes" && name == "No" || name == "NO" || name == "no");        
}



