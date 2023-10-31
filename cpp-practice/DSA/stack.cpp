#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
using namespace std;

void loadingAnimation() {
    for (int i = 1; i <= 3; i++) {
        printf("\b-");
        this_thread::sleep_for(chrono::milliseconds(100));
        printf("\b\\");
        this_thread::sleep_for(chrono::milliseconds(100));
        printf("\b|");
        this_thread::sleep_for(chrono::milliseconds(100));
        printf("\b/");
        this_thread::sleep_for(chrono::milliseconds(100));
        printf("\b");
    }
}

void DisplayTable() {
}

int AskValue() {
    int num;
    printf("Number to Push: ");
    scanf("%d", &num);
    return num;
}

int Push(int value, vector<int> Arr, int Top) {
    Arr[Top] = value;
    return Top++;
}

void Pop(vector<int> Arr, int Top) {
    printf("%d", Arr[Top]);
    Top--;
}

int main() {

    int userOption, Top = 0, value;
    printf("[1] Push()\n[2] Pop()\n[3] Exit\n");
    printf("OPTION: ");
    scanf("%d", &userOption);
    vector<int> Arr;
    if (userOption < 1 || userOption > 3) {
        printf("Number must be within the options!!\n");
        loadingAnimation();
        main();
    }
    switch (userOption) {
    case 1:
        value = AskValue();
        Top = Push(value, Arr, Top);
        break;
    case 2:
        Pop(Arr, Top);
        break;
    case 3:
        printf("Goodbye!!...");
        loadingAnimation();
        exit(0);
        break;
    default:
        break;
    }
}
