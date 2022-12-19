
#include<iostream>
#include <queue>

//二叉树

#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

using namespace std;

typedef struct node {
    char data;    // 数据域
    node *lchild, *rchild;    // 左右指针域
} BNode, *BTree;

class Bitree {

public:
    Bitree() { root = Creat(root); }

    ~Bitree() { Release(); }

    void PreOlder() {
        PreOrderTraverse(this->root);
        cout << endl;
    }

    void InOlder() {
        InOrderTraverse(this->root);
        cout << endl;
    }

    void PostOlder() {
        PostOrderTraverse(this->root);
        cout << endl;
    }

    void BinOlder() {
        BinaryOrder(this->root);
        cout << endl;
    }

    void Release() {
        re(this->root);
    }

private:
    BTree root;

    //（1）初始化二叉链表：理解扩展二叉树及其前序遍历序列；
    BTree Creat(BTree bt) {
        char ch;
        cin >> ch;  // 输入结点的数据信息，假设为字符
        if (ch == '#')      // 建立一棵空树
            bt = NULL;
        else {
            bt = new node; // 生成一个结点，数据域为ch
            bt->data = ch;
            bt->lchild = Creat(bt->lchild); // 递归建立左子树
            bt->rchild = Creat(bt->rchild); // 递归建立右子树
        }
        return bt;
    }

//（2）前序遍历二叉链表（递归实现）；

    Status PreOrderTraverse(BTree bt) {
        if (bt) {
            cout << bt->data ;
            PreOrderTraverse(bt->lchild);
            PreOrderTraverse(bt->rchild);
        }
        return OK;
    }

//（3）中序遍历二叉链表（递归实现）；
    Status InOrderTraverse(BTree bt) {
        if (bt) {
            InOrderTraverse(bt->lchild);
            cout << bt->data;
            InOrderTraverse(bt->rchild);
        }
        return OK;
    }

//（4）后序遍历二叉链表（递归实现）；
    Status PostOrderTraverse(BTree bt) {
        if (bt) {
            PostOrderTraverse(bt->lchild);
            PostOrderTraverse(bt->rchild);
            cout << bt->data;
        }
        return OK;
    }

//（5）层序遍历二叉链表

    void BinaryOrder(BTree root) {
        queue<BTree> q;
        //树为空，直接返回
        if (root == nullptr) {
            cout << "空" << endl;
            return;
        }
        //先将根节点入队
        q.push(root);
        while (!q.empty()) {
            //出队保存队头并访问
            BTree front = q.front();
            cout << front->data;
            q.pop();
            //将出队结点的左子树根入队
            if (front->lchild)
                q.push(front->lchild);
            //将出队结点的右子树根入队
            if (front->rchild)
                q.push(front->rchild);
        }
    }

//（6）销毁二叉链表（递归实现）。
    void re(BTree bt) {
        if (bt != nullptr) {
            re(bt->lchild);    // 释放左子树
            re(bt->rchild);    // 释放右子树
            delete bt;  // 释放根节点
        }
    }


};

int main() {
    Bitree a;//ABD##E##CF##G##
    a.InOlder();//DBEAFCG
    a.PostOlder();//DEBFGCA
    a.PreOlder();//ABDECFG
    a.BinOlder();//ABCDEFG
    a.Release();
}