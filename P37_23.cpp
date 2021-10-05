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
        node->data = i % 3;
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

void DeleteMoreData(Linklist &L, int max) {
    int *num = new int[++max]{0};
    LNode *head = L;
    while (head && head->next != NULL) {
        int data = head->next->data;
        if (num[data] != 0) {
            head->next = head->next->next;
            //易错点
//            head = head->next;
        } else if (num[data] == 0) {
            head = head->next;
            num[data] = 1;
        }
    }

}

int main() {
    LNode *L1 = new LNode();
    InsertList(L1);
    Print(L1);
//    Print(L3);
    DeleteMoreData(L1, 10);
    Print(L1);


    return 0;
}
