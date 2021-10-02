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

//反向输出每个节点的值
bool reversalLinklist(Linklist &L) {
    if (L && L->next != NULL) {
        Linklist next = L->next;
        reversalLinklist(next);
        cout << L->data << ends;
    }
    return true;

}

int main() {
    cout << "hello world" << endl;
    Linklist myL = new LNode();
    InitLinklist(myL);
    InsertLNode(myL);
    Print(myL);
    reversalLinklist(myL);
//    Print(myL);


    return 0;
}
