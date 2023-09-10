#include <iostream>
using namespace std;
int main() {
    int N, NUM1, SMALL, COUNT;

    // Step 1: Input the number of integers to compare an N
    cout << "Enter the number of integers to compare N: ";
    cin >> N;

    // Step 2: Input the first integer an NUM1
    cout << "Enter the first integer NUM1: ";
    cin >> NUM1;

    // Step 3: Initialize SMALL and COUNT
    SMALL = NUM1;
    COUNT = 2; // DD ko na gin set COUNT TO 2.

    // Step 4: Loop to compare integers
    while (COUNT <= N) {
        int nextNum;
        // Input the next integer
        cout << "Enter integer #" << COUNT << ": ";
        cin >> nextNum;
        // Step 5: Compare NUM1 with SMALL and update SMALL if needed
        if (nextNum < SMALL) {
            SMALL = nextNum;
        }
        // Step 6: Increment COUNT
        COUNT++;
        // Step 7: Return to step
    }
    // Step 8: Ig display la an value han SMALL. Optional la ine na step
    cout << "The smallest integer is: " << SMALL << endl;

    return 0;
}
