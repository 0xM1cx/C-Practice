#include <iostream>

using namespace std;

string Sort_Arr(string Arr1[], int N) {
    int Ctr1 = 1;
    while (Ctr1 <= N - 1) {
        int Ctr2 = Ctr1 + 1;
        while (Ctr2 <= N) {
            if (Arr1[Ctr1] > Arr1[Ctr2])
            {
                string
            }
            
        }
    }
}

int main() {
    string names[] = {"Cyril", "Lil'o", "Belle", "Ash", "Rae"};
    cout << Sort_Arr(names, 5) << endl;
    return 0;
}