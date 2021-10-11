//
// Created by Linker on 10/11/2021.
// 交换排序

#include "iostream"

using namespace std;

void Print(int A[], int n) {
    for (int k = 0; k < n; ++k) {
        cout << A[k] << ends;
    }
    cout << endl;
}

void BubbleSort(int A[], int n) {
    Print(A, n);
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        for (int j = n - 1; j > i; --j) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                flag = true;
            }
        }
        if (flag == false) { //如果已经有序，则终止
            break;
        }
    }
    Print(A, n);
}

/* 31245 , 0,4 , temp=3
 * 0,2
 * 21245
 * 2,2
 * 21345
 * */
//标准分割函数
int Partition(int A[], int low, int high) {
//    Print(A, 5);
    int pivot = A[low];
    while (low < high) {
        while (low < high && A[high] > pivot) {
            --high;
        }
        A[low] = A[high];
        while (low < high && A[low] <= pivot) {
            ++low;
        }
        A[high] = A[low];
//        Print(A, 5);
    }
    A[low] = pivot;
//    Print(A, 5);
    return low;
}

//快排母函数
void QuickSort(int A[], int low, int high) {

    if (low < high) {
        int pivot = Partition(A, low, high);
        QuickSort(A, low, pivot - 1);
        QuickSort(A, pivot + 1, high);
    }

}

//选择排序
void SelectSort(int A[], int n) {
    for (int i = 0; i < n; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (A[min] > A[j]) {
                min = j;
            }
        }
        if (min != i) {
            swap(A[i], A[min]);
        }

    }
}

int main() {
    cout << "hello world" << endl;
    int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int arr2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    BubbleSort(arr, 10);
//    Print(arr, 10);
//    QuickSort(arr, 0, 9);

    int arr3[5] = {3, 1, 2, 4, 5};
    Print(arr3, 5);
    QuickSort(arr3, 0, 4);
    Print(arr3, 5);

//    Print(arr, 10);
//    SelectSort(arr,10);
//    Print(arr, 10);

    return 0;
}
