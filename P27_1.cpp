//
// Created by Linker on 10/1/2021.
//

#include "iostream"

using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next; // "基本类型 *" ：声明指针变量。它的值是另一个变量的地址。https://www.runoob.com/cplusplus/cpp-pointer-operators.html
} LNode, *Linklist; //LinkList 为指向结构体的指针类型

int InitList(Linklist &L) {
    L = new LNode();
    if (!L) {
        cout << "申请内存空间失败" << endl;
        return -1;
    }
    L->next = NULL;
    return 1;
}

//头插法建立单链表 -> 从头部插入
bool List_HeadInsert(Linklist &L, int e) {
    Linklist node = new LNode();
    node->data = e;
    node->next = NULL;
    node->next = L;
    L = node;
    return true;
}

//尾插法建立单链表
bool List_tailInsert(Linklist &L, int e) {
    Linklist temp = L;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    Linklist newNode = new LNode();
    newNode->data = e;
    newNode->next = NULL;
    temp->next = newNode;
}

//按序号查找节点 从0开始
Linklist GetElem(Linklist &L, int i) {
    int tempI = 0;
    Linklist temp = L;

    while (tempI != i) {
        temp = temp->next;
        tempI++;
    }
    if (i == tempI) {
        return temp;
    }
    return NULL;

}

//按值查找节点
int LocateElem(Linklist &L, int e) {
    Linklist tempL = L;
    int count = 0;
    while (tempL != NULL) {
        if (tempL->data == e) {
            return count;
        }
        tempL = tempL->next;
        count++;
    }
    return -1;
}

//插入指定位置 i>=1
int InsertLNode(Linklist &L, int e, int i) {
    Linklist tempL = L;
    int count = 0;

    while (tempL && count < i - 1) {
        tempL = tempL->next;
        count++;
    }
    if (!tempL || count > i - 1) {
        return 0;
    }
    Linklist newNode = new LNode();
    newNode->data = e;
    newNode->next = tempL->next;
    tempL->next = newNode;

}

//删除指定位置节点
int DeleteLNode(Linklist &L, int i) {
    Linklist tempL = L;
    int count = 0;

    while (tempL && count < i - 1) {
        tempL = tempL->next;
        count++;
    }
    Linklist freeNode = tempL->next;

    tempL->next = tempL->next->next;

    free(freeNode);
}

int ListLength(Linklist &L) {
    if (L == NULL) {
        return 0;
    }
    int count = 0;
    Linklist tempL = L;
    while (tempL != NULL) {
        count++;
        tempL = tempL->next;
    }
    return count;

}

void Print(Linklist L) {
    if (L == NULL) {
        return;
    }
    while (L != NULL) {
        cout << L->data << ends;
        L = L->next;
    }
    cout << endl;
}

//init 初始化后自带一个空节点
bool isEmpty(Linklist L) {
    if (L->next == NULL) {
        return true;
    } else {
        return false;
    }
}

int DestroyList(Linklist &L) {

    Linklist tempL = L;
    while (L){
        tempL = L;
        L = L->next;
        delete tempL;
    }
    return 1;
}

int main() {


    cout << "hello world" << endl;
    //init
    Linklist L;


    int res = InitList(L);
//    cout << res << endl;
//    Print(L);

    bool empty = isEmpty(L);
    cout << empty << endl;

    bool b = List_HeadInsert(L, 1);
    List_HeadInsert(L, 2);
    List_HeadInsert(L, 3);
    List_HeadInsert(L, 4);
    List_HeadInsert(L, 5);
//    cout << b << endl;
    Print(L);

    List_tailInsert(L, 6);
    List_tailInsert(L, 7);
    List_tailInsert(L, 8);
    List_tailInsert(L, 9);
    Print(L);

    Linklist pNode = GetElem(L, 9);
    cout << pNode->data << endl;

    int i = LocateElem(L, 3);
    cout << i << endl;
    Print(L);

    int node = InsertLNode(L, 999, 1);
    Print(L);
    DeleteLNode(L, 1);
    Print(L);


    int length = ListLength(L);
    cout << length << endl;
    Print(L);

    bool empty2 = isEmpty(L);
    cout << empty2 << endl;

    int delL = DestroyList(L);
    cout<<delL<<endl;

    return 0;
}