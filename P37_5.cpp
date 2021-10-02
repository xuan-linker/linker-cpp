//
// Created by Linker on 10/2/2021.
//

#include "iostream"

using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *Linklist;


bool InsertLNode(Linklist &L) {
    Linklist tempL = L;
    for (int i = 1; i < 10; ++i) {
        Linklist node = new LNode();
        node->data = i;
        node->next = NULL;
        tempL->next = node;
        tempL = tempL->next;
    }
//    for (int i = 2; i < 5; ++i) {
//        Linklist node = new LNode();
//        node->data = i;
//        node->next = NULL;
//        tempL->next = node;
//        tempL = tempL->next;
//    }
    return true;
}

//空间复杂度O（1） 反转 链表
bool reversionLinklist(Linklist &L) {
    Linklist head = new LNode();
    Linklist tempL = L;
    while (tempL && tempL->next != NULL) {
        //注意引用和新建赋值的区别
        Linklist node = new LNode();
        node->data = tempL->next->data;
        node->next = head->next;
        head->next = node;

        tempL = tempL->next;
    }
    L = head;
    return true;
}

void Print(Linklist &L) {
    Linklist tempL = L;
    while (tempL->next != NULL) {
        cout << tempL->next->data << ends;
        tempL = tempL->next;
    }
    cout << endl;
}

int main() {
    cout << "Hello world" << endl;

    Linklist L = new LNode();
    L->next == NULL;
    InsertLNode(L);
    Print(L);

    reversionLinklist(L);
    Print(L);
    return 0;
}