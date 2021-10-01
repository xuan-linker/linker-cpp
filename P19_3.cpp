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

// 双指针，i存储 j比较
bool DeleteElement(List &myList, int e) {
    if (myList.length == 0) {
        return false;
    }
    int i = 0, j = 0;
    for (; j < myList.length;) {
        if (myList.data[j] == e) {
            j++;
        } else if (myList.data[j] != e) {
            myList.data[i] = myList.data[j];
            i++;
            j++;
        }
    }
    myList.length = i;
    return true;
}

void Print(List myList) {
    for (int i = 0; i < myList.length; ++i) {
        cout << myList.data[i] << ends;
    }
    cout << endl;

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
    int data[] = {1, 2, 3, 4, 3, 2};
    Init(myList, n, data);

    Print(myList);
    DeleteElement(myList,3);
    Print(myList);

    return 0;
}