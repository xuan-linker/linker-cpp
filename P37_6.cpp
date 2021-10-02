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
    for (int i = 5; i < 10; ++i) {
        Linklist node = new LNode();
        node->data = i;
        node->next = NULL;
        tempL->next = node;
        tempL = tempL->next;
    }
    for (int i = 1; i < 3; ++i) {
        Linklist node = new LNode();
        node->data = i;
        node->next = NULL;
        tempL->next = node;
        tempL = tempL->next;
    }
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


// 元素递增有序
// 循环1 迭代原链表
// 循环2 按照从小到大顺序 插入新的head 链表中
bool sort(Linklist &L) {
    if (!L) {
        return false;
    }
    Linklist head = new LNode();
    Linklist tempL = L;
    while (tempL && tempL->next != NULL) {
        Linklist node = new LNode();
        node->data = tempL->next->data;
        Linklist tempHead = head;
        while (tempHead->next != NULL && tempHead->next->data < node->data) {
            tempHead = tempHead->next;
        }
        node->next = tempHead->next;
        tempHead->next = node;

        tempL = tempL->next;
    }

    L = head;
    return true;

}

int main() {
    cout << "Hello world" << endl;

    Linklist L = new LNode();
    L->next == NULL;
    InsertLNode(L);
    Print(L);

    sort(L);
    Print(L);
    return 0;
}