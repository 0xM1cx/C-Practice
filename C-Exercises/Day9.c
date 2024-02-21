#include <stdio.h>

int isPrime(int n) {
    if (n == 1) {
        return 0;
    } else if (n <= 3) {
        return 1;
    } else {
        if (n % 2 != 0 || n % 3 != 0) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    int bool = isPrime(4);
    if (bool == 1) {
        printf("Is Prime Number");
    } else if (bool == 0) {
        printf("Is Composite");
    }

    return 0;
}