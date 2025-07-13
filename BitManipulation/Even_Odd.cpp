#include<iostream>
using namespace std;

// Function to check if a number is even or odd using bitwise operator
bool isEven(int n) {
    return (n & 1) == 0; // If the least significant bit is 0, it's even
}
bool isOdd(int n) {
    return (n & 1) == 1; // If the least significant bit is 1, it's odd
}
int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    if (isEven(num)) {
        cout << num << " is even." << endl;
    } else if (isOdd(num)) {
        cout << num << " is odd." << endl;
    } else {
        cout << "Invalid input." << endl;
    }

    return 0;
}
