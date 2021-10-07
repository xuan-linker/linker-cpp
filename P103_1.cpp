//
// Created by Linker on 10/7/2021.
//https://blog.csdn.net/weixin_44990847/article/details/119877820
//

#include "iostream"

using namespace std;

#define MaxSize 255
typedef struct {
    char ch[MaxSize]; //每个分量存储一个字符
    int length = 0;       //串的实际长度
} SString;

typedef struct {
    char *ch;       //按串长分配存储区，ch指向串的基地址
    int length = 0;     //串的长度
} HString;

void StrAssign(SString &T, char chars[]) {
    int size = sizeof(chars) / sizeof(chars[0]);
    for (int i = 0; i < size; ++i) {
        T.ch[i] = chars[i];
    }
    T.length = size;
}

void StrCopy(SString &T, SString S) {
    T.length = S.length;
    for (int i = 0; i < S.length; ++i) {
        T.ch[i] = S.ch[i];
    }
}

//求子串，用sub返回串S的第pos个字符起长度为Len的字符 ,pos首字母为0
bool SubString(SString &Sub, SString S, int pos, int len) {
    if (pos + len > S.length) {
        return false;
    }
    for (int i = pos; i < pos + len; ++i) {
        Sub.ch[i - pos] = S.ch[i];
    }
    Sub.length = len;
    return true;
}

bool StrEmpty(SString S) {
    if (S.length == 0) {
        return true;
    } else {
        return false;
    }
}

int StrLength(SString S) {
    return S.length;
}

bool Concat(SString &T, SString S1, SString S2) {
    for (int i = 0; i < S1.length; ++i) {
        T.ch[i] = S1.ch[i];
    }
    for (int i = S1.length; i < S1.length + S2.length; ++i) {
        T.ch[i] = S2.ch[i - S1.length];
    }
    T.length = S1.length + S2.length;
    return true;
}

void ClearString(SString &S) {
    S.length = 0;
}

void DestroyString(SString &S) {
    free(S.ch);
    //...
}

//比较操作，若S>T，则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0
int StrCompare(SString S, SString T) {
    for (int i = 0; i < S.length && i < T.length; ++i) {
        if (S.ch[i] != T.ch[i]) {
            return S.ch[i] - T.ch[i];
        }
    }
    return S.length - T.length;
}

int Index(SString S, SString T) {
    int i = 0;
    int n = S.length;
    int m = T.length;
    while (i <= n - m) {
        SString Sub;
        SubString(Sub, S, i, m);
        if (StrCompare(Sub, T) != 0) {
            ++i; //失败
        } else {
            return i; //成功
        }
    }
    return -1;
}

//朴素模式匹配算法
int Index_1(SString S, SString T) {
    int i = 0, j = 0;
    while (i < S.length && j < T.length) {
        if (S.ch[i] == T.ch[j]) { //逐个比较
            ++i;
            ++j;
        } else {
            i = i - j + 1; //回退并重置，i=i+1,j=0
            j = 0;
        }
    }
    if (j >= T.length) { //若比较完毕
        return i - T.length;
    } else {
        return -1;
    }
}

void Print(SString S) {
    for (int i = 0; i < S.length; ++i) {
        cout << S.ch[i] << ends;
    }
    cout << endl;
}
//
////模式串T的next数组
//void GetNext(SString T, int next[]) {
//    int i = 0, j = -1;
//    next[0] = -1;
//    while (i < T.length - 1) {
//        if (j == -1 || T.ch[i] == T.ch[j]) {
//            ++i;
//            ++j;
//            next[i] = j;
//        } else {
//            j = next[j];
//        }
//    }
//}
//
//int Kmp(SString S, SString T) {
//    int i = 0, j = -1;
//    int next[T.length];
//    GetNext(T, next);
//    while (i < S.length && i < T.length) {
//        if (j == -1 || S.ch[i] == T.ch[j]) {
//            i++;
//            j++;
//        } else {
//            j = next[j];
//        }
//    }
//    if (j >= T.length) {
//        return i - T.length;
//    } else {
//        return 0;
//    }
//
//}

int main() {
    cout << "hello world" << endl;
    SString S, T;
    for (int i = 0; i < 10; ++i) {
        char c = 'A';
        int num = c + i;
        char c1 = num;
        S.ch[S.length++] = c1;
    }
    for (int i = 0; i < 5; ++i) {
        char c = 'B';
        int num = c + i;
        char c1 = num;
        T.ch[T.length++] = c1;
    }
    Print(S);
    Print(T);

    int res = Index(S, T);
    cout << res << endl;
    int res2 = Index_1(S, T);
    cout << res2 << endl;


    return 0;
}