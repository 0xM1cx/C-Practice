#include <iostream>
#include <windows.h>
using namespace std;

void Sort_Arr(string Arr1[], int N) {
    int Ctr1 = 0, Ctr2;
    string temp;

    while (Ctr1 <= N - 2) {
        Ctr2 = Ctr1 + 1;
        while (Ctr2 <= N - 1) {
            if (Arr1[Ctr1][0] > Arr1[Ctr2][0]) {
                temp = Arr1[Ctr1];
                Arr1[Ctr1] = Arr1[Ctr2];
                Arr1[Ctr2] = temp;
            }
            Ctr2++;
        }
        Ctr1++;
    }

    for (int i = 0; i < N; i++) {
        cout << Arr1[i] << " ";
    }
}

void loading() {
    for (int i = 0; i < 5; i++) {
        Sleep(90);
        cout << "\b\\";
        Sleep(90);
        cout << "\b|";
        Sleep(90);
        cout << "\b/";
        Sleep(90);
        cout << "\b-";
    }
    cout << "\b" << endl;
}

void push(string Arr1[], int N) {
    int arr_len = sizeof(Arr1) / sizeof(Arr1[0]);
    cout << arr_len;
}

int main() {

    int N;
    string arr1[0];
    cout << "============================================================" << endl;
    cout << "\nHow many elements would you like in the array? ";
    cin >> N;

    if (N < 3) {
        cout << "Elements in the arry must be greater than 3!";
        loading();
        main();
    }

    cout << "\n============================================================" << endl;
    loading();

    push(arr1, N);
    // Sort_Arr(arr1, N);

    return 0;
}