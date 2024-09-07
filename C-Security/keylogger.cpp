#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <ncurses.h>
#include <fstream>
using namespace std;

int keys(char key, fstream&);

int main() {
    char key_press;
    int ascii_value;
    fstream afile;
    afile.open("key.txt", ios::in | ios::out);
    afile.close();


    while(true){
        key_press = getch();
        ascii_value = key_press;
        printf("The key pressed %d", ascii_value);
    }
    return 0;
}