#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin("criptat.in");
ofstream fout("criptat.out");

int maxlen(const vector<string>& words,
           int freq[][26], int n) {
    const int maxLen = 1e4 + 5;
    int rez = 0;

    // iterez prin toate literele
    for (char c = 'a'; c <= 'z'; ++c) {
        // convertesc caracterul la un indice
        int ch = c - 'a';
        int dp[maxLen] = {0};

        // parcurg toate cuvintele
        for (int j = 0; j < n; ++j) {
            int word_len = words[j].size();
            int remaining_len = maxLen - 1;
            // parcurg doar lungimile posibile
            while (remaining_len >= word_len) {
                // verific daca putem adauga frecventele literelor
                // din cuvantul curent
                if (dp[remaining_len - word_len] != 0 ||
                    remaining_len == word_len) {
                    dp[remaining_len] = max(dp[remaining_len],
                                            dp[remaining_len - word_len]
                                            + freq[j][ch]);
                }
                --remaining_len;
            }
        }

        // verific daca ideplineste conditia din enunt
        for (int L = 0; L < maxLen; ++L) {
            if (2 * dp[L] > L) {
                rez = max(rez, L);
            }
        }
    }

    return rez;
}

int main() {
    int n;
    fin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        fin >> words[i];
    }

    // initializez matricea de frecvente
    int freq[n][26];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 26; ++j)
            freq[i][j] = 0;

    // calculez frecventele literelor
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < words[i].size(); ++j) {
            freq[i][words[i][j] - 'a']++;
        }
    }

    fout << maxlen(words, freq, n);

    return 0;
}
