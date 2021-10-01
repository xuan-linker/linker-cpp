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
    int length = 0;
    int data[myList.length];
    int i = 0;
    for (int j = 0; j < myList.length; ++j) {
        if (myList.data[j] >= s && myList.data[j] <= t) {
            continue;
        } else {
            length++;
            data[i] = myList.data[j];
            i++;
        }
    }
    myList.length = length;
    for (int j = 0; j <= i; ++j) {
        myList.data[j] = data[j];
    }

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