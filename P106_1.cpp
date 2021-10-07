//
// Created by Linker on 10/7/2021.
//

#include "iostream"

using namespace std;
#define MaxSize 50

typedef struct {
    int length = 0;
    char ch[MaxSize];
} SString;

void Insert(SString &S, string content) {
    for (int i = 1; i < content.length() + 1; ++i) {
        cout << content.at(i - 1) << ends;
        S.ch[i] = content.at(i - 1);
        S.length++;
    }
}

void GetNext(SString T, int next[]) {
    int i = 1;
    int j = 0;
    next[i] = 0;//默认i=1不匹配j=0//i=2不匹配j=1
    while (i <= T.length) {
        cout << i <<" "<<j << " " << T.ch[i] << " " << T.ch[j] << endl;
//        for (int i = 1; i <= T.length; ++i) {
//            cout << next[i] << ends;
//        }
        cout<<endl;
        if (j == 0 || T.ch[i] == T.ch[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }

}

void get_next(SString T, int next[]) {
    int i = 1, j = 0;
    next[i] = 0;
    while (i < T.length) {
        cout << i << " " << T.ch[i] << " " << T.ch[j] << endl;
        if (j == 0 || T.ch[i] == T.ch[j]) {
            ++i;
            ++j;
            //若pi=pj，则next[j+1]=next[j]+1
            next[i] = j;
        } else
            //否则令j=next[j]，循环继续
            j = next[j];
    }
}

void Print(SString &S) {
    for (int i = 1; i <= S.length; ++i) {
        cout << S.ch[i] << ends;
    }
    cout << endl;
}

void Print2(SString S) {
    for (int i = 1; i <= S.length; ++i) {
        cout << S.ch[i] << ends;
    }
    cout << endl;
}

int main() {
    cout << "hello world" << endl;
    SString S, T;
    string content1 = "AABCCCAABB";
    string content2 = "abaabcaba";
    Insert(S, content1);
    Insert(T, content2);
    cout << (S.length) << endl;
    cout << (S.ch[0]) << endl;
    Print(S);
    Print(T);
    int next[T.length];
    GetNext(T, next);
    for (int i = 1; i <= T.length; ++i) {
        cout << next[i] << ends;
    }

    return 0;
}