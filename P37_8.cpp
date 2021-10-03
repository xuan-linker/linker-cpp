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
bool InsertLNode2(Linklist &L) {
    Linklist tempL = L;
    for (int i = 5; i < 15; ++i) {
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

void Print(Linklist &L) {
    Linklist tempL = L;
    while (tempL->next != NULL) {
        cout << tempL->next->data << ends;
        tempL = tempL->next;
    }
    cout << endl;
}


vector<int> findSameLNode(Linklist &L1, Linklist &L2) {
    Linklist tempL1 = L1;
    Linklist tempL2 = L2;
    vector<int> v ;
    int count = 0;
    while (tempL1->next!=NULL && tempL2!=NULL && tempL1 &&tempL2){
        if (tempL1->next->data == tempL2->next->data){
            v.push_back(count++);
        }

        tempL1 = tempL1->next;
        tempL2 = tempL2->next;
    }
    return v;
}


int main() {
    cout << "Hello world" << endl;

    Linklist L1 = new LNode();
    L1->next == NULL;
    InsertLNode(L1);
    Print(L1);

    Linklist L2 = new LNode();
    L2->next == NULL;
    InsertLNode2(L2);
    Print(L2);
    vector<int> v =findSameLNode(L1,L2);
    for (int i = 0; i < v.size(); ++i) {
        cout<<v.at(i)<<ends;
    }

//    Print(L);
    return 0;
}