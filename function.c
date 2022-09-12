#include <stdio.h>

void recur(){
    int num = 1;
    printf("%d", num);
    
    if(num % 10 == 0){
        printf("\n");
    }
    if(num != 100){
        num += 1;
        recur();
    }
}
void greetUser(int age, char name[20]){
    if(age >= 18){
        printf("Welcome %s\n", name);
    }else{
        printf("I'm sorry %s but you are %d yrs old, which makes you a minor \n", name ,age);
    }
}

int main() {
    char userName[20];
    printf("Who are you? ");
    scanf("%s", userName);

    int UserAge;
    printf("How old are you? ");
    scanf("%d", &UserAge);
    greetUser(UserAge, userName);

    recur();
}
