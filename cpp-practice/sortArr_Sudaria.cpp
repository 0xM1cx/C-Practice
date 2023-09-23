#include <iostream>
#include <windows.h>
using namespace std;

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
    cout << "\b";
}

int main() {

    int N;

    cout << "============================================================" << endl;
    cout << "\nHow many elements would you like in the array? ";
    cin >> N;
    cout << "\n============================================================" << endl;
    loading();
    cout << "The Value of N is: " << N << endl;

    return 0;
}