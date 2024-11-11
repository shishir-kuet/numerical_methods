#include <bits/stdc++.h>
using namespace std;


void find_ab(double A, double B, double C, double &a, double &b) {
    b = sqrt(pow(B/A,2)-2*C/A);
    a = -b;
}

double f(double x, double A, double B, double C) {
    return A*pow(x,2)+B*x+C;
}

void biSection(double A, double B, double C) {
    double dif, x=0, pre_x, a=0, b=0, res, f_x, f_a, f_b;
    vector<double> errors;

    find_ab(A, B, C, a, b);

    int count = 0;
    while(count < 21) {
        ++count; 
        pre_x = x;
        f_a = f(a,A,B,C);
        f_b = f(b,A,B,C);

        x = (a+b)/2;
        f_x = f(x,A,B,C);

        dif = abs(pre_x-x);
        if(count != 1) {
            errors.push_back(dif); 
            }

        if(abs(f_x) < 0.0001) {
            res = x;
        }
        if(f_x*f_a > 0) {
            a = x;
        }
        else b = x;    
    }
    cout << "Result: " << res << endl;
    cout << "Errors: ";
    for(auto error:errors) {
        cout << error << " ";
    }
    cout << endl;
}

void falsePosition(double A, double B, double C) {
    double dif, x=0, pre_x, a=0, b=0, res, f_x, f_a, f_b;
    vector<double> errors;

    find_ab(A, B, C, a, b);

    int count = 0;
    while(count < 21) {
        ++count; 
        pre_x = x;
        f_a = f(a,A,B,C);
        f_b = f(b,A,B,C);

        x = (a*f_b-b*f_a)/(f_b-f_a);
        f_x = f(x,A,B,C);

        dif = abs(pre_x-x);
        if(count != 1) {
            errors.push_back(dif); 
            }

        if(abs(f_x) < 0.0001) {
            res = x;
        }
        if(f_x*f_a > 0) {
            a = x;
        }
        else b = x;    
    }
    cout << "Result: " << res << endl;
    cout << "Errors: ";
    for(auto error:errors) {
        cout << error << " ";
    }
    cout << endl;
}

int main() {
    double A, B, C;
    cin >> A >> B >> C;
    cout << "\n\n";
    cout << "Bisection:" << endl;
    biSection(A,B,C);
    cout <<"\n";
    cout << "False Position:" << endl;
    falsePosition(A, B, C);

    return 0;
}