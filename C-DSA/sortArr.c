#include <stdio.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    int *merged = malloc((nums1Size + nums2Size) * sizeof(int));

    int counter = 0;
    for (int i = 0; i < nums1Size; i++) {
        merged[counter] = nums1[i];
        counter++;
    }
    for (int j = 0; j < nums2Size; j++) {
        merged[counter] = nums2[j];
        counter++;
    }

    int ctr1 = 0, ctr2 = 0; // pag search hin merged array
    while (ctr1 < (nums1Size + nums2Size)) {
        ctr2 = ctr1 + 1;
        while (ctr2 < (num1Size + nums2Size)) {
            if (merged[ctr1] > merged[ctr2]) {
                int temp = merged[ctr1];
                merged[ctr1] = merged[ctr2];
                merged[ctr2] = temp;
            }
        }
    }
}

int main() {
    int nums1[5] = {1, 4, 2, 5, 7};
    int nums2[5] = {3, 6, 8, 9, 10};
    int nums1Size = 5;
    int nums2Size = 5;

    findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
}