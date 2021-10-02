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

//双重循环，内循环找最小值，找到最小节点前节点后free 前节点->next
//外循环迭代直到所有节点都free
void outputSortedLinklist(Linklist &L) {
    if (L->next == NULL || !L) {
        return;
    }
    Linklist head = L;
    Linklist tempL = L;
    Linklist tempPrior = L, tempLNote = tempPrior->next;
    while (head->next != NULL) {
        Linklist minTempPrior = head;
        tempL = head;
        while (tempL->next != NULL && tempL) {
            if (tempL->next->data < minTempPrior->next->data) {
                minTempPrior = tempL;
            }
            tempL = tempL->next;
        }
        //free
        Linklist deleteLNode = minTempPrior->next;
        minTempPrior->next = minTempPrior->next->next;
        cout<<deleteLNode->data<<ends;
        free(deleteLNode);
    }


    cout << endl;
}

void Print(Linklist &L) {
    Linklist tempL = L;
    while (tempL->next != NULL) {
        cout << tempL->next->data << ends;
        tempL = tempL->next;
    }
    cout << endl;
}

int main() {
    cout << "Hello world" << endl;

    Linklist L1 = new LNode();
    L1->next == NULL;
    InsertLNode(L1);
    Print(L1);

//    Linklist L2 = new LNode();
//    L2->next == NULL;
//    InsertLNode2(L2);
//    Print(L2);

    outputSortedLinklist(L1);

    Print(L1);

    return 0;
}