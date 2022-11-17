
#include<iostream>

using namespace std;
//单链表
#define OK 1
#define ERROR 0
#define MAXSIZE 100
#define OVERFLOW -2
typedef int Status;

typedef struct Node {
    int data;
    Node* next;
} node,*LinkList;

//初始化单链表
LinkList creat(int num) {
    LinkList head, p, q;
    q = head = new node;
    head->next = nullptr;
    for (int i = 0; i < num; i++) //循环每次new一个新结点
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

//求单链表长度
Status len(LinkList L) {
    LinkList p = L->next;
    int i = 0;
    while (p) {
        i++;
        p = p->next;
    }
    return i;
}

//按位置查找
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

//按值查找
node *Locatedget(LinkList L, int e) {
    LinkList p = L->next;
    while (p && p->data != e) {
        p = p->next;
    }
    return p;
}

//在位置i插入一个元素
void insert(LinkList head, int index, int element) {
    LinkList p = head->next;
    int j = 1;
    while (j < index - 1 && p != nullptr) {
        p = p->next;
        j++;
    }//p 是index-1的位置  j 是index - 1
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

//删除位置i的元素
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

//遍历单链表
void show(LinkList head) {
    LinkList p = head->next;
    while (p != nullptr) {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

//合并链表
LinkList combine(LinkList a, LinkList b) {
    LinkList p = a;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = b->next;
    return a;
}

//销毁单链表
void del(LinkList &L) {
    LinkList tmp;
    while (L != nullptr) {
        tmp = L->next;
        delete L; // 依次释放结点。
        L = tmp;
    }

    L = nullptr; // 将链表指针置空。
    cout << "链表已删除";
}

int main() {
    LinkList s = creat(10);
    cout << "初始化：";
    show(s);
    cout << endl << "长度为" << len(s) << endl;
    int index, element;
    cout << "插入的位置";
    cin >> index;
    cout << "要插入的数";
    cin >> element;
    insert(s, index, element);
    cout << "插入后:";
    show(s);
    delate(s, index);
    cout << "删除后:";
    show(s);
    LinkList b = creat(20);
    cout << "b:";
    show(b);
    combine(s, b);
    cout << "s:";
    show(s);
    del(s);
}