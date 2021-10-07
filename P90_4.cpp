//
// Created by Linker on 10/6/2021.
//

#include "iostream"
#include "stack"

using namespace std;

void Clean(stack<int> &s) {
    while (!s.empty()) {
        s.pop();
    }
}
void Print(stack<int> stack){
    while (!stack.empty()){
        int x = stack.top();
        stack.pop();
        cout<<x<<ends;
    }
    cout<<endl;
}

int main() {
    cout << "hello world" << endl;
    //s1 客车，s2，货车
    stack<int> s, s1, s2;
    //init
    for (int i = 0; i < 20; ++i) {
        s1.push(1);
    }
    for (int i = 0; i < 3; ++i) {
        s2.push(2);
    }
    int count = 0;
    int count1 = 0, count2 = 0;

    while (s1.size() > 0 && s2.size() > 0) {
        if (count == 10) {
            count1 = 0;
            count2 = 0;
            count = 0;
        }
        if (count1 < 4) {
            int x = s1.top();
            s.push(x);
            s1.pop();
            count1++;
            count++;
        } else if (count1 == 4) {
            int x = s2.top();
            s2.pop();
            s.push(x);
            count2++;
            count1 = 0;
            count++;
        }
    }
    if (s1.empty() && !s2.empty()) {
        while (!s2.empty()) {
            int x = s2.top();
            s2.pop();
            s.push(x);
        }
    } else if (!s1.empty() && s2.empty()) {
        while (!s1.empty()) {
            int x = s1.top();
            s1.pop();
            s.push(x);
        }
    } else if (s1.empty() && s2.empty()) {
        //ok
    }
    Print(s);
    return 0;
}