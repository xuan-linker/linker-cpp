//
// Created by Linker on 10/2/2021.
// 双链表
//

#include "iostream"

using namespace std;

typedef struct DNode {
    int data;
    struct DNode *prior, *next; //前驱和后继指针
} DNode, *DLinklist; // 存在问题

int main() {
    cout << "hello world" << endl;
    return 0;
}
