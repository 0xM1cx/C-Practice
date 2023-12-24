#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string input;
    fstream inputFile("./input.txt");

    string numbers = "0123456789";

    int counter = 0;
    vector<string> digitPair = [];
    bool flag = true;
    while (getline(inputFile, input)) {
        flag = true;
        char firstDigit;
        char secondDigit;
        for (int i = 0; i < input.size() && flag == true; i++) {
            for (char c : numbers) {
                if (c == input[i]) {
                    firstDigit = input[i];
                    flag = false;
                    break;
                }
            }
        }
        flag = true;

        for (int size = input.size() - 1; size > 0 && flag == true; size--) {
            for (char c : numbers) {
                if (c == input[size]) {
                    secondDigit = input[i];
                    flag = false;
                    break;
                }
            }
        }

        string combined(1, firstDigit);
        combined += secondDigit;
        digitPair[counter] = combined;
        counter++;
    }

    for (string s : digitPair) {
        cout << s;
    }

    return 0;
}