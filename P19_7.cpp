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

List MergeSortedList(List list1, List list2) {
    List result;
//    int length = 0;
    int maxsize = list1.length + list2.length;
    int data[maxsize];

    int left = 0, right = 0;
    for (; left < list1.length && right < list2.length;) {
        if (list1.data[left] <= list2.data[right]) {
            data[left + right] = list1.data[left++];
        } else if (list1.data[left] > list2.data[right]) {
            data[left + right] = list2.data[right++];
        }
    }
    if (left < list1.length) {

        for (int i = left; i < list1.length; ++i) {
            data[right + i] = list1.data[i];
        }
    } else if (right < list2.length) {
        for (int i = right; i < list2.length; ++i) {
            data[left + i] = list2.data[i];
        }
    }

    result.length = maxsize;
    for (int i = 0; i < maxsize; ++i) {
        result.data[i] = data[i];
    }
    return result;

}

int main() {
    cout << "hello world" << endl;
    List myList1;
    int n = 10;
    int data1[] = {1, 2, 2, 2, 3, 3, 4, 4, 5, 6};
    Init(myList1, n, data1);
    Print(myList1);

    List myList2;
    int m = 10;
    int data2[] = {1, 2, 3, 3, 3, 3, 4, 5, 7, 8};
    Init(myList2, m, data2);
    Print(myList2);

    List mergeList = MergeSortedList(myList1, myList2);
    Print(mergeList);

    return 0;
}