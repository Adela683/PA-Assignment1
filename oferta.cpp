#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin("oferta.in");
ofstream fout("oferta.out");

double find_minim(vector<int> &prices, int n) {
    // vectorul in care stochez costul minim pentru fiecare pas
    vector<double> min_cost(n, 0);
    for (int i = 0; i < n; ++i) {
        min_cost[i] = min_cost[i - 1] + prices[i];
        // verific daca putem obtine un cost mai mic daca cumparam 2 produse
        if (i >= 1) {
            double min_price = min(prices[i - 1], prices[i]);
            min_cost[i] = min(min_cost[i],
                              min_cost[i - 2] + prices[i - 1] + prices[i]
                                - min_price * 0.5);
        }
        // verific daca putem obtine un cost mai mic daca cumparam 3 produse
        if (i >= 2) {
            double min_price = min(prices[i],
                                   min(prices[i - 1], prices[i - 2]));
            min_cost[i] = min(min_cost[i],
                              min_cost[i - 3] + prices[i - 1] +
                            prices[i - 2] + prices[i] - min_price);
        }
    }

    return min_cost[n - 1];
}

int main() {
    int n, k;
    vector<int> price;
    fin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        fin >> x;
        price.push_back(x);
    }

    fout << fixed << setprecision(1) << find_minim(price, n) << endl;

    return 0;
}
