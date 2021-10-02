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
        node->data = i % 3;
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

bool InitLinklist(Linklist &L) {
    Linklist linklist = new LNode();
    linklist->next = NULL;
    return true;
}

void DeepDelete(Linklist &L, int e) {
    Linklist tempL = L;
    while (tempL&&tempL->next != NULL) {
        if (tempL->next->data == e) {
            tempL->next = tempL->next->next;
        }
        tempL = tempL->next;
    }
    return;
}

int main() {
    cout << "hello world" << endl;
    Linklist myL = new LNode();
    InitLinklist(myL);
    InsertLNode(myL);
    Print(myL);
    DeepDelete(myL, 0);
    Print(myL);


    return 0;
}
