#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Arr1(vector<string> arr1, string arr3[], int &count1, int count3) {
    arr3[count3] = arr1[count1];

    count1++;
}
void Arr2(vector<string> arr2, string arr3[], int &count2, int count3) {
    arr3[count3] = arr2[count2];

    count2++;
}

void Merge_Arr(vector<string> arr1, vector<string> arr2, string arr3[], int N1, int N2) {
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
    vector<string> arr1;
    vector<string> arr2;
    int N1, N2;
    cout << "How many elements for array 1: ";
    cin >> N1;

    cout << "How many elements for array2: ";
    cin >> N2;

    if ((N1 < 3) || (N2 < 3)) {
        main();
    }
    string arr3[N1 + N2];

    cout << "Input the elements for array 1: " << endl;
    for (int i = 0; i < N1; i++) {
        string element;
        cin >> element;
        arr1.push_back(element);
    }

    cout << "\nInput the elements for array 2: " << endl;
    for (int i = 0; i < N2; i++) {
        string element;
        cin >> element;
        arr2.push_back(element);
    }

    Merge_Arr(arr1, arr2, arr3, N1, N2);

    cout << "\tOUTPUT" << endl;
    cout << "==============================" << endl;

    for (int i = 0; i < N1 + N2; i++) {
        cout << arr3[i] << endl;
    }
}