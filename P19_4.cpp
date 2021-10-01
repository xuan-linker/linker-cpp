//
// Created by Linker on 10/1/2021.
//

#include "iostream"

using namespace std;

#define MaxSize 100
typedef struct List {
    int data[MaxSize];
    int length;
};

void Print(List myList) {
    for (int i = 0; i < myList.length; ++i) {
        cout << myList.data[i] << ends;
    }
    cout << endl;

}

//删除有序中的区间
bool ListDelete(List &myList, int s, int t) {
    if (s > t) {
        cout << "s>t" << endl;
        return false;
    }
    if (myList.length == 0) {
        cout << "list empty" << endl;
        return false;
    }
    int left = 0;
    int right = 0;
    //如果是>= 则左侧 ， 如果是>= 则左侧    小于被删除的数|等于被删除的数
    for (int i = 0; i < myList.length; i++) {
        if (myList.data[i] >= s) {
            left = i;
            break;
        }
    }
    //如果是>= 则左侧 ， 如果是> 则右侧    等于被删除的数|大于被删除的数
    for (int j = 0; j < myList.length; ++j) {
        if (myList.data[j] > t) {
            right = j;
            break;
        }
    }
    for (int i = left, j = right; i < myList.length; ++i, ++j) {
        myList.data[i] = myList.data[j];
    }
    myList.length = myList.length - right + left;


    return true;
}

void Init(List &myList, int n, int data[]) {
    myList.length = n;
    for (int i = 0; i < myList.length; ++i) {
        myList.data[i] = data[i];
    }
}

int main() {
    cout << "hello world" << endl;
    List myList;
    int n = 6;
    int data[] = {1, 2, 3, 4, 5, 6};
    Init(myList, n, data);
    Print(myList);
    ListDelete(myList, 3, 4);
    Print(myList);
    ListDelete(myList, 4, 3);
    Print(myList);

    return 0;
}