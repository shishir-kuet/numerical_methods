#include <bits/stdc++.h>
using namespace std;


double f(double x, double y) {
    return 3*x-y;
}

void runge_kutta() {
    double a, b, h, x, y;
    vector<double> X,Y;
    cin >> a >> b >> h >> y;
    x = a;
    X.push_back(x);
    Y.push_back(y);

    while(x < b && fabs(x - b) > 1e-9) {
        double m1 = f(x,y);
        double m2 = f(x+0.5*h, y+0.5*m1*h);
        double m3 = f(x+0.5*h, y+0.5*m2*h);
        double m4 = f(x+h, y+m3*h);
        y += (m1+2*m2+2*m3+m4)*h/6;
        x+=h;
        X.push_back(x);
        Y.push_back(y);
    }
    cout << "x : " << endl;
    for(auto i : X) {
        cout << i << " ";
    }
    
    cout << endl;

    cout << "y : " << endl;
    for(auto i : Y) {
        cout << i << " ";
    }
}

int main() {
    runge_kutta();

    return 0;
}