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

void LinklistMergeSame(Linklist &L, Linklist &L1, Linklist &L2) {
    if (!L1 || !L2 || L1->next == NULL || L2->next == NULL) {
        return;
    }

    Linklist tempL1 = L1, tempL2 = L2;

    Linklist tempL = L, head = L;
    int tempData = L1->next->data;
    //相等 L1、L2 同时+1
    while (tempL1 && tempL2 && tempL1->next != NULL && tempL2->next != NULL) {
        tempData = tempL1->next->data;
        if (tempL1->next->data == tempL2->next->data) {
            Linklist node = new LNode();
            node->data = tempL1->next->data;
            tempL->next = node;
            tempL = tempL->next;

            tempL1 = tempL1->next;
            tempL2 = tempL2->next;
            //break
        } else if (tempL2->next->data < tempData) {
            tempL2 = tempL2->next;
        } else if (tempL2->next->data > tempData) {
            tempL1 = tempL1->next;
        }

    }

    L = head;
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

    LinklistMergeSame(L, L1, L2);

    Print(L);
    Print(L1);
    Print(L2);

    return 0;
}