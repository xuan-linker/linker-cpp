//
// Created by Linker on 10/6/2021.
//
#include "iostream"
#include "stack"

using namespace std;

char *TurnTrain(char arr[], int size, char res[]) {
    stack<char> s;
    int count = 0;
    for (int i = 0; i < size; ++i) {
        s.push(arr[i]);
        if (arr[i] == 'H') {
        } else if (arr[i] == 'S') {
            res[count++] = s.top();
            s.pop();
        }
    }
    while (!s.empty()) {
        res[count++] = s.top();
        s.pop();
    }
    return res;

}

int main() {
    cout << "hello world" << endl;

    string str = "HHSHSHSHHHHHSSSS";
    int size = str.end() - str.begin();
    char arr[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = str.at(i);
    }
    char res[size];

    TurnTrain(arr, size, res);
    for (int i = 0; i < size; ++i) {
        cout << res[i] << ends;
    }
    return 0;
}
