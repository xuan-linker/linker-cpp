//
// Created by Linker on 10/1/2021.
//

#include<iostream>

using namespace std;

#define MaxSize 100
typedef struct List {
    int data[MaxSize];
    int length;
};

bool Swap(List &myList) {
    if (myList.length <= 0) {
        return false;
    }
    int left, right;
    if (myList.length > 0) {
        left = 0;
        right = myList.length - 1;
        for (int left = 0, right = myList.length - 1; left <= right; left++, right--) {
            int temp = myList.data[left];
            myList.data[left] = myList.data[right];
            myList.data[right] = temp;
        }
    }
    return true;
}

void Print(List myList) {
    for (int i = 0; i < myList.length; ++i) {
        cout << myList.data[i] << ends;
    }
    cout << endl;
}

int main() {
    cout << "hello world" << endl;
    int data[] = {1,2,3,4,5};
    List myList ;
    myList.length = 5;
    for (int i = 0; i < myList.length; ++i) {
        myList.data[i] = data[i];
    }
    Print(myList);

    Swap(myList);

    Print(myList);

    return 0;
}