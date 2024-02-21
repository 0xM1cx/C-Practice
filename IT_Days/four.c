#include <stdio.h>
#include <stdlib.h>

int *twosum(int *nums, int n, int target) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                int *res = (int *)malloc(sizeof(int) * 2);
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
    return NULL;
}

void main() {
    int size;
    int target;
    printf("Number of items: \n");
    scanf("%d", &size);
    int *arrs = malloc(size * sizeof(int));
    printf("\nTarget: ");
    scanf("%d", &target);
    int temp;

    for (int i = 0; i < size; i++) {
        temp = 0;
        scanf("%d", &temp);
        arrs[i] = temp;
    }

    int *res = twosum(arrs, size, target);
    printf("[%d,%d]", res[0], res[1]);
}