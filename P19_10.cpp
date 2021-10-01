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

bool Move(List &myList, int p) {
    int data[p];
    int count = 0;
    for (int i = myList.length - p; i < myList.length; ++i) {
        data[count++] = myList.data[i];
    }

    for (int i = myList.length - 1; i > p - 1; --i) {
        myList.data[i] = myList.data[i - p];
    }

    for (int i = p - 1; i >= 0; i--) {
        myList.data[i] = data[--count];
    }

    return true;
}

int main() {
    cout << "hello world" << endl;
    List myList1;
    int n = 10;
    int data1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Init(myList1, n, data1);

    Move(myList1, 3);

    Print(myList1);

    return 0;
}