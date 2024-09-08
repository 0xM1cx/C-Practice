#include <iostream>

using namespace std;

void BubbleSort(int arrOne[]) {
    int N = sizeof(arrOne) / sizeof(arrOne[0]);
    cout << N << endl;
}

int main() {
    int arr[] = {5, 1, 3, 4, 2};
    BubbleSort(arr);
    return 0;
}
