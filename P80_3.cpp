//
// Created by linker on 2021/10/6.
//

#include "iostream"

using namespace std;

#define MaxSize 5
typedef struct Stack {
    int data[MaxSize];
    int top = -1;
};

bool StackEmpty(Stack &S) {
    if (S.top == -1) {
        return true; //空
    } else {
        return false; //非空
    }
}

bool StackOverflow(Stack &S) {
    if (S.top + 1 == MaxSize) {
        return true; // 满
    } else {
        return false; //不满
    }
}

bool Push(Stack &S, int x) {
    if (StackOverflow(S)) {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

bool Pop(Stack &S, int &x) {
    if (StackEmpty(S)) {
        return false;
    }
    x = S.data[S.top--];
    return true;
}

void S1ToS2(Stack &S1, Stack &S2) {
    //S1->S2
    for (int i = 0; i < MaxSize; ++i) {
        int s = -1;
        Pop(S1, s);
        Push(S2, s);
    }
}

bool EnQueue(Stack &S1, Stack &S2, int x) {
    if (StackOverflow(S1) == true) {
        if (StackEmpty(S2) == true) {
            //S1->S2
            S1ToS2(S1, S2);
            Push(S1, x);
            return true;
        } else if (StackEmpty(S2) == false) {
            return false;
        }
    } else if (StackOverflow(S1) == false) {
        Push(S1, x);
        return true;
    }
}

bool QueueEmpty(Stack S1, Stack S2) {
    if (StackEmpty(S1) && StackEmpty(S2)) {
        return true;//空
    } else {
        return false;
    }
}

bool Dequeue(Stack &S1, Stack &S2, int &x) {
    if (QueueEmpty(S1, S2)) {
        return false;
    }
    if (StackEmpty(S2) == true) {
        S1ToS2(S1, S2);
        Pop(S2, x);
        return true;
    } else if (StackEmpty(S2) == false) {
        Pop(S2, x);
        return true;
    }
    return false;

}


int main() {
    cout << "hello world" << endl;
    // ->S1-left->S2-right->
    Stack S1, S2;
    for (int i = 0; i < 20; ++i) {
        bool flag = EnQueue(S1, S2, i);
        cout << flag << " " << i << ends;
    }
    cout << endl;

    for (int i = 0; i < 20; ++i) {
        int x = -1;
        bool flag = Dequeue(S1, S2, x);
        if (flag) {
            cout << x << ends;
        }
    }
    cout << endl;
    return 0;
}