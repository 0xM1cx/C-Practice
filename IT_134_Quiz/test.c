#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>


void main(){
    int time = clock();
    sleep(3);
    printf("%d", time);
}