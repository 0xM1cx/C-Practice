#include <iostream>
#include <windows.h>
using namespace std;

void Sort_Arr(string Arr1[], int N) {
    for (int i = 0; i < N; i++) {
        cout << Arr1[i][0] << endl;
    }

    int Ctr1 = 0;
    while (Ctr1 <= N - 2) {
        int Ctr2 = Ctr1 + 1;
        while (Ctr2 <= N) {
            if (Arr1[Ctr1][0] > Arr1[Ctr2][0]) {
                string temp = Arr1[Ctr1];
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

int main() {

    int N;

    string arr1[] = {"Belle", "Lil'o", "Rae", "Ash", "Cyril"};

    cout << "============================================================" << endl;
    cout << "\nHow many elements would you like in the array? ";
    cin >> N;
    cout << "\n============================================================" << endl;
    loading();
    Sort_Arr(arr1, N);

    return 0;
}