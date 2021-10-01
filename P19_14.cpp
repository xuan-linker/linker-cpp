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

bool firstIsMin(int a, int b, int c) {
    if (a <= b && a <= c) {
        return true;
    } else {
        return false;
    }
}

int calD(int a, int b, int c) {
    int res = abs(a - b) + abs(a - c) + abs(b - c);
    return res;
}

int calMinThree(List myList1, List myList2, List myList3, int &temp1, int &temp2, int &temp3) {
    int i = 0, j = 0, k = 0;
    temp1 = myList1.data[i], temp2 = myList2.data[j], temp3 = myList3.data[k];
    int min = calD(temp1, temp2, temp3);

    while (i < myList1.length && j < myList2.length && k < myList3.length) {
        if (firstIsMin(temp1, temp2, temp3)) {
            i++;
        } else if (firstIsMin(temp2, temp1, temp3)) {
            j++;
        } else if (firstIsMin(temp3, temp1, temp2)) {
            k++;
        }
        int tempD = calD(myList1.data[i], myList2.data[j], myList3.data[k]);
        if (tempD < min) {
            temp1 = myList1.data[i];
            temp2 = myList2.data[j];
            temp3 = myList3.data[k];
        }
    }
    return min;
}


int main() {
    cout << "hello world" << endl;
    List myList1;
    int n = 3;
    int data1[] = {-1, 0, 9};
    Init(myList1, n, data1);
    Print(myList1);

    List myList2;
    int m = 4;
    int data2[] = {-25, -10, 10, 11};
    Init(myList2, m, data2);
    Print(myList2);

    List myList3;
    int s = 5;
    int data3[] = {2, 9, 17, 30, 41};
    Init(myList3, s, data3);
    Print(myList3);

    int temp1, temp2, temp3;
    int result = calMinThree(myList1, myList2, myList3, temp1, temp2, temp3);
    cout << result << endl;
    cout << temp1 << endl;
    cout << temp2 << endl;
    cout << temp3 << endl;


    return 0;
}