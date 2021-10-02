//
// Created by Linker on 10/2/2021.
//

#include "iostream"

using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *Linklist;

bool InsertLNode(Linklist &L) {
    Linklist tempL = L;
    for (int i = 5; i < 10; ++i) {
        Linklist node = new LNode();
        node->data = i ;
        node->next = NULL;
        tempL->next = node;
        tempL = tempL->next;
    }
    for (int i = 2; i < 5; ++i) {
        Linklist node = new LNode();
        node->data = i ;
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

bool InitLinklist(Linklist &L) {
    Linklist linklist = new LNode();
    linklist->next = NULL;
    return true;
}

//删除最小值节点
bool deleteMinLNode(Linklist &L) {
    if (L == NULL || L->next == NULL) {
        return false;
    }
    Linklist tempL = L;


    Linklist leftLNode = tempL, pointLNode = tempL->next;
    Linklist tempLeftLNode, tempPointLNode;
    while (tempL && tempL->next != NULL) {
        tempLeftLNode = tempL;
        tempPointLNode = tempL->next;

        if (pointLNode->data > tempPointLNode->data) {
            pointLNode = tempPointLNode;
            leftLNode = tempLeftLNode;
        }
        tempL = tempL->next;
    }
    leftLNode->next = pointLNode->next;
    return true;
}

int main() {
    cout << "hello world" << endl;
    Linklist myL = new LNode();
    InitLinklist(myL);
    InsertLNode(myL);
    Print(myL);
    deleteMinLNode(myL);

    Print(myL);

    return 0;
}
