//
// Created by linker on 2021/10/6.
// 队列的链式存储
//

#include "iostream"

using namespace std;

typedef struct MyLinkNode {
    int data;
    struct MyLinkNode *next;
} MyLinkNode;
typedef struct {
    MyLinkNode *front, *rear;
} LinkQueue;

void Init(LinkQueue &Q) {
    Q.front = Q.rear = new MyLinkNode();
    Q.front->next = NULL;
}

bool IsEmpty(LinkQueue &Q) {
    if (Q.front == Q.rear) {
        return true;
    } else {
        return false;
    }
}

//在链尾插入
void EnQueue(LinkQueue &Q, int x) {
    MyLinkNode *node = new MyLinkNode();
    node->data = x;
    node->next = NULL;
    Q.rear->next = node;
    Q.rear = node;
}

bool DeQueue(LinkQueue &Q, int &x) {
    if (IsEmpty(Q)) {
        return false; // 判空
    }
    MyLinkNode *node = Q.front->next;
    x = node->data;
    Q.front->next = node->next;
    if (Q.rear == node) { //如果仅有一个节点
        Q.rear = Q.front;
    }
    free(node);
    return true;
}

void Print(LinkQueue Q) {
    if (IsEmpty(Q)){
        return;
    }
    while (Q.front->next != NULL) {
        cout << Q.front->next->data << ends;
        Q.front = Q.front->next;
    }
    cout << endl;
}

int main() {
    cout << "hello world" << endl;
    LinkQueue Q;
    Init(Q);
    Print(Q);
    for (int i = 0; i < 10; ++i) {
        EnQueue(Q, i);
    }
    Print(Q);
    for (int i = 0; i < 15; ++i) {
        int x = -1;
        bool res = DeQueue(Q, x);
        cout << res << " " << x << endl;
    }
    Print(Q);

    return 0;
}
