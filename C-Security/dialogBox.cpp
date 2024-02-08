#include <iostream>
#include <windows.h>
#include <winuser.h>

using namespace std;

int main() {
    int msgBox = MessageBox(
        NULL,
        "You have been pwned",
        "THIS IS A UNSAFE PROGRAM",
        MB_ICONWARNING | MB_YESNO);

    if (msgBox == IDYES) {
        for (int i = 0; i < 10; i++) {
            MessageBox(NULL, "HALA KA MAY VIRUS IM LAPTOP", "May klase buwas?", MB_ICONWARNING);
        }
    }else if (msgBox == IDNO) {
        for(int i = 0; i < 30; i++){
          MessageBox(NULL, "NA VIRUSAN NA IM LAPPY", "HEHEHEHEH", MB_ICONWARNING);
        }
    }
    return 0;
}
