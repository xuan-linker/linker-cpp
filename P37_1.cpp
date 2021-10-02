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
    tempL->data = 0;
    for (int i = 1; i < 10; ++i) {
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
    while (tempL) {
        cout << tempL->data << ends;
        tempL = tempL->next;
    }
    cout << endl;
}

bool InitLinklist(Linklist &L) {
    Linklist linklist = new LNode();
    linklist->next = NULL;
    return true;
}

bool deepDelete(Linklist &L, int e, int count) {
    if (!L) {
        return false;
    }
    if (count == 0 && L->data == e) {
        L = L->next;
        deepDelete(L, e, count);
        return true;
    }

    if (L->next->data == e) {
        L->next = L->next->next;
        deepDelete(L, e, count++);
    }
    return true;

}

int main() {
    cout << "hello world" << endl;
    Linklist myL = new LNode();
    InitLinklist(myL);
    InsertLNode(myL);
    Print(myL);
    deepDelete(myL, 1, 0);
    Print(myL);


    return 0;
}
