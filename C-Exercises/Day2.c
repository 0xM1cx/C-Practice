#include <stdio.h>


int main(){
    double tempf = 83.0;
    double tempc;
    
    tempc = (tempf - 32) / 1.8;

    printf("The temp is %lf degrees Celsius \n", tempc);
}
