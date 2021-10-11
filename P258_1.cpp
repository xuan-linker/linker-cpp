//
// Created by Linker on 10/11/2021.
//

#include "iostream"

using namespace std;
#define MaxSize 100
typedef struct SSTable {
    int data[MaxSize]; //元素存储空间基质，建表时按实际长度分配
    int TableLen;
};

//一般线性表的顺序查找——哨兵
int SearchSeq(SSTable ST, int key) {
    ST.data[0] = key;
    int i = ST.TableLen;
    for (; ST.data[i] != key; --i) {
    }
    return i; //若表中不存在关键字为key的元素，将查找到的i为0时退出for循环

}

void Init(SSTable &ST) {
    ST.TableLen = 1;
    ST.data[0] = 0;
    for (int i = 1; i < 10; ++i) {
        ST.data[i] = i;
        ST.TableLen++;
    }
}

int main() {
    cout << "hello world" << endl;
    SSTable ST;
    Init(ST);
    int i = SearchSeq(ST, 5);
    cout << i << endl;
    return 0;
}
