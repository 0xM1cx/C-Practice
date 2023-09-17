#include <iostream>
using namespace std;

int main() {
    // int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24};
    // for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
    // 	cout << arr[i] << endl;
    // }

    int age = 19;
    int *p = &age;

    cout << age << endl;
    cout << &age << endl;
    cout << *p << endl;

    *p = 1000;
    cout << age << endl;
    return 0;
}
