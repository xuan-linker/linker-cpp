//
// Created by Linker on 10/6/2021.
//

#include "iostream"

using namespace std;

typedef struct LNode {
    char data;
    struct LNode *next;
} LNode, *Linklist;

void Print(Linklist L) {
    while (L->next != NULL) {
        cout << L->next->data << ends;
        L = L->next;
    }
    cout << endl;
}

void InsertList(Linklist &L, Linklist &L3) {
    LNode *head = L;
    string sth1 = "load";
    for (int i = 0; i < sth1.size(); ++i) {
        LNode *node = new LNode();
        node->data = sth1.at(i);
        head->next = node;
        head = head->next;
    }
    head->next = L3->next;
}

void InsertList2(Linklist &L, Linklist &L3) {
    LNode *head = L;
    string sth1 = "be";
    for (int i = 0; i < sth1.size(); ++i) {
        LNode *node = new LNode();
        node->data = sth1.at(i);
        head->next = node;
        head = head->next;
    }
    head->next = L3->next;
}

void InsertList3(Linklist &L) {
    LNode *head = L;
    string sth1 = "ing";
    for (int i = 0; i < sth1.size(); ++i) {
        LNode *node = new LNode();
        node->data = sth1.at(i);
        node->next = NULL;
        head->next = node;
        head = head->next;
    }
}

int ListLength(Linklist L) {
    int count = 0;
    while (L->next != NULL) {
        count++;
        L = L->next;
    }
    return count;
}

// 前后双指针查找对应第k个元素
Linklist FindLast(Linklist L1, Linklist L2) {
    LNode *head1 = L1, *head2 = L2;
    int length1 = ListLength(L1);
    int length2 = ListLength(L2);
    while (length1 > length2) {
        head1 = head1->next;
        length1--;
    }
    while (length1 < length2) {
        head2 = head2->next;
        length2--;
    }
    while (L1) {
        LNode *node1 = head1->next;
        LNode *node2 = head2->next;
        cout << node1 << " " << node2 << endl;
        if (node1 == node2) {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}

int main() {
    LNode *L1 = new LNode();
    LNode *L2 = new LNode();
    LNode *L3 = new LNode();
    InsertList3(L3);
    InsertList(L1, L3);
    InsertList2(L2, L3);
    Print(L1);
    Print(L2);
//    Print(L3);
    Linklist pNode = FindLast(L1, L2);
    Print(pNode);


    return 0;
}
