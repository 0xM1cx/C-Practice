#include <iostream>
#include <string>
using namespace std;

void Arr1(string arr1[], string arr3[], int &count1, int count3) {
    arr3[count3] = arr1[count1];
    count1++;
}
void Arr2(string arr2[], string arr3[], int &count2, int count3) {
    arr3[count3] = arr2[count2];
    count2++;
}

void Merge_Arr(string arr1[], string arr2[], string arr3[], int N1, int N2) {
    int count1 = 0, count2 = 0, count3 = 0;

    while ((count1 < N1) || (count2 < N2)) {
        if (count1 >= N1) {
            Arr2(arr2, arr3, count2, count3);
        } else if (count2 >= N2) {
            Arr1(arr1, arr3, count1, count3);
        } else if (arr1[count1] < arr2[count2]) {
            Arr1(arr1, arr3, count1, count3);
        } else {
            Arr2(arr2, arr3, count2, count3);
        }
        count3++;
    }
}

int main() {
    string arr1[20] = {"Strawberry", "Blueberry", "Lemon", "Mango", "Plum"};
    string arr2[20] = {"Grapes", "Pineapple", "Orange", "Cherry"};
    string arr3[20];
    int N1 = 5, N2 = 4;

    Merge_Arr(arr1, arr2, arr3, N1, N2);

    cout << "\tOUTPUT" << endl;
    cout << "==============================" << endl;

    for (int i = 0; i < N1 + N2; i++) {
        cout << arr3[i] << endl;
    }
}