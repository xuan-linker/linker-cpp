//
// Created by Linker on 10/6/2021.
//
#include "iostream"
#include "stack"

using namespace std;

bool Compare(char arr[]) {
    stack<char> s;
    for (int i = 0; arr[i] != '\0'; ++i) {
        char x;
        switch (arr[i]) {
            //左侧入stack
            case '(':
                s.push(arr[i]);
                break;
            case '{':
                s.push(arr[i]);
                break;
            case '[':
                s.push(arr[i]);
                break;
                //右侧出stack
            case ')': {
                char c = s.top();
                s.pop();
                if (c == '(')break;
                else return false;
            }
            case '}': {
                char c = s.top();
                s.pop();
                if (c == '{')break;
                else return false;
            }
            case ']': {
                char c = s.top();
                s.pop();
                if (c == '[')break;
                else return false;
            }
            default:
                break;
        }
    }
    if (s.empty()) {
        cout << "{}[]()OK" << endl;
        return true;
    } else {
        cout << "{}[]()not" << endl;
        return false;
    }
}

int main() {
    cout << "hello world" << endl;
    char arr1[20] = {'{', '}', '{', '}', '{', '}', '[', ']', '(', ')', '\0'};
    char arr2[20] = {'(', '{', '}', ')', '{', '}', '[', '{', '}', ']', '[', ']', '(', ')', '\0'};
    char arr3[20] = {'(', ')', '\0'};
    Compare(arr3);
    return 0;
}