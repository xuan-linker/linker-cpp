//
// Created by linker on 2021/10/6.
//

#include "iostream"

using namespace std;

#define MaxSize 50
typedef struct {
    int data[MaxSize];
    int top1 = -1;
    int top2 = MaxSize;
} Stack;

//full top1+top2-1 == MaxSize
void Print(Stack S) {
    for (int i = 0; i <= S.top1; ++i) {
        cout << S.data[i] << ends;
    }
    cout << endl;
    for (int i = MaxSize - 1; i >= S.top2; --i) {
        cout << S.data[i] << ends;
    }
    cout << endl;
}

//i=1,top1 ; i=2,top2
bool Push(Stack &S, int i, int x) {
    if (S.top2 - S.top1 - 1 > MaxSize) {
        return false;
    }
    if (i == 1) {
        S.data[++S.top1] = x;
    } else if (i == 2) {
        S.data[--S.top2] = x;
    } else if (i != 1 && i != 2) {
        return false;
    }
    return true;
}

//i=1,top1 ; i=2,top2
bool Pop(Stack &S, int i, int &x) {
    if (i != 1 && i != 2) {
        return false;
    }
    if (i == 1) {
        if (S.top1 == -1) {
            return false;
        }
    } else if (i == 2) {
        if (S.top2 == MaxSize) {
            return false;
        }
    }
    if (i == 1) {
        x = S.data[S.top1--];
    } else if (i == 2) {
        x = S.data[S.top2++];
    }
    return true;
}

int main() {
    cout << "hello world" << endl;
    Stack S;
    Push(S, 1, 1);
    Push(S, 1, 2);
    Print(S);

    Push(S, 2, 3);
    Push(S, 2, 4);
    Print(S);
    int x;
//    Pop(S, 1, x);
//    cout << x << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    Print(S);
    Pop(S, 2, x);
    cout << x << endl;
    Print(S);

    Pop(S, 2, x);
    cout << x << endl;
    Print(S);

    return 0;
}