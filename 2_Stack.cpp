
#include<iostream>
#include <string>
//˳��ջ
using namespace std;

#define OK 1
#define ERROR 0
#define MAXSIZE 100
#define OVERFLOW -2
typedef int Status;
typedef int SElemType;

typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

//1.��ʼ��
Status InitStack(SqStack &S) {
    S.base = new SElemType[MAXSIZE];
    if (!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}

//2.��ջ
Status Push(SqStack &S, SElemType e) {
    if (S.top - S.base == S.stacksize)
        return ERROR;
    *S.top++ = e;
    return OK;
}

//3.��ջ
Status Pop(SqStack &S, SElemType &e) {
    if (S.top == S.base)
        return ERROR;
    e = *--S.top;
    return OK;
}

//4.��ջ��Ԫ��
SElemType GetTop(SqStack S, int &e) {

    if (S.top != S.base) {
        e = *(S.top - 1);
        return e;
    } else return 0;
}

//5.�ж�ջ��/������
Status StackEmpty(SqStack S) {

    if (S.top == S.base)
        return OK;
    else
        return ERROR;
}

//6.����˳��ջ
Status DestroyStack(SqStack &S) {

    delete (S.base);
    S.top = nullptr;
    S.base = nullptr;
    S.stacksize = 0;
    return OK;
}

void test01(SqStack &S) {
    int choose;
    cin >> choose;
    if (choose == 1) {
        InitStack(S);
        cout << "��ʼ���ɹ�" << endl;
    } else {
        cout << "δ��ʼ��" << endl;
        test01(S);
    }
}

void test02(SqStack &S) {
    int choose = -1;
    SElemType e;
    string s;
    while (choose != 0) {
        cout << "�������:";
        cin >> choose;
        switch (choose) {
            case 2:
                cout << "��������ջԪ�أ�";
                cin >> e;
                if (!Push(S, e)) {
                    cout << "��ջʧ�ܣ�" << endl;
                } else {
                    cout << "Ԫ�� " << e << " ��ջ�ɹ�" << endl;
                }
                break;
            case 3:
                if (!Pop(S, e)) {
                    cout << "��ջʧ��" << endl;
                } else {
                    cout << "Ԫ�� " << e << " ��ջ�ɹ�" << endl;
                }
                break;
            case 4:
                if (GetTop(S, e)) {
                    cout << "ջ��Ԫ��Ϊ:" << e << endl;
                } else {
                    cout << "��ջ��Ԫ��ʧ��" << endl;
                }
                break;
            case 5:
                s = StackEmpty(S) ? "ջ��" : "ջ�ǿ�";
                cout << s << endl;
                break;
            case 6:
                DestroyStack(S);
                cout << "������" << endl;
                exit(0);
                break;
            default:
                cout << "��������" << endl;
                test02(S);
        }
    }
}

void menu() {
    cout << "1.��ʼ��" << endl;
    cout << "2.��ջ" << endl;
    cout << "3.��ջ" << endl;
    cout << "4.��ջ��Ԫ��" << endl;
    cout << "5.�ж�ջ��/��" << endl;
    cout << "6.���ٲ��˳�" << endl;
}

int main() {
    SqStack S;
    menu();
    test01(S);
    test02(S);

}