//
// Created by Linker on 10/3/2021.
//
#include "iostream"

using namespace std;

typedef struct DNode {
    int data;
    struct DNode *prior, *next;
} DNode, *DLinklist;

void InsertDLinklist(DLinklist &L) {
    DLinklist tempL = L;
    for (int i = 0; i < 10; ++i) {
        DLinklist node = new DNode();
        node->data = i;
        node->next = NULL;
        node->prior = tempL;
        tempL->next = node;
        tempL = tempL->next;
    }
    for (int i = 10; i >= 0; --i) {
        DLinklist node = new DNode();
        node->data = i;
        node->next = NULL;
        node->prior = tempL;
        tempL->next = node;
        tempL = tempL->next;
    }
}

void Print(DLinklist L) {
    while (L && L->next != NULL) {
        cout << L->next->data << ends;
        L = L->next;
    }
    cout << endl;
}

bool DLinklistSymmetry(DLinklist L) {
    DLinklist head = L, temp = L;
    int count = 0;
    while (temp->next != NULL) {
        count++;
        temp = temp->next;
    }
    for (int i = 0; i < count / 2+1; ++i) {
        if (head->next->data == temp->data) {
            cout << head->next->data << "  " << temp->data << endl;
            head = head->next;
            temp = temp->prior;
        } else {
            return false;
        }
    }
    return true;

}

int main() {
    cout << "Hello world" << endl;

    DLinklist L = new DNode();

    InsertDLinklist(L);
    Print(L);

    bool result = DLinklistSymmetry(L);
    cout<<result<<endl;
    Print(L);

    return 0;
}