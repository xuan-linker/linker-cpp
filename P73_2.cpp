//
// Created by linker on 2021/10/6.
// 循环队列 2.增设size

#include "iostream"

using namespace std;
#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int front, rear; //队头指针和队尾指针
    int size;
} SqQueue;

void InitQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;
    Q.size = 0;
}

bool QueueEmpty(SqQueue &Q) {
    if (Q.front == Q.rear && Q.size == 0) {
        return true;
    } else {
        return false;
    }
}

bool QueueFull(SqQueue &Q) {
    if (Q.size == MaxSize) {
        return true;
    } else {
        return false;
    }
}

bool EnQueue(SqQueue &Q, int x) {
    if (QueueFull(Q)) {
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.size++;
    return true;
}

bool DeQueue(SqQueue &Q, int &x) {
    if (QueueEmpty(Q)) {
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    Q.size--;
    return true;
}

bool GetHead(SqQueue Q, int &x) {
    if (QueueEmpty(Q)) {
        return false;
    }
    x = Q.data[Q.front];
    return true;
}

void Print(SqQueue Q) {
    for (int i = Q.front; i < Q.rear + Q.size; ++i) {
        cout << Q.data[i % MaxSize] << ends;
    }
    cout << endl;
}

int main() {
    cout << "hello world" << endl;
    SqQueue Q;
    InitQueue(Q);

    Print(Q);
    bool empty = QueueEmpty(Q);
    cout << empty << endl;

    for (int i = 0; i < 100; ++i) {
        EnQueue(Q, i);
    }
    int x;
    GetHead(Q, x);
    cout << x << endl;
    Print(Q);
    for (int i = 0; i < 100; ++i) {
        int x = 0;
        bool flag = DeQueue(Q, x);
        if (flag) {
            cout << x << ends;
        }
    }

    return 0;
}