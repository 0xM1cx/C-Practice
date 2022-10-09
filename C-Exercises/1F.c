#include <stdio.h>

int questionThree(){
    /*Write a C program the convertes the number of minutes to 
    days and years.*/

    int min;
    printf("INPUT MINUTES: ");
    fgets(min);
    float days = min / 24;
    float years = min / 525600;

    printf("%d minutes in %.0f days and %.1f years\n", min, days, years);
}


int questionTwo(){
    /*Designa a program using conditional operators what will evaluate
    if the number entered is positive or negative*/

    int userInput;
    printf("INPUT NUMBER: ");
    scanf("%d", &userInput);
    
    if(userInput >= 0){
        printf("The number entered %d is positive\n", userInput);
    }else{
        printf("The number entered %d is negative\n", userInput);
    }

    return 0;
}

int questionOne(){
    /*Create a program that automatically generate a student's biodata
    on his/her inputted infor. Information will be Student Name, School,
    Department, Course, Year and Section. Address and Mobile Number*/

    char studentName[50], school[50], department[50], course[50], Year[50], Section[50];
    printf("Input the ff information\n+\tName\n+\tSchool\n+\tDepartment\n+\tCourse\n+\tYear\n+\tSection\n");
    printf("E.g. John EVSU COE BSIT 1st 1F\n");
    scanf("%s%s%s%s%s%s", studentName, school, department, course, Year, Section);

    printf("\n+\tName: %s\n+\tSchool: %s\n+\tDepartment: %s\n+\tCourse: %s\n+\tYear: %s\n+\tSection: %s\n", studentName, school, department, course, Year, Section);
    return 0;
}

int main(){
    
    int input;
    printf("Type the number of the question you want to run: ");
    scanf("%d", &input);

    if(input == 1){
        questionOne();
    }
    else if(input == 2){
        questionTwo();
    }
    else if(input == 3){
        questionThree();
    }
    return 0;


}