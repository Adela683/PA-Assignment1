#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin("servere.in");
ofstream fout("servere.out");

double min1(vector<int> &C, vector<int> &P, int n) {
    vector<double> min1;
    for (int i = 0; i < n; i++) {
        min1.push_back(C[i] - P[i]);
    }

    // maximul din vectorul de diferente
    double max = min1[0];
    for (int i = 1; i < n; i++) {
        if (min1[i] > max) {
            max = min1[i];
        }
    }

    return max;
}

double min2(vector<int> &C, vector<int> &P, int n) {
    vector<double> min2;
    for (int i = 0; i < n; i++) {
        min2.push_back(C[i] + P[i]);
    }

    // minimul din vectorul de sume
    double min = min2[0];
    for (int i = 1; i < n; i++) {
        if (min2[i] < min) {
            min = min2[i];
        }
    }

    return min;
}

double gasestePutereMaxima(vector<int> &C, vector<int> &P, int n) {
    // puterea de alimentare
    double alimentare = (min1(C, P, n) + min2(C, P, n)) / 2;
    vector<double> putere;
    for (int i = 0; i < n; i++) {
        // puterile individuale
        putere.push_back(P[i] - abs(alimentare - C[i]));
    }

    // minimul din vectorul de puteri individuale
    double min = putere[0];
    for (int i = 1; i < n; i++) {
        if (putere[i] < min) {
            min = putere[i];
        }
    }

    return min;
}

int main() {
    int n;
    vector<int> P, C;

    fin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        fin >> x;
        P.push_back(x);
    }

    for (int i = 0; i < n; ++i) {
        int x;
        fin >> x;
        C.push_back(x);
    }

    fout << fixed << setprecision(1) << gasestePutereMaxima(C, P, n) << endl;

    return 0;
}
