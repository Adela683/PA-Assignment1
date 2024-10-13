#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ifstream fin("compresie.in");
ofstream fout("compresie.out");

int suma_elem_vector(vector<int> &v, int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += v[i];
    }
    return suma;
}

int main() {
    int n, m, i, j;
    fin >> n;

    vector<int> A(n, 0);

    int max_length = 0;

    for (int i = 0; i < n; ++i) {
        fin >> A[i];
    }

    fin >> m;
    vector<int> B(m, 0);
    for (int i = 0; i < m; ++i) {
        fin >> B[i];
    }

    i = 0;
    j = 0;

    if (suma_elem_vector(A, n) != suma_elem_vector(B, m)) {
        fout << "-1";
    } else {
        while (i < n && j < m) {
            if (A[i] < B[j]) {
                A[i + 1] += A[i];
                i++;
            } else if (A[i] > B[j]) {
                B[j + 1] += B[j];
                j++;
            } else {
                max_length++;
                i++;
                j++;
            }
        }
        fout << max_length;
    }

    return 0;
}
