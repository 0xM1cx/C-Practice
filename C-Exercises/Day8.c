#include <stdio.h>

int dist(int points[], int len) {
    int distance;
    int biggest = 0;
    int smallest = 0;
    for (int i = 0; i < len; i++) {
        // check biggest
        if (points[i] > biggest) {
            biggest = points[i];
        }
    }

    smallest = biggest;
    for (int i = 0; i < len; i++) {
        if (points[i] < smallest) {
            smallest = points[i];
        }
    }

    distance = biggest - smallest;
    return distance;
}
int main() {
    int d[] = {1, 2, 3, 2.5, 3.5, 120};
    int len = sizeof(d) / sizeof(d[0]);
    int distance = dist(d, len);
    printf("%d\n", distance);
    return 0;
}