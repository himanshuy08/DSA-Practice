#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 5; // Example number
    int k = 2; // Example bit position to check

    // Check if the k-th bit is set
    if (n & (1 << k)) {
        cout << "The " << k << "-th bit is set in " << n << endl;
    } else {
        cout << "The " << k << "-th bit is not set in " << n << endl;
    }

    // Set the k-th bit
    n |= (1 << k);
    cout << "After setting the " << k << "-th bit, n = " << n << endl;

    // Clear the k-th bit
    n &= ~(1 << k);
    cout << "After clearing the " << k << "-th bit, n = " << n << endl;

    // Toggle the k-th bit
    n ^= (1 << k);
    cout << "After toggling the " << k << "-th bit, n = " << n << endl;

    // Count the number of set bits
    int count = __builtin_popcount(n);
    cout << "Number of set bits in " << n << " is " << count << endl;

    // Check if a number is a power of two
    if (n && !(n & (n - 1))) {
        cout << n << " is a power of two." << endl;
    } else {
        cout << n << " is not a power of two." << endl;
    }

    // Find the position of the rightmost set bit
    int pos = 0;
    if (n) {
        pos = __builtin_ctz(n);
        cout << "The position of the rightmost set bit in " << n << " is " << pos << endl;
    } else {
        cout << n << " has no set bits." << endl;
    }

    // Reverse bits of a number
    int reversed = 0;
    for (int i = 0; i < sizeof(n) * 8; ++i) {
        if (n & (1 << i)) {
            reversed |= (1 << (sizeof(n) * 8 - 1 - i));
        }
    }

    cout << "Reversed bits of " << n << " is " << reversed << endl;



    return 0;
}