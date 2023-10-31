#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <string.h>
#include <thread>
#include <vector>
using namespace std;

vector<string> Arr;
int Top = 0, counter = 1;
map<int, vector<string>> dictionary;

void loadingAnimation(), AddToMap(string Method_Used, string retVal, string stack_content), Push(string value), Pop(), MainMenu();
string AskValue();
int DisplayTable();

int main() {

    MainMenu();
}

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

void MainMenu() {
    int userOption;
    string value;
    printf("[1] Push()\n[2] Pop()\n[3] Exit\n");
    printf("OPTION: ");
    scanf("%d", &userOption);
    if (userOption < 1 || userOption > 3) {
        printf("Number must be within the options!!\n");
        loadingAnimation();
        MainMenu();
    }

    switch (userOption) {
    case 1:
        value = AskValue();
        Push(value);
        break;
    case 2:
        Pop();
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

void AddToMap(string Method_Used, string retVal, string stack_content) {
    dictionary[counter] = {
        Method_Used,
        retVal,
        stack_content};
    counter++;
}

int DisplayTable() {
    system("cls");
    cout << setw(15) << left << "Method Used"
         << setw(1) << left << " "
         << setw(15) << left << "Return Value"
         << setw(1) << left << " "
         << setw(25) << left << "Stack Content" << endl;

    for (int i = 1; i <= counter; i++) {
        cout << setw(15) << left << dictionary[i][0]
             << setw(1) << left << " "
             << setw(15) << left << dictionary[i][1]
             << setw(1) << left << " "
             << setw(25) << left << dictionary[i][2] << endl;
    }
}

string AskValue() {
    string input;
    printf("Number to Push: ");
    cin >> input;
    return input;
}

void Push(string value) {
    Arr.push_back(value);
    Top++;
    string combined;               // To hold all the array elements in a single string separeted by spaces
    for (const string &el : Arr) { // Para mag iterate over every element ha Arr na array
        combined += el + " ";
    }

    AddToMap("Push()", "-", combined);
    DisplayTable();
    cout << "Bye";
}

void Pop() {
    if (Top != 0) {

        DisplayTable();
        Top--;
    } else {
        printf("Stack is Empty");
    }
}
