
//˳��ջ
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

//��1����ʼ��˳��ջ��
Status InitStack(Sqstack &S) /*˳��ջ�ĳ�ʼ��*/
{
    S.base = new ElemType[MAXSIZE];
    if (!S.base) return OVERFLOW;
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}

//��2����ջ
Status Push(Sqstack &S, ElemType e) {
    if (S.top - S.base == S.stacksize)return ERROR;
    *S.top++ = e;
    return OK;
}

//��3����ջ
Status Pop(Sqstack &S, ElemType &e) {
    if (S.base == S.top) return ERROR;
    e = *--S.top;
    return OK;
}

//��4����ջ��Ԫ�أ�
Status GetTop(Sqstack S, ElemType &e) //ȡջ��
{
    if (S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}

//��5���ж�ջ��/��������
bool StackEmpty(Sqstack &S)//ջ�п�
{
    if (S.top == S.base)return ERROR;
    else return OK;
}

//��6������˳��ջ��
Status DestroyStack(Sqstack &S) {
    if (S.base) {
        delete S.base;
        S.top = S.base = nullptr;
        S.stacksize = 0;
    }
    return OK;
}

int StackLength(Sqstack S)//��ջ��
{
    return S.top-S.base;
}

int main()
{
    int choose = -1;
    ElemType e;		//����һ���ṹ���Ԫ��e
    Sqstack S;		//����һ��˳��ջ�ı���S
    InitStack(S);		//��ʼ��˳��ջ
    cout << "˳��ջ:" << endl << endl;
    cout << "1. ˳��ջ�ĳ�ʼ��" << endl;
    cout << "2. �ж�ջ�Ƿ�Ϊ��" << endl;
    cout << "3. �ж�˳��ջ�ĳ���" << endl;
    cout << "4. ����˳��ջ" << endl;
    cout << "5. ˳��ջ��ջ" << endl;
    cout << "6. ˳��ջ��ջ" << endl;
    cout << "7. ȡ˳��ջ��Ԫ��" << endl;
    cout << "0. �˳�" << endl << endl;

    while (choose != 0) {

        cout << "��ѡ�������" << endl;		//����ѡ��
        do {
            cin >> choose;
            if (choose < 0 || choose>7)
                cout << "�������,����������:" << endl;
        } while (choose < 0 || choose>7);
        switch (choose)
        {
            case 1:
                if (InitStack(S))  cout << "˳��ջ��ʼ���ɹ���" << endl << endl;
                else cout << "˳��ջ��ʼ��ʧ�ܣ�" << endl << endl;;
                break;
            case 2:
                if (StackEmpty(S))	cout << "��˳��ջΪ�գ�" << endl << endl;
                else cout << "��˳��ջ��Ϊ�գ�" << endl << endl;
                break;
            case 3:
                cout << "��ʱջ�ڹ���" << StackLength(S) << "��Ԫ��" << endl<<endl;
                break;
            case 4:
                if (DestroyStack(S)) cout << "����˳���ɹ�" << endl << endl;
                break;
            case 5:
                cout << "������" << endl;
                cin >> e;
                if (Push(S, e))	cout << "��Ԫ����ջ�ɹ�" << endl << endl;
                break;
            case 6:
                Pop(S, e);
                cout << "��ջԪ��Ϊ��" << endl;
                cout << e<< endl<<endl;
                break;
            case 7:
                GetTop(S, e);
                cout << "ջ����Ԫ��Ϊ��" << endl;
                cout << e << endl << endl;
                break;
            default:break;
        }
    }
    return 0;
}