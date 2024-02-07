#include <iostream>
#include <windows.h>
#include <winuser.h>

using namespace std;
int main() {
    int msgBox = MessageBox(
        NULL,
        "You have been pwned",
        "THIS IS A SAFE PROGRAM",
        MB_ICONWARNING | MB_YESNO);

    if (msgBox == IDYES) {
        for (int i = 0; i < 10; i++) {
            MessageBox(NULL, "HALA KA MAY VIRUS IM LAPTOP", "May klase buwas?", MB_ICONWARNING);
        }
    }
    return 0;
}
