#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

int main()
{
    printf("Bounce na tayo par after the countdown ");
    for (int i=5 ; i >= 1 ; i--)
    {
        printf(" %d ", i);
        sleep(3);
    }
    return 0;
}