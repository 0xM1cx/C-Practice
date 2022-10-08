#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {

    int n;
    int exponent;
    unsigned long long int result;

    printf("Enter a number from 0 to 10: ");
    scanf("%d", &exponent);

    switch(exponent) {
        case 0:
            printf("\nHere are numbers 1 to 100 raised to the power of %d!\n\n", exponent);
            for (n = 1; n <= 100; n++) {
                printf("%d ^ %d = 1\n", n, exponent);
            }
            break;

        case 1:
            printf("\nHere are numbers 1 to 100 raised to the power of %d!\n\n", exponent);
            for (n = 1; n <= 100; n++) {
                printf("%d ^ %d = %d\n", n, exponent, n);
            }
        break;

        case 2:
            printf("\nHere are numbers 1 to 100 raised to the power of %d!\n\n", exponent);
            for (n = 1; n <= 100; n++) {
                result = n * n;
                printf("%d ^ %d = %lld\n", n, exponent, result);
            }
            break;

        case 3:
            printf("\nHere are numbers 1 to 100 raised to the power of %d!\n\n", exponent);
            for (n = 1; n <= 100; n++) {
                result = n * n * n;
                printf("%d ^ %d = %lld\n", n, exponent, result);
            }
            break;

        case 4:
            printf("\nHere are numbers 1 to 100 raised to the power of %d!\n\n", exponent);
            for (n = 1; n <= 100; n++) {
                result = n * n * n * n;
                printf("%d ^ %d = %lld\n", n, exponent, result);
            }
            break;

        case 5:
            printf("\nHere are numbers 1 to 100 raised to the power of %d!\n\n", exponent);
            for (n = 1; n <= 100; n++) {
                printf("%d ^ %d = %f\n", n, exponent, round(pow(n, 5)));
            }
            break;

        case 6:
            printf("\nHere are numbers 1 to 100 raised to the power of %d!\n\n", exponent);
            for (n = 1; n <= 100; n++) {
                result = n * n * n * n * n * n;
                printf("%d ^ %d = %lld\n", n, exponent, result);
            }
            break;

        case 7:
            printf("\nHere are numbers 1 to 100 raised to the power of %d!\n\n", exponent);
            for (n = 1; n <= 100; n++) {
                result = n * n * n * n * n * n * n;
                printf("%d ^ %d = %lld\n", n, exponent, result);
            }
            break;

        case 8:
            printf("\nHere are numbers 1 to 100 raised to the power of %d!\n\n", exponent);
            for (n = 1; n <= 100; n++) {
                result = n * n * n * n * n * n * n * n;
                printf("%d ^ %d = %lld\n", n, exponent, result);
            }
            break;

        case 9:
            printf("\nHere are numbers 1 to 100 raised to the power of %d!\n\n", exponent);
            for (n = 1; n <= 100; n++) {
                result = n * n * n * n * n * n * n * n * n;
                printf("%d ^ %d = %lld\n", n, exponent, result);
            }
            break;

        case 10:
            printf("\nHere are numbers 1 to 100 raised to the power of %d!\n\n", exponent);
            for (n = 1; n <= 100; n++) {
                result = n * n * n * n * n * n * n * n * n * n;
                printf("%d ^ %d = %lld\n", n, exponent, result);
            }
            break;

        default:
            printf("\nInvalid Input!\n\n");
            main();
            break;
        }
    return 0;
}