//
// Created by Linker on 10/1/2021.
//

#include <iostream>
#include <algorithm>

using namespace std;
#define MaxSize 50

//typedef struct {
//    int length;
//    int data[MaxSize];
//} SqList;
class SqList {
public:
    int data[MaxSize];
    int length;

};

int main() {
//    std::cout << "Hello, World!" << std::endl;
    int x = 10;
    int y = 20;
    int sum = x + y;
    int myData[10];
    for (int i = 0; i < 10; ++i) {
        myData[i] = i;
    }


    std::cout<<myData<<std::endl;
    std::cout<<sizeof(myData)<<std::endl;
    std::cout<<sizeof(myData)/sizeof(myData[0])<<std::endl;
    for (int i = 0; i < sizeof(myData)/sizeof(myData[0]); ++i) {
//        printf("%d",myData[i]);
        cout<<&myData[i]<<endl;
        cout<<myData[i]<<endl;
    }

    return 0;
}
