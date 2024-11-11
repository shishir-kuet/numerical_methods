#include <bits/stdc++.h>

using namespace std;

void gauss_eli(vector<vector<double>>& mat){
    int n = mat.size();

    for(int k = 0; k<n-1; k++){
        // row swapping
        int maxRow = k;
        for (int i = k + 1; i < n; i++) {
            if (abs(mat[i][k]) > abs(mat[maxRow][k])) {
            maxRow = i;
            }
        }
        if(mat[maxRow][k] == 0){
            cout << "No unique solution exists" << endl;
            exit(0);
        }

        if (maxRow != k) {
            swap(mat[k], mat[maxRow]);
        }

        for(int r = n-1; r>k; r--){
            double fA = mat[r][k];
            double fB = mat[r-1][k];

            for(int c = 0; c<n+1; c++){
                if(c == k)
                    mat[r][c] = 0;
                else
                    mat[r][c] = mat[r][c] * fB - mat[r-1][c] * fA;
            }

        }
    }
}

void jordan_eli(vector<vector<double>>& mat){
    int n = mat.size();

    for(int k = n-1; k>0; k--){
        for(int r = 0; r<k; r++){
            double fA = mat[r][k];
            double fB = mat[r+1][k];

            for(int c = 0; c<n+1; c++){
                mat[r][c] = mat[r][c] * fB - mat[r+1][c] * fA;
            }

        }
    }
}

void row_ech2(vector<vector<double>>& mat){
    
    int n = mat.size();

    for(int i = 0; i<n; i++){
        mat[i][n] = mat[i][n] / mat[i][i];
        mat[i][i] = 1;
    }
}

void row_ech(vector<vector<double>>& mat){
    
    int n = mat.size();

    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            mat[i][n] -= mat[i][j] * mat[j][n];
        }
        mat[i][n] /= mat[i][i];
        // mat[i][i] = 1;
    }

}

void printMat(vector<vector<double>>& mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            if (abs(mat[i][j]) < 1e-5)
                mat[i][j] = 0;
            cout << setw(4) << mat[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    vector<vector<double>> mat = {
        {1, 1, -1, 7},
        {1, -1, 2, 3},
        {2, 1, 1, 9},
    };
    vector<vector<double>> mat2 = {
        {1, 1, -1, 7},
        {1, -1, 2, 3},
        {2, 1, 1, 9},
    };

    gauss_eli(mat);
    printMat(mat);
    row_ech(mat);
    printMat(mat);

    cout << "--------------------" << endl;

    gauss_eli(mat2);
    printMat(mat2);
    jordan_eli(mat2);
    printMat(mat2);
    row_ech2(mat2);
    printMat(mat2);

}