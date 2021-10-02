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


bool DeleteMid(Linklist &L, int left, int right) {
    Linklist tempL = L;
    while (tempL && tempL->next != NULL) {
        if (tempL->next->data >= left && tempL->next->data <= right) {
            tempL->next = tempL->next->next;
        } else {
            //注意 next 删除 和 next迭代 （else）
            tempL = tempL->next;
        }
    }
    return true;
}

int main() {
    cout << "Hello world" << endl;

    Linklist L = new LNode();
    L->next == NULL;
    InsertLNode(L);
    Print(L);

    DeleteMid(L, 6, 8);
    Print(L);
    return 0;
}