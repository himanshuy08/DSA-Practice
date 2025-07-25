#include<iostream>
#include<vector>
using namespace std;
// KMP Algorithm for Pattern Searching

void computeLPSArray(string pat, vector<int>& lps) {
    int len = 0; // length of previous longest prefix suffix
    lps[0] = 0; // lps[0] is always 0
    int i = 1;

    while (i < pat.length()) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string pat, string txt) {
    int M = pat.length();
    int N = txt.length();

    vector<int> lps(M);
    computeLPSArray(pat, lps);

    int i = 0; // index for txt
    int j = 0; // index for pat
    while (i < N) {
        if (pat[j] == txt[i]) {
            i++; 
            j++;
        }

        if (j == M) {
            cout << "Found pattern at index " << i - j << endl;
            j = lps[j - 1]; // Get the next character to compare
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1]; // Move to the next character in the pattern
            } else {
                i++;
            }
        }
    }
}

int main() {
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}
