#include <iostream>
#include <vector>
#include <string>

using namespace std;

void computeLPSArray(const string& pat, int M, vector<int>& lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
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

int KMPSearch(const string& pat, const string& txt) {
    int M = pat.length();
    int N = txt.length();
    vector<int> lps(M);
    computeLPSArray(pat, M, lps);
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            count++;
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return count;
}

int main() {
    string pat, txt;
    getline(cin, pat);
    getline(cin, txt);
    cout << KMPSearch(pat, txt) << endl;
    return 0;
}