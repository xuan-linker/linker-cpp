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
    for (int i = 4; i < 8; ++i) {
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

//传统双重循环比较法
//长序列L1 子序列L2  如果L2无后继节点则比较完毕
bool normalSubsequence(Linklist L1, Linklist L2) {
    if (!L1 || !L2 || L1->next == NULL || L2->next == NULL) {
        return false;
    }
    Linklist headL2 = L2;
    while (L1->next != NULL) {
        Linklist tempL1 = L1, tempL2 = headL2;
        if (tempL1->next->data == tempL2->next->data) {
            while (tempL1->next != NULL && tempL2->next != NULL && tempL1 && tempL2
                   && tempL1->next->data == tempL2->next->data) {
                tempL1 = tempL1->next;
                tempL2 = tempL2->next;
            }
            if (tempL2->next == NULL) {
                cout<<"success"<<endl;
                return true;
            }
        } else if (L1->next->data != L2->next->data) {
            L1 = L1->next;
        }
    }
    cout<<"false"<<endl;
    return false;
}


int main() {
    cout << "Hello world" << endl;

    Linklist L1 = new LNode();
    Linklist L2 = new LNode();
    InsertLNode1(L1);
    InsertLNode2(L2);
    Print(L1);
    Print(L2);

    bool result = normalSubsequence(L1, L2);
    cout << result << endl;

    return 0;
}