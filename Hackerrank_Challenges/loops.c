#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    int sum;
    char num[5];
    itoa(n, num, 1);
    for(int i = 0; i<=sizeof(num)/sizeof(num[0]); ++i){
        int x;
        char *y = num[i];
        sscanf(y, "%d", &x);
        sum += x;
    }

    printf("%d", sum);
    return 0;
}