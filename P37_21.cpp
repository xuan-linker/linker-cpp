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
        node->data = i;
        head->next = node;
        head = head->next;
    }
}

// 前后双指针查找对应第k个元素
int FindNode(Linklist L, int k) {
    LNode *headFirst = L, *headNext = L;
    int count = k;
    while (count > 0) {
        headFirst = headFirst->next;
        count--;
    }
    if (count > 0) {
        return 0;
    }
    count = k;
    while (count > 0 && headFirst!=NULL) {
        headFirst = headFirst->next;
        headNext = headNext->next;
        count--;
    }
    if (count == 0){
        return headNext->next->data;
    } else{
        return 0;
    }

}

int main() {
    LNode *L = new LNode();
    InsertList(L);
    Print(L);

    int node = FindNode(L, 3);
    cout<<node<<endl;
    Print(L);
    return 0;
}
