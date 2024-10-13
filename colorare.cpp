#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin("colorare.in");
ofstream fout("colorare.out");

const int MOD = 1000000007;

long long power(long long a, long long b) {
    // functie care calculeaza a^b(pentru bonus)
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    struct pereche {
        int X;
        char T;
    };

    int n;

    fin >> n;
    vector<pereche> v(n);
    for (int i = 0; i < n; i++) {
        fin >> v[i].X;
        fin >> v[i].T;
    }

    vector<long long> dp(n + 1, 0);

    if (v[0].T == 'H') {
        dp[0] = 6;
        dp[0] = (dp[0] * power(3, v[0].X - 1)) % MOD;
    } else {
        dp[0] = 3;
        dp[0] = (dp[0] * power(2, v[0].X - 1)) % MOD;
    }

    for (int i = 1; i < n; i++) {
        if (v[i].T == 'H') {
            if (v[i - 1].T == 'V') {
                dp[i] = (dp[i - 1] * 2) % MOD;
            } else {
                dp[i] = (dp[i - 1] * 3) % MOD;
            }

            dp[i] = (dp[i] * power(3, v[i].X - 1)) % MOD;

        } else {
            if (v[i - 1].T == 'H') {
                dp[i] = dp[i - 1] % MOD;
            } else {
                dp[i] = (dp[i - 1] * 2) % MOD;
            }
            dp[i] = (dp[i] * power(2, v[i].X - 1)) % MOD;
        }
    }

    fout << dp[n - 1];

    return 0;
}
