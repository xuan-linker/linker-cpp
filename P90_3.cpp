//
// Created by Linker on 10/6/2021.
//

#include "iostream"
#include "stack"

using namespace std;

void PushAll(double n, stack<double> &s) {
    for (int i = n; i >= 2; --i) {
        s.push(i);
    }
}

double Cal(stack<double> s, double x) {
    double first = 1;//default n=0
    double next = x * 2;//default n=1
    while (!s.empty()) {
        int n = s.top();
        s.pop();
        double sum = 2 * x * next - 2 * (n - 1) * first;
        first = next;
        next = sum;
    }
    return next;
}

int main() {
    cout << "Hello world" << endl;
    stack<double> s;
    double x = 10;
    double n = 10;
    PushAll(n , s);
    double res = Cal(s, x);
    cout<<res<<endl;
    return 0;
}