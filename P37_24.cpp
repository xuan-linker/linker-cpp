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
    int flag = 0;
    LNode *head = L;
    while (L->next != NULL) {
        if (flag > 0 && L->next == head->next) {
            break;
        }
        cout << L->next->data << ends;
        L = L->next;
        flag++;
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
    head->next = L->next;
}

int ListLength(Linklist L) {
    int count = 0;
    while (L->next != NULL) {
        count++;
        L = L->next;
    }
    return count;
}

LNode *FindCircleHead(Linklist L) {
    LNode *head = L;
    int flag = 0;
    while (head->next != NULL) {
        if (head->next == L->next && flag != 0) {
            return head->next;
        }
        head = head->next;
        flag++;
        cout << flag << endl;
    }
    return NULL;
}

int main() {
    LNode *L1 = new LNode();
    InsertList(L1);
    Print(L1);
    LNode *pNode = FindCircleHead(L1);
    Print(pNode); //返回节点为head->next 非head
    Print(L1);


    return 0;
}
