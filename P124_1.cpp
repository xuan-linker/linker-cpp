//
// Created by Linker on 10/7/2021.
// 顺序存储的二叉树 https://blog.csdn.net/weixin_44820625/article/details/106651743

#include "iostream"
#include "vector"

using namespace std;
typedef struct BiTNode {
    char data;
    BiTNode *lchild, *rchild;

    BiTNode() {
        lchild = NULL;
        rchild = NULL;
    }
} BiTNode, *BiTree;

bool InitBiTree(BiTree &T) {
    T = NULL;
    return true;
}

//前序遍历创建二叉树
void CreateBiTree(BiTree &T) {
    char ch;
    cin >> ch;
    if (ch == '#') {
        T = NULL;
    } else {
        T = new BiTNode();

        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

void Destroy(BiTree &T) {
    if (T) {
        Destroy(T->lchild);
        Destroy(T->rchild);
        delete (T);
        T = NULL;
    }
}

int TreeHeight(BiTree T) {
    if (T == NULL) {
        return 0;
    }
    int leftHeight = TreeHeight(T->lchild);
    int rightHeight = TreeHeight(T->rchild);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

void PreOrderTraverse(BiTree T) {
    if (T != NULL) {
        cout << T->data << ends;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void InOrderTraverse(BiTree T) {
    if (T != NULL) {
        InOrderTraverse(T->lchild);
        cout << T->data << ends;
        InOrderTraverse(T->rchild);
    }
}

void PostOrderTraverse(BiTree T) {
    if (T != NULL) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data << ends;
    }
}

BiTNode *PreOrderSaveTraverse(vector<int> v, int i) {
    cout << v.size() << endl;
    if (i > v.size()) {
        return nullptr;
    }
    if (v.at(i) != 0) {
        BiTNode *node = new BiTNode();
        node->data = v.at(i);
        node->lchild = PreOrderSaveTraverse(v, i * 2);
        node->rchild = PreOrderSaveTraverse(v, i * 2 + 1);
    } else {
        BiTNode *node = new BiTNode();
        return node;
    }
}


//ab#d##c##
int main() {
    cout << "Hello world" << endl;
    BiTree T;
    InitBiTree(T);
    CreateBiTree(T);
    cout << "前序遍历" << endl;
    PreOrderTraverse(T);
    cout << endl;
    cout << "中序遍历" << endl;
    InOrderTraverse(T);
    cout << endl;
    cout << "后序遍历" << endl;
    PostOrderTraverse(T);
    cout << endl;

    int height = TreeHeight(T);
    cout<<height<<endl;

    vector<int> v = {0, 1, 2, 3, 0, 4, 0, 5, 0, 0, 6, 0};


    return 0;
}