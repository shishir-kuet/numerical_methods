#include <bits/stdc++.h>
using namespace std;

double f(double x, double A, double B, double C) {
    return A*pow(x, 2) + B*x + C;
}

double df(double x, double A, double B, double C) {
    return 2*A*x + B;
}

void Newton(double A, double B, double C) {
    double x = 0, pre_x = 4, f_pre_x, df_pre_x;
    int count = 0;
    vector<double> data;
    double res;
    int iteration;
    bool gotResult = false;
    
    while (count < 20) {
        ++count;
        data.push_back(f(pre_x,A,B,C));

        f_pre_x = f(pre_x, A, B, C);
        if (abs(f_pre_x) < 0.0001 && gotResult == false) {
            res = pre_x;
            iteration = count;
            gotResult = true;
        }

        df_pre_x = df(pre_x, A, B, C);
        if (df_pre_x == 0) {
            cout << "Can't be calculated. derivative is zero!" << endl;
            return;
        }

        x = pre_x - f_pre_x / df_pre_x;
        pre_x = x;
        
    }
    cout << "Result: " << res << "  Iterations: " <<iteration << endl;
    for(auto it:data) {
        cout << it << " ";
    }
    
}

void Secant(double A, double B, double C) {
    double x=0, a=5, b=10, res, f_x, f_a, f_b;
    vector<double> data;
    int iteration;
    bool gotResult = false;

    int count = 0;
    while(count < 20) {
        ++count; 

        f_a = f(a,A,B,C);
        f_b = f(b,A,B,C);
        if(abs(f_a-f_b) < 1e-10) {
            data.push_back(0);
            continue;
        }

        x = b-(f_b*(b-a))/(f_b-f_a);
        f_x = f(x,A,B,C);
        data.push_back(f_x);

        if(abs(f_x) < 0.0001 && gotResult == false) {
            res = x;
            iteration = count;
            gotResult = true;
        }
        a = b;
        b = x;
    }
    cout << "Result: " << res << "  Iterations: " <<iteration << endl;
    for(auto it:data) {
        cout << it << " ";
    }
    
}

int main() {
    double A, B, C;
    cin >> A >> B >> C;
    Newton(A, B, C);
    cout <<endl;
    Secant(A,B,C);

    return 0;
}