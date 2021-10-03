//
// Created by Linker on 10/2/2021.
// 双链表
//

#include "iostream"
#include "vector"

using namespace std;

typedef struct DNode {
    int data;
    struct DNode *prior, *next; //前驱和后继指针
} DNode, *DLinklist; // 存在问题

void Init(DNode &L) {
    L = new DNode();
    if (!L) {
        cout << "申请内存空间失败" << endl;
    }
    L->next = NULL;
    L->prior = NULL;
    return;
}

void InsertDNode(DNode &L) {
    DNode head = L;
    DNode tempL = L;
    for (int i = 0; i < 10; ++i) {
        if (i == 0) {
            L->data = i;
        } else {
            DNode node = new DNode();
            node->data = i%3;
            node->prior = tempL;
            tempL->next = node;
            tempL = tempL->next;
        }
    }

}

////带头结点
//void InsertDNodeWithHead(DNode &L, int e) {
//    DNode tempL = L;
//    DNode head = L;
//    while (tempL && tempL->next != NULL) {
//        tempL = tempL->next;
//    }
//    DNode node = new DNode();
//    node->data = e;
//    tempL->next = node;
//}

vector<int> DeleteDNode(DNode &L, int e) {
    DNode tempL = L;
    vector<int> v;
    int count = 0;
    while (tempL) {
        if (tempL->data == e && count == 0) {
            tempL = tempL->next;
            v.push_back(count);
        } else if (tempL->data == e && tempL->next == NULL) {
            tempL = tempL->prior;
            tempL->next = NULL;
            v.push_back(count);
            tempL = tempL->next;
        } else if (tempL->data == e && tempL->next != NULL) {
            tempL->next->prior = tempL->prior;
            tempL->prior->next = tempL->next;

            tempL = tempL->next;
            v.push_back(count);
        } else{
            tempL = tempL->next;
        }
        count++;
    }

    return v;

}

bool DeleteDNode2(DNode &L, int i) {
    DNode tempL = L;
    int count = 0;
    while (tempL) {
        if (count == i) {
            if (tempL->next == NULL) {
                tempL = tempL->prior;
                tempL->next = NULL;
                return true;
            } else if (tempL->next != NULL) {
                tempL->next->prior = tempL->prior;
                tempL->prior->next = tempL->next;
                DNode deleteNode = tempL;
                tempL = tempL->prior;
                free(deleteNode);
                return true;
            }
        } else if (count < i) {
            tempL = tempL->next;
        } else if (count > i) {
            //...
            break;
        }
        count++;
    }
    return false;

}

void Print(DNode L) {
//    while (L->next != NULL && L) {
//        cout << L->next->data << ends;
//    }
//    cout << endl;
    while (L) {
        cout << L->data << ends;
        L = L->next;
    }
    cout << endl;
}


int main() {
    cout << "hello world" << endl;
    DNode L = new DNode();
    InsertDNode(L);
    Print(L);

//    vector<int> v = DeleteDNode(L, 0);
//    for (int i = 0; i < v.size(); ++i) {
//        cout << v.at(i) << ends;
//    }
    Print(L);

    bool result = DeleteDNode2(L, 3);
    cout<<result<<endl;
    Print(L);

    return 0;
}
