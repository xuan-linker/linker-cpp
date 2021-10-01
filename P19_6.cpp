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

void Init(List &myList, int n, int data[]) {
    myList.length = n;
    for (int i = 0; i < myList.length; ++i) {
        myList.data[i] = data[i];
    }
}

void Print(List myList) {
    for (int i = 0; i < myList.length; ++i) {
        cout << myList.data[i] << ends;
    }
    cout << endl;
}

//删除有序表中重复元素
bool ListSortedDelete(List &myList) {
    if (myList.length == 0) {
        cout << "empty" << endl;
        return true;
    } else if (myList.length == 1) {
        return true;
    }
    int left = 0, right = 1;
    for (int i = 0; i < myList.length - 1; ++i) {
        if (myList.data[left] == myList.data[right]) {
            right++;
        } else if (myList.data[left] != myList.data[right]) {
            myList.data[++left] = myList.data[right++];
        }
    }
    myList.length = left + 1;
    return true;
}

int main() {
    cout << "hello world" << endl;
    List myList;
    int n = 10;
    int data[] = {1, 2, 2, 2, 3, 3, 4, 4, 5, 6};
    Init(myList, n, data);
    Print(myList);
    ListSortedDelete(myList);
    Print(myList);


    return 0;
}