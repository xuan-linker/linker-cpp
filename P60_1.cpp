//
// Created by Linker on 10/6/2021.
//

#include "iostream"

using namespace std;
#define MaxSize 50
typedef struct {
    int data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack &S) {
    S.top = -1;
}

bool StackEmpty(SqStack S) {
    if (S.top == -1) {
        return true;
    }
    return false;
}

bool Push(SqStack &S, int x) {
    if (S.top == MaxSize - 1) {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, int &x) {
    if (S.top == -1) {
        return false;
    }
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack &S, int &x) {
    if (S.top == -1) {
        return false;
    }
    x = S.data[S.top];
    return true;
}

//void DestroyStack(SqStack &S) {
//}
int Size(SqStack &S) {
    return S.top + 1;
}

void Print(SqStack S) {
    for (int i = 0; i <= S.top; ++i) {
        cout << S.data[i] << ends;
    }
    cout << endl;
}


int main() {
    cout << "hello world" << endl;
    SqStack S;
    InitStack(S);
    bool res = StackEmpty(S);
    cout << res << endl;
    Print(S);
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Print(S);
    int x;
    Pop(S, x);
    cout << x << endl;
    Print(S);
    GetTop(S,x);
    cout << x << endl;
    Print(S);
    int size = Size(S);
    cout<<size<<endl;
    return 0;
}
