#include<iostream>
using namespace std;

// Function to generate prime numbers using the Sieve of Eratosthenes
void sieveOfEratosthenes(int n) {
    int prime[n + 1];
    for (int i = 0; i <= n; i++) {
        prime[i] = 1; // Initialize all numbers as prime
    }
    prime[0] = prime[1] = 0; // 0 and 1 are not prime numbers
    for (int p = 2; p <= n; p++) {
        if (prime[p]) { // If prime[p] is still true
            for (int i = p * p; i <= n; i += p) {
                prime[i] = 0; // Mark all multiples of p as not prime
            }
        }
    }

    // Print all prime numbers
    cout << "Prime numbers up to " << n << " are: ";
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            cout << p << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the upper limit for prime numbers: ";
    cin >> n;

    sieveOfEratosthenes(n);

    return 0;
}