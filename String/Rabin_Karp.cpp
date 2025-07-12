#include<iostream>
#include<vector>
using namespace std;

// Rabin-Karp Algorithm for Pattern Searching
void RabinKarpSearch(string pat, string txt, int q) {
    int M = pat.length();
    int N = txt.length();
    int d = 256; // number of characters in the input alphabet
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (int i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (int i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (int i = 0; i <= N - M; i++) {
        // Check the hash values of current window of text and pattern.
        if (p == t) {
            // Check for characters one by one
            int j;
            for (j = 0; j < M; j++)
                if (txt[i + j] != pat[j])
                    break;

            if (j == M)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash value for next window of text: Remove leading digit,
        // add trailing digit
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            // We might get negative value of t, converting it to positive
            if (t < 0)
                t += q;
        }
    }
}

int main() {
    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEK";
    int q = 101; // A prime number

    RabinKarpSearch(pat, txt, q);
    return 0;
}

