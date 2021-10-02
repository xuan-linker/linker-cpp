//
// Created by Linker on 10/2/2021.
//

#include "iostream"
#include "vector"

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

void divide(Linklist &L, Linklist &L1, Linklist &L2) {
    int count = 0;
    Linklist tempL = L;
    Linklist tempL1 = L1;
    Linklist tempL2 = L2;
    while (tempL && tempL->next != NULL) {
        Linklist node = new LNode();
        node->next = NULL;
        if (count % 2 == 1) {
            node->data = tempL->next->data;
            tempL1->next = node;
            tempL1 = tempL1->next;
        } else if (count % 2 == 0) {

            node->data = tempL->next->data;
            tempL2->next = node;
            tempL2 = tempL2->next;
        }
        count++;
        tempL = tempL->next;
    }
}


int main() {
    cout << "Hello world" << endl;

    Linklist L = new LNode();
    Linklist L1 = new LNode();
    Linklist L2 = new LNode();
    L->next == NULL;
    L1->next == NULL;
    L2->next == NULL;
    InsertLNode(L);
    Print(L);
    Print(L1);
    Print(L2);

    divide(L, L1, L2);

    Print(L);
    Print(L1);
    Print(L2);

    return 0;
}