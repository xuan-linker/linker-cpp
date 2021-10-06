//
// Created by linker on 2021/10/6.
//

#include "iostream"

using namespace std;

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
};
typedef struct SqQueue {
    LinkNode *front, *rear;
};

void Init(SqQueue &Q) {
    Q.front = Q.rear = new LinkNode();
    Q.rear->next = Q.front;
}

bool IsEmpty(SqQueue &Q) {
    if (Q.front == Q.rear) {
        return true;//空
    } else {
        return false;
    }
}

bool IsFull(SqQueue &Q) {
    if (Q.rear->next == Q.front) {
        return true;//满
    } else {
        return false;
    }
}

//入队
bool EnQueue(SqQueue &Q, int x) {
    if (IsFull(Q)) {
        LinkNode *node = new LinkNode();
        node->data = x;
        node->next = Q.front;
        Q.rear->next = node;
        Q.rear = Q.rear->next;
        return true;
    } else {
        Q.rear->data = x;
        Q.rear = Q.rear->next;
        return true;
    }
}

bool OutQueue(SqQueue &Q, int &x) {
    if (IsEmpty(Q)) {
        return false;
    }
    LinkNode *node = Q.front->next;
    x = node->data;
    Q.front = Q.front->next;
    if (node == Q.rear) {
        Q.front = Q.rear;
    }
    return true;
}

void Print(SqQueue Q) {
    if (IsEmpty(Q)) {
        return;
    }
    while (!IsEmpty(Q)) {
        cout << Q.front->next->data << ends;
        Q.front = Q.front->next;
    }
    cout << endl;
}

int main() {
    cout << "hello world" << endl;
    SqQueue Q;
    Init(Q);
    Print(Q);
    for (int i = 1; i < 10; ++i) {
        EnQueue(Q, i);
    }
    cout << endl;

    Print(Q);
    for (int i = 1; i < 15; ++i) {
        int x;
        bool flag = OutQueue(Q, x);
        if (flag == true) {
            cout << i << " " << x << ends;
        }
    }
    cout << endl;
    Print(Q);

    return 0;
}
