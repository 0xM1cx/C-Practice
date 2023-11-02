#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <string.h>
#include <thread>
#include <vector>
using namespace std;

// Declaring the global variables
string Arr[100];
int Top = 0, counter = 0, border_Flag = 0;
map<int, vector<string>> dictionary;

// Declaring the Functions that will be used
void loadingAnimation(), AddToMap(string Method_Used, string retVal, string stack_content),
    Push(string value), Pop(), MainMenu(), DisplayTable(), size(), isEmpty(), top();

string AskValue();

int main() {
    system("chcp 65001"); // To enable the reading of broader ascii chars
    system("cls");
    cout << "\t\t\t══════════════════════════════════════════════════════════════\n\n";
    cout << setw(5) << left << "\t\t\t "
         << setw(40) << left << "\t\t\tSET OPERATIONS"
         << setw(5) << left << "\n " << endl;
    cout << setw(5) << left << "\t\t\t "
         << setw(40) << left << "\t\tShawn Michael Sudaria | BSIT 2B"
         << setw(5) << left << "\n " << endl;
    cout << "\t\t\t══════════════════════════════════════════════════════════════\n";
    MainMenu();
}

void loadingAnimation() {
    for (int i = 1; i <= 3; i++) {
        printf("-");
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
    printf("\t\t\t[1] Push()\n\t\t\t[2] Pop()\n\t\t\t[3] Size()\n\t\t\t[4] isEmpty()\n\t\t\t[5] Top()\n\t\t\t[6] Exit\n\n");
    printf("\t\t\tOPTION: ");
    scanf("%d", &userOption);
    if (userOption < 1 || userOption > 6) {
        printf("\t\t\tNumber must be within the options!!\n");
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
        size();
        break;
    case 4:
        isEmpty();
        break;
    case 5:
        top();
        break;
    case 6:
        printf("\t\t\tGoodbye!!.....");
        loadingAnimation();
        exit(0);
        break;
    default:
        break;
    }
}

string AskValue() {
    string input;
    printf("\t\t\tNumber to Push: ");
    cin >> input;
    return input;
}

void AddToMap(string Method_Used, string retVal, string stack_content) {

    dictionary[counter] = {
        Method_Used,
        retVal,
        stack_content};
    counter++;
}

void DisplayTable() {
    system("cls");
    cout << "\t\t\t╔═════════════╦══════════════╦══════════════════════════╗" << endl;
    cout << setw(15) << left << "\t\t\t║ Method Used ║"
         << setw(1) << left << " "
         << setw(15) << left << "Return Value ║"
         << setw(1) << left << " "
         << setw(25) << left << "Stack Content"
         << setw(1) << left << "║" << endl;
    cout << "\t\t\t╠═════════════╬══════════════╬══════════════════════════╣" << endl;

    for (int i = 0; i < counter; i++) {
        cout << setw(1) << left << "\t\t\t║ "
             << setw(12) << left << dictionary[i][0]
             << setw(1) << left << "║ "
             << setw(13) << left << dictionary[i][1]
             << setw(1) << left << "║ "
             << setw(25) << left << dictionary[i][2]
             << setw(1) << left << "║" << endl;
    }
    cout << "\t\t\t╚═════════════╩══════════════╩══════════════════════════╝" << endl;
}

// OPERATIONS

void top() {
    string combined;                // To hold all the array elements in a single string separeted by spaces
    for (int i = 0; i < Top; i++) { // Para mag iterate over every element ha Arr na array
        combined += Arr[i] + " ";
    }
    AddToMap("Top()", Arr[Top - 1], combined);
    DisplayTable();
    MainMenu();
}

void size() {
    string combined;
    for (int i = 0; i < Top; i++) {
        combined += Arr[i] + " ";
    }
    AddToMap("Size()", to_string(Top), combined);
    DisplayTable();
    MainMenu();
}

void isEmpty() {
    if (Top == 0) {
        AddToMap("isEmpty()", "TRUE", " ");
    } else {
        string combined;
        for (int i = 0; i < Top; i++) {
            combined += Arr[i] + " ";
        }
        AddToMap("isEmpty()", "FALSE", combined);
    }

    DisplayTable();
    MainMenu();
}

void Push(string value) {
    Top++;
    Arr[Top - 1] = value;
    string combined;                // To hold all the array elements in a single string separeted by spaces
    for (int i = 0; i < Top; i++) { // Para mag iterate over every element ha Arr na array
        combined += Arr[i] + " ";
    }

    AddToMap("Push()", "-", combined);
    DisplayTable();
    MainMenu();
}

void Pop() {
    string combined;
    for (int i = 0; i < Top - 1; i++) { // Para mag iterate over every element ha Arr na array
        combined += Arr[i] + " ";
    }
    if (Top > 0) {
        string poped_value = Arr[Top - 1];
        Top--;
        AddToMap("Pop()", poped_value, combined);
    } else {
        AddToMap("Pop()", "NULL", combined);
    }

    DisplayTable();
    MainMenu();
}
