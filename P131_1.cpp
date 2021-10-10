//
// Created by linker on 2021/10/8.
//

#include "iostream"
#include "stack"
#include "queue"

using namespace std;
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

bool Init(BiTree &T) {
    T = NULL;
    return true;
}

//先序遍历
void Create(BiTree &T) {
    char c;
    cin >> c;
    if (c == '#') {
        T = NULL;
    } else {
        T = new BiTNode();

        T->data = c;
        Create(T->lchild);
        Create(T->rchild);
    }
}

void InOrderTraver(BiTree T) {
    if (T != NULL) {
        InOrderTraver(T->lchild);
        cout << T->data << ends;
        InOrderTraver(T->rchild);
    }
}

void InOrderTraver2(BiTree T) {
    stack<BiTree> stack;
    BiTree P = T;
    while (P || !stack.empty()) {
        if (P != NULL) {
            stack.push(P);
            P = P->lchild;
        } else {
            P = stack.top();
            stack.pop();
            cout << P->data << ends;
            P = P->rchild;
        }
    }
}

void PreOrderTraver2(BiTree T) {
    stack<BiTree> stack;
    BiTree P = T;
    while (P || !stack.empty()) {
        if (P) {
            cout << P->data << ends;
            stack.push(P);
            P = P->lchild;
        } else {
            P = stack.top();
            stack.pop();
            P = P->rchild;
        }
    }
}

void PostOrderTraver2(BiTree T) {
//    stack<BiTree> stack;
//    BiTree P = T;
//    while (P || !stack.empty()) {
//        if (P) {
//            stack.push(P);
//            P->lchild;
//        } else {
//            P = stack.top();
//            stack.pop();
//            P = P->rchild;
//            cout << P->data << ends;
//        }
//    }

}

void LevelOrder(BiTree T) {
    queue<BiTree> queue;
    BiTree P = T;
    queue.push(P);
    while (!queue.empty()) {
        P = queue.front();
        queue.pop();
        cout << P->data << ends;
        if (P->lchild != NULL) {
            queue.push(P->lchild);
        }
        if (P->rchild != NULL) {
            queue.push(P->rchild);
        }
    }

}

//ab#d##c##
int main() {
    cout << "hello world" << endl;
    BiTree T;
    Init(T);
    Create(T);
    InOrderTraver(T);
    cout << endl;
    InOrderTraver2(T);

    cout << endl;
    PreOrderTraver2(T);

    cout << endl;
    PostOrderTraver2(T);

    cout << endl;
    LevelOrder(T);

    return 0;
}