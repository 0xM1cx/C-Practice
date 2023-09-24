#include <iostream>
#include <string>
#include <vector>

using namespace std;

void arr1(vector<string> Arr3, int Count3, vector<string> Arr1, int Count1) {
    Arr3[Count3] = Arr1[Count1];
    Count1++;
}

void arr2(vector<string> Arr3, int Count3, vector<string> Arr2, int Count2) {
    Arr3[Count3] = Arr2[Count2];
    Count2++;
}

void Merge_Arr(vector<string> Arr1, vector<string> Arr2, int N1, int N2) {
    int Count1 = 1;
    int Count2 = 1;
    int Count3 = 1;
    for (int i = 0; i < Arr2.size(); i++) {
        cout << "Arr2[" << i + 1 << "] = " << Arr2[i] << endl;
    }

    vector<string> Arr3;

    while ((Count1 <= N1) || (Count2 <= N2)) {
        if (Count1 > N1) {
            arr2(Arr3, Count3, Arr2, Count2);
        } else {
            if (Count2 > N2) {
                arr1(Arr3, Count3, Arr1, Count1);
            } else {
                if (Arr1[Count1] < Arr2[Count2]) {
                    arr1(Arr3, Count3, Arr1, Count1);
                } else {
                    arr2(Arr3, Count3, Arr2, Count2);
                }
            }
        }
        Count3++;
    }
}

int main() {

    vector<string> Arr1 = {"Mango", "Orange", "Apple"};
    vector<string> Arr2 = {"Banana", "Grape"};

    int N1 = Arr1.size(), N2 = Arr2.size();
    Merge_Arr(Arr1, Arr2, N1, N2);

    return 0;
}