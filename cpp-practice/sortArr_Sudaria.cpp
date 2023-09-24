#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

void Sort_Arr(vector<string> Arr1, int N) {
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

vector<string> push(vector<string> Arr1, int N) {
    for (int i = Arr1.size(); i < N; i++) {
        string name;
        cout << "Name: ";
        cin >> name;
        Arr1[i] = name;
    }

    return Arr1;
}

int main() {

    int N;

    vector<string> Arr1;
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

    Arr1 = push(Arr1, N);
    Sort_Arr(Arr1, N);

    return 0;
}