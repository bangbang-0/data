
//1.单链表

#include<iostream>

using namespace std;

typedef int ElemType;
typedef struct LNode {
    ElemType data;          //结点的数据域
    LNode *next;     //结点的指针域
} LNode, *LinkList;
void ListDisplay(LinkList &L);
//（1）初始化单链表（无参和有参）；
LinkList CreateList(int i = 0) { //参数默认为0 ,如有参数传入,参数代表链表长度,默认尾插法
    LinkList head = new LNode, p;//创建头结点head 和操作指针
    p = head; //赋值给操作指针
    head->next = nullptr; //置空
    if (i != 0) { //有参构造
        for (int j = 0; j < i; j++) {
            auto s = new LNode;  //创建新结点
            cout << "输入第" << j + 1 << "个数" << endl;
            cin >> s->data; //输入结点的数据
            p->next = s;  //将新结点的地址传给操作指针的next,让其连接
            p = s;   //相当于 p=p->next 移动操作指针到最后一个结点
        }
        p->next = nullptr;//尾结点置空
    } else { //无参构造函数 ,默认构建1-10
        for (int j = 0; j < 10; j++) {
            auto s = new LNode;
            s->data = j + 1; //赋值
            p->next = s; //连接
            p = s; //移动指针
        }
        p->next = nullptr;//置空
//        cout << "请输入单链表中的数据元素（输入-1时不做处理，输入结束）：" << endl;
//        int x;
//        cin >> x;
//        while (x != -1) {
//            auto s = new LNode;
//            s->data = x;
//            p->next = s;
//            p = s;
//            cin >> x;
//        }
//        p->next = nullptr;
    }
    return head;
}

//（2）求单链表长度；
void Listlenth(LinkList L) {
    int i = 0;//记录长度
    LinkList p = L->next;
    while (p) {//遍历直到 p==nullptr
        p = p->next;
        i++;//计数器++
    }
    cout << "length:" << i << endl;//打印长度
}

//（3）按位置查找；
ElemType GetElem(LinkList &L, int i) {//按位置查找,顺序查找，平均时间复杂度为O（n）
    LinkList p = L->next;
    int j = 1;//计数器
    while (p && j < i) {//遍历直到p指针指向第i个元素的结点
        p = p->next;
        ++j;
    }
    if (p == nullptr) { //防止输入的位置数大于结点数
        cout << "位置不合法,重新输入:" << endl;
        int x;
        cin >> x;
        GetElem(L, x);//重新调用函数
    }
    else {
        cout<<"第"<<i<<"个元素为"<<p->data<<endl;
        return p->data;
    }
}

//（4）按值查找；
LinkList LocateElem(LinkList &L, ElemType e) {//按值查找,顺序查找，平均时间复杂度为O（n）
    LinkList p = L->next;
    int x = 1;
    while (p && p->data != e) {//遍历直到p指向该值所在的结点
        p = p->next;//移动
        ++x;
    }
    if (!p) {
        cout << "链表中无此元素" << endl;
        return nullptr;//返回空指针
    } else {
        cout << "该元素是链表第" << x<< "个" << endl;
        return p;
    }
}

//（5）在位置i插入一个数据元素；
void ListInsert(LinkList &L, int i, ElemType e) {//在位置i插入一个数据元素：在序号为i-1的结点后插入结点，平均时间复杂度为O（n）
    LinkList p = L;//指针直接指向头结点,以便在位置0处插入
    int j = 0;
    while (p && j < i) {//指针移动到i位置前
        ++j;
        p = p->next;
    }
    if (p) {
        auto s = new LNode;//新建结点
        s->next = p->next; //该节点保存 p的next所指向的地址
        p->next = s; //刷新p->next 将s的地址赋值给p
        s->data = e; //s插入成功 ,赋值
        cout << "插入成功" << endl;
        ListDisplay(L);
    } else
        cout << "插入失败" << endl;
}

//（6）删除位置i的数据元素；
void ListDelete(LinkList &L, int i) {//删除位置i的一个数据元素,平均时间复杂度为O（n）
    LinkList p = L->next;
    int j = 1;//计数器
    while (p && j < i - 1) {//移动指针到要删除的结点的上一个结点
        ++j;
        p = p->next;
    }
    if (p) {//判断该结点是否存在
        LinkList s;
        s = p->next; //将要删除的结点
        p->next = s->next;//将要删除的结点的next指针保存的地址转移
        delete s;//删除结点
        cout << "删除成功" << endl;
        ListDisplay(L);
    } else cout << "删除失败" << endl;
}

//（7）遍历单链表；
void ListDisplay(LinkList &L) {//遍历
    LinkList p = L->next;
    while (p) {
        cout << p->data << "->";
        p = p->next;//移动指针
    }
    cout << "null" << endl;
}

//（8）合并链表
LinkList MergeList(LinkList &LA, LinkList &LB) {
    LinkList p = LA;//创建操作指针
    while (p->next) {
        p = p->next;
    }//移动操作指针到尾结点
    p->next = LB->next;//尾结点的next指向 LB头指针的第一个结点
    delete LB;//删除无用头结点
    return LA;
}

//（9）销毁单链表
void del(LinkList &L) {
    LinkList tmp;
    while (L->next != nullptr) {
        tmp = L->next;
        delete L; // 依次释放结点。
        L = tmp;
    }
    L = nullptr; // 将链表指针置空。
    cout << "链表已删除";
}

int main() {
    LinkList s = CreateList();//无参构造
    ListDisplay(s);//遍历展示链表
    Listlenth(s);//输出链表的长度
    int i, e;
    i = 5;
    GetElem(s, i);//按位置查找第5个元素
    i = 7;
    LocateElem(s, i);//按值查找元素7
    i =0,e=0;
    cout<<"在0位置插入值0"<<"......";
    ListInsert(s, i, e);//在0位置插入值0
    i=11;
    cout<<"删除第11位置的结点"<<"......";
    ListDelete(s, i);//删除第11位置的结点
    cout<<"输入三个数"<<endl;
    LinkList b = CreateList(3);//有参构造
    MergeList(s, b); //合并链表
    cout<<"合并后:"<<endl;
    ListDisplay(s);
    del(s); //删除链表
    return 0;
}