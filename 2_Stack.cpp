
//顺序栈
#include <iostream>

using namespace std;
#define MAXSIZE 100
#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;
typedef struct {
    int stacksize;
    ElemType *top;
    ElemType *base;
} Sqstack;

//（1）初始化顺序栈；
Status InitStack(Sqstack &S) /*顺序栈的初始化*/
{
    S.base = new ElemType[MAXSIZE];
    if (!S.base) return OVERFLOW;
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}

//（2）入栈
Status Push(Sqstack &S, ElemType e) {
    if (S.top - S.base == S.stacksize)return ERROR;
    *S.top++ = e;
    return OK;
}

//（3）出栈
Status Pop(Sqstack &S, ElemType &e) {
    if (S.base == S.top) return ERROR;
    e = *--S.top;
    return OK;
}

//（4）读栈顶元素；
Status GetTop(Sqstack S, ElemType &e) //取栈顶
{
    if (S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}

//（5）判定栈空/满操作；
bool StackEmpty(Sqstack &S)//栈判空
{
    if (S.top == S.base)return ERROR;
    else return OK;
}

//（6）销毁顺序栈。
Status DestroyStack(Sqstack &S) {
    if (S.base) {
        delete S.base;
        S.top = S.base = nullptr;
        S.stacksize = 0;
    }
    return OK;
}

int StackLength(Sqstack S)//求栈长
{
    return S.top-S.base;
}

int main()
{
    int choose = -1;
    ElemType e;		//定义一个结构体的元素e
    Sqstack S;		//定义一个顺序栈的变量S
    InitStack(S);		//初始化顺序栈
    cout << "顺序栈:" << endl << endl;
    cout << "1. 顺序栈的初始化" << endl;
    cout << "2. 判断栈是否为空" << endl;
    cout << "3. 判断顺序栈的长度" << endl;
    cout << "4. 销毁顺序栈" << endl;
    cout << "5. 顺序栈入栈" << endl;
    cout << "6. 顺序栈出栈" << endl;
    cout << "7. 取顺序栈顶元素" << endl;
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
                if (InitStack(S))  cout << "顺序栈初始化成功！" << endl << endl;
                else cout << "顺序栈初始化失败！" << endl << endl;;
                break;
            case 2:
                if (StackEmpty(S))	cout << "此顺序栈为空！" << endl << endl;
                else cout << "此顺序栈不为空！" << endl << endl;
                break;
            case 3:
                cout << "此时栈内共有" << StackLength(S) << "个元素" << endl<<endl;
                break;
            case 4:
                if (DestroyStack(S)) cout << "销毁顺序表成功" << endl << endl;
                break;
            case 5:
                cout << "请输入" << endl;
                cin >> e;
                if (Push(S, e))	cout << "该元素入栈成功" << endl << endl;
                break;
            case 6:
                Pop(S, e);
                cout << "出栈元素为：" << endl;
                cout << e<< endl<<endl;
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