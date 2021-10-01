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

int findMinNum(List &myList) {
    //为什么初始化异常
    int myData[MaxSize]={0};


    for (int i = 0; i < myList.length; ++i) {
        if (myList.data[i] > 0) {
            myData[myList.data[i]] = 1;
        }
    }
    for (int i = 1; i < MaxSize; ++i) {
        if (myData[i] == 0) {
            return i;
        }
    }

}

int main() {
    cout << "hello world" << endl;
    List myList1;
    int n = 4;
    int data1[] = {-5, 3, 2, 3};
    Init(myList1, n, data1);
    Print(myList1);

    List myList2;
    int m = 3;
    int data2[] = {1, 2, 3};
    Init(myList2, m, data2);
    Print(myList2);

    int result = findMinNum(myList2);
    cout << result << endl;

    return 0;
}