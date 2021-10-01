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

double findMid(List &myList1, List &myList2) {
    //计算count1 + count2
    int count = myList1.length + myList2.length;
    if (count % 2 == 1) {
        int midCount = count / 2;

        int tempLeftCount = 0;
        int tempRightCount = 0;
        int tempNum;
        while (tempLeftCount + tempRightCount <= midCount) {
            if (myList1.data[tempLeftCount] <= myList2.data[tempRightCount]) {
                tempNum = myList1.data[tempLeftCount++];
            } else if (myList1.data[tempLeftCount] > myList2.data[tempRightCount]) {
                tempNum = myList2.data[tempRightCount++];
            }
        }
        return tempNum;

    } else if (count % 2 == 0) {
        int midCountRight = count / 2;
//        int midCountLeft = midCountRight - 1;

        int tempLeftCount = 0;
        int tempRightCount = 0;
        double tempNum0, tempNum;
        while (tempLeftCount + tempRightCount <= midCountRight) {
            if (myList1.data[tempLeftCount] <= myList2.data[tempRightCount]) {
                tempNum0 = tempNum;
                tempNum = myList1.data[tempLeftCount++];
            } else if (myList1.data[tempLeftCount] > myList2.data[tempRightCount]) {
                tempNum0 = tempNum;
                tempNum = myList2.data[tempRightCount++];
            }
        }
        return (tempNum0 + tempNum) / 2;
    }
    //奇数则 直接辗转相消


    //偶数则计算[mid] 和 [mid+1] 的平均数
}

int main() {
    cout << "hello world" << endl;
    List myList1;
    int n = 10;
    int data1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Init(myList1, n, data1);
    Print(myList1);

    List myList2;
    int m = 10;
    int data2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Init(myList2, m, data2);
    Print(myList2);

    double result = findMid(myList1, myList2);
    cout << result << endl;

    return 0;
}