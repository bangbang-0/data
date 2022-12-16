
#include<iostream>
//二叉树

#define MAXSIZE 100
#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

using namespace std;

template<class T>
struct BiNode {
    T data;    // 数据域
    BiNode<T> *lchild, *rchild;    // 左右指针域
};

template<class T>
class Bitree {
public:
    Bitree() { root = Creat(root); }

    ~Bitree() { Release(root); }

    //（1）初始化二叉链表：理解扩展二叉树及其前序遍历序列；
    BiNode<T> *Creat(BiNode<T> *bt) {
        T ch;
        cin >> ch;  // 输入结点的数据信息，假设为字符
        if (ch == '#')      // 建立一棵空树
            bt = NULL;
        else {
            bt = new BiNode<T>; // 生成一个结点，数据域为ch
            bt->data = ch;
            bt->lchild = Creat(bt->lchild); // 递归建立左子树
            bt->rchild = Creat(bt->rchild); // 递归建立右子树
        }
        return bt;
    }

//（2）前序遍历二叉链表（递归实现）；
    Status PreOrderTraverse(BiNode<T> bt) {
        if (bt) {
            cout << bt->data;
            PreOrderTraverse(bt->lchild);
            PreOrderTraverse(bt->rchild);
        }
        return OK;
    }

//（3）中序遍历二叉链表（递归实现）；
    Status InOrderTraverse(BiNode<T> bt) {
        if (bt) {
            InOrderTraverse(bt->lchild);
            cout << bt->data;
            InOrderTraverse(bt->rchild);
        }
        return OK;
    }

//（4）后序遍历二叉链表（递归实现）；
    Status PostOrderTraverse(BiNode<T> bt) {
        if (bt) {
            PostOrderTraverse(bt->lchild);
            PostOrderTraverse(bt->rchild);
            cout << bt->data;
        }
        return OK;
    }

//（5）层序遍历二叉链表；

//（6）销毁二叉链表（递归实现）。
    void Release(BiNode<T> &bt) {
        if (bt != nullptr) {
            Release(bt->lchild);    // 释放左子树
            Release(bt->rchild);    // 释放右子树
            delete bt;  // 释放根节点
        }
    }


    BiNode<T> *root;
};
int main()
{
Bitree<char>* A=new Bitree<char>;
}