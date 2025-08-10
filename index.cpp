#include <bits/stdc++.h>
using namespace std;

//Kmp Function to build the LPS (Longest Prefix Suffix) array
void computeLPSArray(string pattern, vector<int>& lps) {
    int len = 0; // length of the previous longest prefix suffix
    lps[0] = 0;  // LPS of the first character is always 0
    int i = 1;

    while (i < pattern.size()) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
                // no increment of i here
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP search function
void KMPSearch(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();

    vector<int> lps(m);
    computeLPSArray(pattern, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << (i - j) << "\n";
            j = lps[j - 1]; // move to previous possible match
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    KMPSearch(text, pattern);

    return 0;
}
