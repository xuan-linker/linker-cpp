//
// Created by linker on 2021/10/6.
//
#include "iostream"

using namespace std;
#define MaxSize 50

typedef struct Stack {
    int data[MaxSize];
    int top = -1;
};
typedef struct SqQueue {
    int data[MaxSize];
    int front = 0, rear = 0; //队头和队尾指针
    int size = 0;
};

bool EnSqQueue(SqQueue &Q, int x) {
    if (Q.size >= MaxSize) {
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.size++;
    return true;
}

bool OutSqQueue(SqQueue &Q, int &x) {
    if (Q.size <= 0) {
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    Q.size--;
    return true;
}

bool EnStack(Stack &S, int x) {
    if (S.top + 1 >= MaxSize) {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

bool OutStack(Stack &S, int &x) {
    if (S.top < 0) {
        return false;
    }
    x = S.data[S.top--];
    return true;
}

void Print(SqQueue Q) {
    for (int i = Q.front; i < Q.front + Q.size; ++i) {
        cout << Q.data[i % MaxSize] << ends;
    }
    cout << endl;
}

int main() {
    cout << "hello world" << endl;
    Stack S;
    SqQueue Q;
    for (int i = 0; i < 10; ++i) {
        EnSqQueue(Q, i);
    }
    Print(Q);

    int size = Q.size;
    for (int i = 0; i < size; ++i) {
        int x = -1;
        bool flag = OutSqQueue(Q, x);
        if (flag == true) {
            EnStack(S, x);
        }
    }
    for (int i = 0; i < size; ++i) {
        int x = -1;
        bool flag = OutStack(S, x);
        if (flag == true) {
            EnSqQueue(Q, x);
        }
    }
    Print(Q);


    return 0;
}

