//
// Created by Linker on 10/3/2021.
// 循环双链表 带头结点
//
#include "iostream"

using namespace std;

typedef struct DNode {
    int data;
    struct DNode *prior, *next;
} DNode, *DLinklist;

void InsertDLinklist(DLinklist &L) {
    DLinklist tempL = L;
    for (int i = 0; i < 3; ++i) {
        DLinklist node = new DNode();
        node->data = i;
        node->next = NULL;
        node->prior = tempL;
        tempL->next = node;
        tempL = tempL->next;
    }

    tempL->next = L->next;
}

void InsertDLinklist2(DLinklist &L) {
    DLinklist tempL = L;
    for (int i = 6; i < 10; ++i) {
        DLinklist node = new DNode();
        node->data = i;
        node->next = NULL;
        node->prior = tempL;
        tempL->next = node;
        tempL = tempL->next;
    }
    tempL->next = L->next;
}


void Print(DLinklist L) {
    DLinklist tempL = L->next;
    int count = 0;
    while (tempL) {
        if (tempL == L->next && count > 0) {
            break;
        }
        cout << tempL->data << ends;
        tempL = tempL->next;
        count++;
    }
    cout << endl;
}

bool DLinklistMerge(DLinklist &L1, DLinklist L2) {
    DLinklist headL1 = L1, headL2 = L2;
    DLinklist tempL1 = L1->next, tempL2 = L2->next;
    while (tempL1->next != L1->next) {
        tempL1 = tempL1->next;
    }
    while (tempL2->next != L2->next) {
        tempL2 = tempL2->next;
    }
    tempL1->next = headL2->next;
    headL2->next->prior = tempL1;

    tempL2->next = headL1->next;
    headL1->next->prior = tempL2;
    return true;
}

int main() {
    cout << "Hello world" << endl;

    DLinklist L = new DNode();
    DLinklist L1 = new DNode();
    DLinklist L2 = new DNode();

    InsertDLinklist(L1);
    InsertDLinklist2(L2);
    Print(L1);
    Print(L2);

    DLinklistMerge(L1, L2);
    Print(L1);


    return 0;
}