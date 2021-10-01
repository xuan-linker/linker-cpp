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

bool Swap(List &myList, int m, int n) {
//    if (m >= n) {
//        return false;
//    }
    int maxsize = m + n;
    int data[maxsize];
    int count = 0;

    for (int i = m; i < maxsize; ++i) {
        data[count++] = myList.data[i];
    }
    for (int i = 0; i < m; ++i) {
        data[count++] = myList.data[i];
    }
    for (int i = 0; i < maxsize; ++i) {
        myList.data[i] = data[i];
    }
    return true;

}

int main() {
    cout << "hello world" << endl;
    List myList1;
    int n = 20;
    int data1[] = {1, 2, 2, 2, 3, 3, 4, 4, 5, 6, 1, 2, 3, 3, 3, 3, 4, 5, 7, 8};
    Init(myList1, n, data1);
    Print(myList1);

//    List myList2;
//    int m = 10;
//    int data2[] = {1, 2, 3, 3, 3, 3, 4, 5, 7, 8};
//    Init(myList2, m, data2);
//    Print(myList2);

    Swap(myList1,10,10);
    Print(myList1);

    return 0;
}