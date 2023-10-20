/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    int *arr = (int *)malloc(returnSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                arr[0] = i;
                arr[1] = j;
                return arr;
            }
        }
    }
}

int main() {
    int *arr = {2, 7, 11, 15};
    int *re = {1, 1};
    twoSum(arr, 4, 9, re);

    free(arr);
}