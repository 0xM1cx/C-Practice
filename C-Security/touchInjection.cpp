#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <winuser.h>

int main() {

    BOOL test = InitializeTouchInjection();
    return 0;
}