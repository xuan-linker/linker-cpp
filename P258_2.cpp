//
// Created by Linker on 10/11/2021.
//

#include "iostream"

using namespace std;
#define MaxSize 30
typedef struct SeqList {
    int data[MaxSize];
    int length;
};

void Init(SeqList &L) {
    L.length = 0;

    for (int i = 0; i < 10; ++i) {
        L.data[i] = i;
        L.length++;
    }
}

//折半查找
int Binary_Search(SeqList L, int key) {
    int low = 0, high = L.length - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L.data[mid] == key) {
            return mid;
        } else if (L.data[mid] > key) {
            high = mid - 1;
        } else if (L.data[mid] < key) {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    cout << "hello world" << endl;
    SeqList L;
    Init(L);
    int i = Binary_Search(L,5);
    cout<<i<<endl;
    return 0;
}