//
// Created by linker on 2021/10/9.
//
#include "iostream"

typedef struct ThreadNode {
    int data; //数据元素
    struct ThreadNode *lchild, *rchild; //左、右孩子指针
    int ltag, rtag; //左、右线索标志
} ThreadNode, *TheadTree;

void InThread(ThreadTree &p, ThreadTree &pre) {
    if (p != NULL) {
        InThread(p)
    }
}

int main() {
    cout << "hello world" << endl;
    return 0;
}