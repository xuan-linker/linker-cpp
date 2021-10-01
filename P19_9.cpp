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

bool find(List &myList, int x, int left, int right) {
    int mid = (left + right) / 2;
    if (myList.data[mid] == x) {
        //swap
        if (mid == myList.length - 1) {
            return true;
        } else {
            int temp = myList.data[mid];
            myList.data[mid] = myList.data[mid + 1];
            myList.data[mid + 1] = temp;
            return true;
        }
    } else if (myList.data[mid] > x) {
        right = mid - 1;
        find(myList, x, left, right);
    } else if (myList.data[mid] < x) {
        left = mid + 1;
        find(myList, x, left, right);
    }
    return false;
}

int main() {
    cout << "hello world" << endl;
    List myList1;
    int n = 10;
    int data1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Init(myList1, n, data1);
    Print(myList1);

//    List myList2;
//    int m = 10;
//    int data2[] = {1, 2, 3, 3, 3, 3, 4, 5, 7, 8};
//    Init(myList2, m, data2);
//    Print(myList2);
    int x = 2;
    find(myList1, x, 0, myList1.length - 1);

    Print(myList1);

    return 0;
}