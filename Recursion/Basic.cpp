#include<iostream>
#include<string>
using namespace std;
// Function to print 1 to n using recursion

void print1ToN(int n) {
    // Base case
    if (n == 0) {
        return;
    }
    // Recursive call
    print1ToN(n - 1);
    // Print after the recursive call to ensure order
    cout << n << " ";
}

// Function to print n to 1 using recursion
void printNTo1(int n) {
    // Base case
    if (n == 0) {
        return;
    }
    // Print before the recursive call to ensure order
    cout << n << " ";
    // Recursive call
    printNTo1(n - 1);
}

// Function to print factorial of a number using recursion
int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

// Function to sum of first n natural numbers using recursion
int sumOfN(int n) {
    if (n == 0) return 0;
    return n + sumOfN(n - 1);
}

// Function to calculate nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to reverse a number using recursion
int reverseNumber(int n, int rev = 0) {
    if (n == 0) return rev;
    return reverseNumber(n / 10, rev * 10 + n % 10);
}


int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Numbers from 1 to " << n << ": ";
    print1ToN(n);
    cout << endl;
    cout << "Numbers from " << n << " to 1: ";
    printNTo1(n);
    cout << endl;
    cout << "Factorial of " << n << " is: "; // this will overflow for large n 
    cout << factorial(n) << endl;
    cout << "Sum of first " << n << " natural numbers is: ";
    cout << sumOfN(n) << endl;
    cout << "Fibonacci number at position " << n << " is: ";
    cout << fibonacci(n) << endl;
    cout << "Reverse of " << n << " is: ";
    cout << reverseNumber(n) << endl;
    return 0;
}