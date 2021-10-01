#include <iostream>
#include "vector"

using namespace std;

const int MaxSize = 50;
typedef struct MyList {
    int *data;
    int listSize;
    int length;
};

MyList InitList(int len) {
    MyList L;
    L.listSize = len == 0 ? MaxSize : len;
    L.data = new int[L.listSize];
    L.length = 0;
    return L;
}

int Length(MyList L) {
    return L.length;
}

vector<int> LocateElem(MyList L, int e) {
    vector<int> result;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e) {
            result.push_back(i);
        }
    }
    return result;

}

int GetElem(MyList L, int i) {
    if (L.length < i) {
        return -1;
    }
    return L.data[i];
}

bool ListInsert(MyList &L, int i, int e) {
    if (i < 0 || i > L.length ) {
        return false;
    }
    if (L.length>=L.listSize){
        return false;
    }

    for (int k = L.length; k > i; --k) {
        L.data[k] = L.data[k - 1];
    }
    L.data[i] = e;
    L.length++;

    return true;

}

// 删除指定位置的元素  将指定位置之后的元素向前移动一位
bool ListDelete(MyList &L, int i, int &e) {
    if (i < 0 || i > L.length || L.length == 0) {
        return false;
    }
    e = L.data[i];
    for (int j = i; j < L.length; ++j) {
        L.data[j] = L.data[j + 1];
    }

    L.length--;
    return true;
}

void PrintList(MyList L) {
    for (int i = 0; i < L.length; ++i) {
        std::cout << L.data[i] << ends;
    }
    std::cout << endl;
}

bool Empty(MyList L) {
    if (L.length == 0) {
        return true;
    } else {
        return false;
    }
}

bool DestroyList(MyList &L) {
    if (!L.data) {
        cout << "线性表不存在" << endl;
        return false;
    }
    free(L.data);
    L.data = NULL;
    cout << "线性表已销毁" << endl;
    return true;

}

int main() {
    cout << "Hello world" << endl;
    MyList myList = InitList(10);
    bool empty = Empty(myList);
    cout << empty << endl;

    ListInsert(myList, 0, 1);
    PrintList(myList);
    ListInsert(myList, 0, 2);
    PrintList(myList);
    ListInsert(myList, 0, 3);
    PrintList(myList);
    ListInsert(myList, 6, 4);
    PrintList(myList);
    ListInsert(myList, 2, 5);
    PrintList(myList);

    vector<int> vector = LocateElem(myList, 2);
    for (int i = 0; i < vector.size(); ++i) {
        cout<<vector.at(i)<<endl;
    }

    int deleteEle;
    ListDelete(myList, 0, deleteEle);
    PrintList(myList);
    cout << deleteEle << endl;

    bool empty2 = Empty(myList);
    cout << empty2 << endl;

    bool destroy1 = DestroyList(myList);
    cout << destroy1 << endl;
    bool destroy2 = DestroyList(myList);
    cout << destroy2 << endl;

    return 0;


}