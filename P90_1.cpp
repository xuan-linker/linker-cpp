//
// Created by Linker on 10/6/2021.
// {},[],()括号匹配
//

#include "iostream"
#include "array"
#include <vector>
#include <iterator>

using namespace std;
#define MaxSize 50
typedef struct Stack {
    char data[MaxSize];
    int top = -1;
};

bool IsEmpty(Stack &S) {
    if (S.top == -1) {
        return true;
    } else {
        return false;
    }
}

bool IsFull(Stack &S) {
    if (S.top + 1 == MaxSize) {
        return true;
    } else {
        return false;
    }
}

bool Push(Stack &S, int x) {
    if (IsFull(S)) {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

bool Pop(Stack &S, int &x) {
    if (IsEmpty(S)) {
        return false;
    }
    x = S.data[S.top--];
    return true;
}

bool Compare(char arr[], Stack &S) {
    for (int i = 0; arr[i] != '\0'; ++i) {
        if (arr[i] == '\0') {
            break;
        }
        if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[') {
            S.data[++S.top] = arr[i];
        } else if (arr[i] == ')') {
            char c = S.data[S.top--];
            if (c == '(') {
                continue;
            } else {
                return false;
            }
        } else if (arr[i] == '}') {
            char c = S.data[S.top--];
            if (c == '{') {
                continue;
            } else {
                return false;
            }
        } else if (arr[i] == ']') {
            char c = S.data[S.top--];
            if (c == '[') {
                continue;
            } else {
                return false;
            }
        }
    }
    if (S.top != -1) {
        return false;
    } else {
        return true;
    }

}

int main() {
    cout << "hello world" << endl;
    Stack S;
    char arr1[20] = {'{', '}', '{', '}', '{', '}', '[', ']', '(', ')', '\0'};
    char arr2[20] = {'(', '{', '}', ')', '{', '}', '[', '{', '}', ']', '[', ']', '(', ')', '\0'};

    bool res = Compare(arr2, S);
    cout << res << endl;
    return 0;
}
