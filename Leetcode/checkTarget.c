/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

void twoSum(int *nums, int numsSize, int target) {
    int *arr = (int *)malloc(2 * sizeof(int));
    int flag = 0;
    for (int i = 0; i < numsSize; i++) {
        if (flag == 1) {
            break;
        }

        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                arr[0] = i;
                arr[1] = j;
                break;
                flag = 1;
            }
        }
    }

    printf("[%d, %d]", arr[0], arr[1]);
}

int main() {
    int arr[] = {3, 3};
    twoSum(arr, 4, 6);
}