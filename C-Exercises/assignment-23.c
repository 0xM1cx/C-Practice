#include <stdio.h>
#include <string.h>

struct person{
    char name[10];
    int age;
    char program[10];
};

void main(){
    
    struct person *ptr;
    struct person studentOne;

    ptr = &studentOne; 

    strcpy(ptr->name, "Shawn");
    printf("%s\n", studentOne.name);


    strcpy((*ptr).name, "Sudaria");
    printf("%s\n", (*ptr).name);

    strcpy(studentOne.name, "Michael");
    printf("%s\n", studentOne.name);

}
