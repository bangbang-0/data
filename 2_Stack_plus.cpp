
#include<iostream>
#include <string>
//链栈
using namespace std;

#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

using namespace std;


typedef struct sqstack {
    ElemType data;          //数据域
    sqstack *next;          //指针域
} *Sqstack;
//（1）初始化
Status InitStack(Sqstack &S) /*链栈的初始化*/
{
    Sqstack head = new sqstack;  //头结点
    head->next = nullptr;
    S = head;
    return OK;
}

//（2）入栈
Status Push(Sqstack &S, ElemType e) {
    Sqstack p = new sqstack;
    if(!p)return OVERFLOW;
    p->data = e;     //赋值
    p->next = S->next; //插入头结点和首元结点之间
    S->next = p;     // 用头结点索引
    return OK;
}

//（3）出栈
Status Pop(Sqstack &S, ElemType &e) {
    if(S->next) {       //如果非空
        Sqstack p = S->next;
        e = p->data;
        S->next = p->next;   //将次元结点和头结点连接
        delete p;  //删除首元结点
        return OK;
    }
    else return ERROR;
}

//（4）读栈顶元素；
Status GetTop(Sqstack S, ElemType &e) //取栈顶
{
    if (S->next) {
        e = S->next->data;
        return OK;
    } else return ERROR;
}

//（5）判定栈空/满操作；
bool StackEmpty(Sqstack &S)//栈判空
{
    return S->next == nullptr;
}

//（6）销毁链栈。
Status DestroyStack(Sqstack &S) {
    while (S->next)
    {
        Sqstack p=S->next;
        S->next=p->next;
        delete p;
    }
    delete S;
    return OK;
}
int StackLength(Sqstack S)
{
    int len =0;
    Sqstack p=S->next;
    cout<<"head"<<"->";
    while(p) //遍历得到长度
    {
        cout<<p->data<<" -> ";
        p=p->next;
        ++len;
    }
    cout<<"nullptr"<<endl;
    return len;
}

int main() {
    int choose = -1;
    ElemType e;
    Sqstack S;
    InitStack(S); cout << "链栈:" << endl << endl;
    cout << "1. 链栈的初始化" << endl;
    cout << "2. 栈是否为空" << endl;
    cout << "3. 链栈的长度" << endl;
    cout << "4. 销毁链栈" << endl;
    cout << "5. 入栈" << endl;
    cout << "6. 出栈" << endl;
    cout << "7. 取栈顶元素" << endl;
    cout << "0. 退出" << endl << endl;

    while (choose != 0) {

        cout << "请选择操作：" << endl;		//输入选择
        do {
            cin >> choose;
            if (choose < 0 || choose>7)
                cout << "输入错误,请重新输入:" << endl;
        } while (choose < 0 || choose>7);
        switch (choose)
        {
            case 1:
                if (InitStack(S))  cout << "链栈初始化成功！" << endl << endl;
                else cout << "顺序栈初始化失败！" << endl << endl;;
                break;
            case 2:
                if (StackEmpty(S))	cout << "链栈为空！" << endl << endl;
                else cout << "链栈不为空！" << endl << endl;
                break;
            case 3:
                cout << "此时栈内共有" << StackLength(S) << "个元素" << endl<<endl;
                break;
            case 4:
                if (DestroyStack(S)) cout << "销毁链栈成功" << endl << endl;
                break;
            case 5:
                cout << "请输入" << endl;
                cin >> e;
                if (Push(S, e))	cout << "该元素入栈成功" << endl << endl;
                break;
            case 6:
                if(Pop(S, e)) {
                    cout << "出栈元素为：" << endl;
                    cout << e << endl << endl;
                } else cout<<"链栈为空！"<<endl;
                break;
            case 7:
                GetTop(S, e);
                cout << "栈顶的元素为：" << endl;
                cout << e << endl << endl;
                break;
            default:break;
        }
    }
    return 0;
}