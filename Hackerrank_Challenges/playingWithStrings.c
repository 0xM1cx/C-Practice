/*Task
You have to print the character, ch, in the first line. Then print s in
the next line. In the last line print the sentence, sen*/

#include <stdio.h>


int main(){
    char ch;
    char s[100];
    char sen[99];

    printf("Give input(Character): ");
    scanf("%c", &ch);

    
    printf("Give input(String): ");
    scanf("\n");
    scanf("%[^\n]%*c", s);


    printf("Give input(Sentence): ");
    scanf("\n");
    scanf("%[^\n]%*c", sen);

    printf("%c\n%s\n%s", ch, s, sen);

    return 0;  
}