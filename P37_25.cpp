//
// Created by Linker on 10/6/2021.
//

#include "iostream"

using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *Linklist;

void Print(Linklist L) {
    LNode *head = L;
    while (L->next != NULL) {
        cout << L->next->data << ends;
        L = L->next;
    }
    cout << endl;
}

void InsertList(Linklist &L) {
    LNode *head = L;
    for (int i = 0; i < 10; ++i) {
        LNode *node = new LNode();
        node->data = i;
        head->next = node;
        head = head->next;
    }
}


int Sort(Linklist &L) {
    LNode *head = L;
    LNode *firstNode = L, *nextNode = L;
    while (nextNode && nextNode->next != NULL) {
        firstNode = firstNode->next;
        nextNode = nextNode->next;
        if (nextNode->next != NULL) {
            nextNode = nextNode->next;
        }
    }
    nextNode = firstNode->next;
    firstNode->next = NULL;
    while (nextNode) {
        LNode *tempNode = nextNode;
        nextNode = nextNode->next;
        tempNode->next = firstNode->next;
        firstNode->next = tempNode;
    }
    Print(L);
//    head = L->next;
//    while (firstNode && firstNode->next->next != NULL) {
//        Print(L);
//        LNode *tempNode = firstNode->next;
//        firstNode->next = firstNode->next->next;
//        tempNode->next = head->next;
//        head->next = tempNode;
//        head = head->next->next;
//    }
    head = L->next;
    while (firstNode && firstNode->next->next != NULL) {
        Print(L);
        LNode *node = firstNode->next;
        firstNode->next = firstNode->next->next;

        node->next = head->next;
        head->next = node;
        head = head->next->next;
    }

    return 1;
}

int main() {
    LNode *L1 = new LNode();
    InsertList(L1);
    Print(L1);
    int res = Sort(L1);
    cout << res << endl;
    Print(L1);


    return 0;
}
