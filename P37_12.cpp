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
    for (int i = 1; i < 10; ++i) {
        Linklist node = new LNode();
        node->data = i/2;
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


bool LinklistDeleteSame(Linklist &L) {
    if (!L || L->next == NULL) {
        cout << "empty" << endl;
        return false;
    }
    Linklist tempL = L;
    int tempData = -999999;
    while (tempL && tempL->next != NULL) {
        if (tempL->next->data == tempData) {
            tempL->next = tempL->next->next;
        } else if (tempL->next->data != tempData) {
            tempData = tempL->next->data;
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

    LinklistDeleteSame(L);

    Print(L);

    return 0;
}