//
// Created by Linker on 10/2/2021.
//

#include "iostream"

using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *Linklist;


bool InsertLNode1(Linklist &L) {
    Linklist tempL = L;
    for (int i = 1; i < 10; ++i) {
        Linklist node = new LNode();
        node->data = i;
        node->next = NULL;
        tempL->next = node;
        tempL = tempL->next;
    }

    return true;
}

bool InsertLNode2(Linklist &L) {
    Linklist tempL = L;
    for (int i = 4; i < 12; ++i) {
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

void LinklistMergeSame(Linklist &L1, Linklist &L2) {
    Linklist headL1 = L1;
    int tempData;
    while (L1 && L2 && L2->next != NULL && L1->next != NULL) {
        tempData = L1->next->data;
        if (L2->next->data < tempData) {
            L2 = L2->next;
        } else if (L2->next->data == tempData) {
            L1 = L1->next;
            L2 = L2->next;
        } else if (L2->next->data > tempData) {
            //删除L1节点
            L1->next = L1->next->next;
        }
    }

    L1 = headL1;

}


int main() {
    cout << "Hello world" << endl;

    Linklist L = new LNode();
    Linklist L1 = new LNode();
    Linklist L2 = new LNode();
    L->next == NULL;
    L1->next == NULL;
    L2->next == NULL;
    InsertLNode1(L1);
    InsertLNode2(L2);
    Print(L);
    Print(L1);
    Print(L2);

    LinklistMergeSame(L1, L2);

    Print(L1);

    return 0;
}