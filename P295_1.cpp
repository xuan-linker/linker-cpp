//
// Created by Linker on 10/11/2021.
// 插入排序

#include "iostream"

using namespace std;

void Print(int A[], int n) {
    for (int k = 0; k < n; ++k) {
        cout << A[k] << ends;
    }
    cout << endl;
}

//直接插入
void InsertSort2(int A[], int n) {
    Print(A, n);

    for (int j = 1; j < n; j++) {
        int key = A[j]; //待排序第一个元素
        int i = j - 1;  //代表已经排过序的元素最后一个索引数
        while (i >= 0 && key < A[i]) {
            //从后向前逐个比较已经排序过数组，如果比它小，则把后者用前者代替，
            //其实说白了就是数组逐个后移动一位,为找到合适的位置时候便于Key的插入
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;//找到合适的位置了，赋值,在i索引的后面设置key值。
    }

    Print(A, n);
}

//直接插入
void InsertSort(int A[], int n) {
    Print(A, n);
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int temp = A[i];
        for (; j >= 0 && A[j] > temp; --j) {
            A[j + 1] = A[j];
        }
        A[j + 1] = temp;
    }
    Print(A, n);
}

// 折半插入
void InsertSort_3(int A[], int n) {
    Print(A, n);
    int low, high, mid;
    int temp;
    for (int i = 1; i < n; ++i) {
        temp = A[i];
        low = 0, high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (A[mid] > temp) {
                high = mid - 1;
            } else if (A[mid] < temp) {
                low = mid + 1;
            } else if (A[mid] == temp) {
                low = mid + 1;
            }
        }
        for (int j = i - 1; j >= low; --j) {
            A[j + 1] = A[j];
        }
        A[low] = temp;
    }
    Print(A, n);

}

void ShellSort(int A[], int n) {
    Print(A, n);

    for (int dk = n / 2; dk >= 1; dk = dk / 2) {
        for (int i = dk; i < n; ++i) {
            //插入或者交换，此处用插入
            int temp = A[i];
            int j;
            for (j = i - dk; j >= 0 && A[j] > temp; j = j - dk) {
                A[j + dk] = A[j];
            }
            A[j + dk] = temp; //j=low - dk,所以j+dk = low，A[j+dk]=temp
        }
    }
    Print(A, n);

}


int main() {
    cout << "Hello world" << endl;
    int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int arr2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    InsertSort_3(arr, 10);
    ShellSort(arr, 10);
    return 0;
}

