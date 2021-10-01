//
// Created by Linker on 10/1/2021.
//

#include <iostream>

using namespace std;

#define MaxSize 100
typedef struct List {
    int data[MaxSize];
    int length;
};

bool ListDelete(List &myList, int &e) {
    if (myList.length == 0) {
        return false;
    }
    int minEle = myList.data[0];
    int i = 0;
    for (int j = 0; j < myList.length; ++j) {
        if (myList.data[j] < minEle) {
            i = j;
            minEle = myList.data[j];
        }
    }
    // delete
    //swap
    if (myList.length - 1 > i) {
        myList.data[i] = myList.data[myList.length - 1];
    }
    myList.length--;

    return true;
}

void PrintList(List myList) {
    for (int i = 0; i < myList.length; ++i) {
        cout << myList.data[i] << ends;
    }
    cout << endl;
}

int main() {
    cout << "Hello world" << endl;
    List myList;
    myList.length = 4;
    int arr[] = {1, 2, 3, 4};
    for (int i = 0; i < myList.length; ++i) {
        myList.data[i] = arr[i];
    }

    PrintList(myList);
    for (int i = 0; i < 4; ++i) {
        int deleteE;
        bool listDelete = ListDelete(myList, deleteE);
        cout << listDelete << endl;
        PrintList(myList);
    }
    return 0;
}