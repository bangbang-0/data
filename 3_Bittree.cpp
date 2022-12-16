
#include<iostream>
//������

#define MAXSIZE 100
#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

using namespace std;

template<class T>
struct BiNode {
    T data;    // ������
    BiNode<T> *lchild, *rchild;    // ����ָ����
};

template<class T>
class Bitree {
public:
    Bitree() { root = Creat(root); }

    ~Bitree() { Release(root); }

    //��1����ʼ���������������չ����������ǰ��������У�
    BiNode<T> *Creat(BiNode<T> *bt) {
        T ch;
        cin >> ch;  // �������������Ϣ������Ϊ�ַ�
        if (ch == '#')      // ����һ�ÿ���
            bt = NULL;
        else {
            bt = new BiNode<T>; // ����һ����㣬������Ϊch
            bt->data = ch;
            bt->lchild = Creat(bt->lchild); // �ݹ齨��������
            bt->rchild = Creat(bt->rchild); // �ݹ齨��������
        }
        return bt;
    }

//��2��ǰ��������������ݹ�ʵ�֣���
    Status PreOrderTraverse(BiNode<T> bt) {
        if (bt) {
            cout << bt->data;
            PreOrderTraverse(bt->lchild);
            PreOrderTraverse(bt->rchild);
        }
        return OK;
    }

//��3������������������ݹ�ʵ�֣���
    Status InOrderTraverse(BiNode<T> bt) {
        if (bt) {
            InOrderTraverse(bt->lchild);
            cout << bt->data;
            InOrderTraverse(bt->rchild);
        }
        return OK;
    }

//��4������������������ݹ�ʵ�֣���
    Status PostOrderTraverse(BiNode<T> bt) {
        if (bt) {
            PostOrderTraverse(bt->lchild);
            PostOrderTraverse(bt->rchild);
            cout << bt->data;
        }
        return OK;
    }

//��5�����������������

//��6�����ٶ��������ݹ�ʵ�֣���
    void Release(BiNode<T> &bt) {
        if (bt != nullptr) {
            Release(bt->lchild);    // �ͷ�������
            Release(bt->rchild);    // �ͷ�������
            delete bt;  // �ͷŸ��ڵ�
        }
    }


    BiNode<T> *root;
};
int main()
{
Bitree<char>* A=new Bitree<char>;
}