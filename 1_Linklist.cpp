
#include<iostream>

using namespace std;
//������
#define OK 1
#define ERROR 0
#define MAXSIZE 100
#define OVERFLOW -2
typedef int Status;

typedef struct Node {
    int data;
    Node* next;
} node,*LinkList;

//��ʼ��������
LinkList creat(int num) {
    LinkList head, p, q;
    q = head = new node;
    head->next = nullptr;
    for (int i = 0; i < num; i++) //ѭ��ÿ��newһ���½��
    {
        p = new node;
        p->data = i + 1;
        p->next = nullptr;
        if (head->next == nullptr)
            head->next = p;
        else
            q->next = p;
        q = p;
    }
    q->next = nullptr;
    return head;
}

//��������
Status len(LinkList L) {
    LinkList p = L->next;
    int i = 0;
    while (p) {
        i++;
        p = p->next;
    }
    return i;
}

//��λ�ò���
int Get(LinkList L, int index, int re) {
    LinkList p = L->next;
    int j = 1;
    while (p && j < index) {
        p = p->next;
        ++j;
    }
    if (!p || j > index)return -1;
    re = p->data;
    return re;
}

//��ֵ����
node *Locatedget(LinkList L, int e) {
    LinkList p = L->next;
    while (p && p->data != e) {
        p = p->next;
    }
    return p;
}

//��λ��i����һ��Ԫ��
void insert(LinkList head, int index, int element) {
    LinkList p = head->next;
    int j = 1;
    while (j < index - 1 && p != nullptr) {
        p = p->next;
        j++;
    }//p ��index-1��λ��  j ��index - 1
    if (index == 1) {
        LinkList s;
        s = new node;
        s->data = element;
        head->next = s;
        s->next = p;
        return;
    } else if (j > index || !p)
        return;
    LinkList s;
    s = new node;
    s->data = element;
    s->next = p->next;
    p->next = s;
}

//ɾ��λ��i��Ԫ��
Status delate(LinkList &L, int i) {
    LinkList p = L;
    int j = 0;
    while ((p->next) && (j < i - 1)) {
        p = p->next;
        ++j;
    }
    if (!(p->next) || (j > i - 1))return -1;
    LinkList q = p->next;
    p->next = q->next;
    delete q;
    return 0;
}

//����������
void show(LinkList head) {
    LinkList p = head->next;
    while (p != nullptr) {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

//�ϲ�����
LinkList combine(LinkList a, LinkList b) {
    LinkList p = a;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = b->next;
    return a;
}

//���ٵ�����
void del(LinkList &L) {
    LinkList tmp;
    while (L != nullptr) {
        tmp = L->next;
        delete L; // �����ͷŽ�㡣
        L = tmp;
    }

    L = nullptr; // ������ָ���ÿա�
    cout << "������ɾ��";
}

int main() {
    LinkList s = creat(10);
    cout << "��ʼ����";
    show(s);
    cout << endl << "����Ϊ" << len(s) << endl;
    int index, element;
    cout << "�����λ��";
    cin >> index;
    cout << "Ҫ�������";
    cin >> element;
    insert(s, index, element);
    cout << "�����:";
    show(s);
    delate(s, index);
    cout << "ɾ����:";
    show(s);
    LinkList b = creat(20);
    cout << "b:";
    show(b);
    combine(s, b);
    cout << "s:";
    show(s);
    del(s);
}