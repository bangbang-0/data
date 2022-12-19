
#include<iostream>
#include <queue>

//������

#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

using namespace std;

typedef struct node {
    char data;    // ������
    node *lchild, *rchild;    // ����ָ����
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

    //��1����ʼ���������������չ����������ǰ��������У�
    BTree Creat(BTree bt) {
        char ch;
        cin >> ch;  // �������������Ϣ������Ϊ�ַ�
        if (ch == '#')      // ����һ�ÿ���
            bt = NULL;
        else {
            bt = new node; // ����һ����㣬������Ϊch
            bt->data = ch;
            bt->lchild = Creat(bt->lchild); // �ݹ齨��������
            bt->rchild = Creat(bt->rchild); // �ݹ齨��������
        }
        return bt;
    }

//��2��ǰ��������������ݹ�ʵ�֣���

    Status PreOrderTraverse(BTree bt) {
        if (bt) {
            cout << bt->data ;
            PreOrderTraverse(bt->lchild);
            PreOrderTraverse(bt->rchild);
        }
        return OK;
    }

//��3������������������ݹ�ʵ�֣���
    Status InOrderTraverse(BTree bt) {
        if (bt) {
            InOrderTraverse(bt->lchild);
            cout << bt->data;
            InOrderTraverse(bt->rchild);
        }
        return OK;
    }

//��4������������������ݹ�ʵ�֣���
    Status PostOrderTraverse(BTree bt) {
        if (bt) {
            PostOrderTraverse(bt->lchild);
            PostOrderTraverse(bt->rchild);
            cout << bt->data;
        }
        return OK;
    }

//��5�����������������

    void BinaryOrder(BTree root) {
        queue<BTree> q;
        //��Ϊ�գ�ֱ�ӷ���
        if (root == nullptr) {
            cout << "��" << endl;
            return;
        }
        //�Ƚ����ڵ����
        q.push(root);
        while (!q.empty()) {
            //���ӱ����ͷ������
            BTree front = q.front();
            cout << front->data;
            q.pop();
            //�����ӽ��������������
            if (front->lchild)
                q.push(front->lchild);
            //�����ӽ��������������
            if (front->rchild)
                q.push(front->rchild);
        }
    }

//��6�����ٶ��������ݹ�ʵ�֣���
    void re(BTree bt) {
        if (bt != nullptr) {
            re(bt->lchild);    // �ͷ�������
            re(bt->rchild);    // �ͷ�������
            delete bt;  // �ͷŸ��ڵ�
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