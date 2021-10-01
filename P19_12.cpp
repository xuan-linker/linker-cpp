////
//// Created by Linker on 10/1/2021.
//// 未完成
//
//#include "iostream"
//
//using namespace std;
//
//#define MaxSize 100
//
//typedef struct List {
//    int data[MaxSize];
//    int length;
//};
//
//void Init(List &myList, int n, int data[]) {
//    myList.length = n;
//    for (int i = 0; i < myList.length; ++i) {
//        myList.data[i] = data[i];
//    }
//}
//
//void Print(List myList) {
//    for (int i = 0; i < myList.length; ++i) {
//        cout << myList.data[i] << ends;
//    }
//    cout << endl;
//}
//
//int findMainNum(List &myList){
//
//}
//
//int main() {
//    cout << "hello world" << endl;
//    List myList1;
//    int n = 10;
//    int data1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    Init(myList1, n, data1);
//    Print(myList1);
//
//    List myList2;
//    int m = 10;
//    int data2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    Init(myList2, m, data2);
//    Print(myList2);
//
//    double result = findMid(myList1, myList2);
//    cout << result << endl;
//
//    return 0;
//}