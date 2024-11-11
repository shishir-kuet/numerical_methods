#include <bits/stdc++.h>
using namespace std;

vector<double> gaussElimin(vector<vector<double>>& a, vector<double>& b) {
    int n = b.size();

    // Elimination phase with partial pivoting
    for (int k = 0; k < n - 1; k++) {
        // Partial pivoting: Find the row with the largest absolute value in column k
        int maxIndex = k;
        for (int i = k + 1; i < n; i++) {
            if (abs(a[i][k]) > abs(a[maxIndex][k])) {
                maxIndex = i;
            }
        }

        // Swap rows if needed
        if (maxIndex != k) {
            swap(a[k], a[maxIndex]);
            swap(b[k], b[maxIndex]);
        }

        // Proceed with elimination if the pivot is non-zero
        if (a[k][k] != 0.0) {
            for (int i = k + 1; i < n; i++) {
                double lam = a[i][k] / a[k][k];
                for (int j = k + 1; j < n; j++) {
                    a[i][j] -= lam * a[k][j];
                }
                b[i] -= lam * b[k];
            }
        } else {
            cout << "Matrix is singular or nearly singular!" << endl;
            return vector<double>();
        }
    }

    // Back substitution
    for (int k = n - 1; k >= 0; k--) {
        for (int j = k + 1; j < n; j++) {
            b[k] -= a[k][j] * b[j];
        }
        b[k] /= a[k][k];
    }

    return b;
}

int main() {
    vector<vector<double>> a = {{0, 2, -1}, {1, -2, 3}, {4, 0, 5}};
    vector<double> b = {1, 2, 3};

    vector<double> result = gaussElimin(a, b);

    if (!result.empty()) {
        cout << "Solution: ";
        for (double x : result) {
            cout << x << " ";
        }
    }

    return 0;
}