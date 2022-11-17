
#include<iostream>
#include <string>
//Ë³ÐòÕ»
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

//1.³õÊ¼»¯
Status InitStack(SqStack &S) {
    S.base = new SElemType[MAXSIZE];
    if (!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}

//2.ÈëÕ»
Status Push(SqStack &S, SElemType e) {
    if (S.top - S.base == S.stacksize)
        return ERROR;
    *S.top++ = e;
    return OK;
}

//3.³öÕ»
Status Pop(SqStack &S, SElemType &e) {
    if (S.top == S.base)
        return ERROR;
    e = *--S.top;
    return OK;
}

//4.¶ÁÕ»¶¥ÔªËØ
SElemType GetTop(SqStack S, int &e) {

    if (S.top != S.base) {
        e = *(S.top - 1);
        return e;
    } else return 0;
}

//5.ÅÐ¶¨Õ»¿Õ/Âú²Ù×÷
Status StackEmpty(SqStack S) {

    if (S.top == S.base)
        return OK;
    else
        return ERROR;
}

//6.Ïú»ÙË³ÐòÕ»
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
        cout << "³õÊ¼»¯³É¹¦" << endl;
    } else {
        cout << "Î´³õÊ¼»¯" << endl;
        test01(S);
    }
}

void test02(SqStack &S) {
    int choose = -1;
    SElemType e;
    string s;
    while (choose != 0) {
        cout << "ÊäÈë²Ù×÷:";
        cin >> choose;
        switch (choose) {
            case 2:
                cout << "ÇëÊäÈëÈëÕ»ÔªËØ£º";
                cin >> e;
                if (!Push(S, e)) {
                    cout << "ÈëÕ»Ê§°Ü£¡" << endl;
                } else {
                    cout << "ÔªËØ " << e << " ÈëÕ»³É¹¦" << endl;
                }
                break;
            case 3:
                if (!Pop(S, e)) {
                    cout << "³öÕ»Ê§°Ü" << endl;
                } else {
                    cout << "ÔªËØ " << e << " ³öÕ»³É¹¦" << endl;
                }
                break;
            case 4:
                if (GetTop(S, e)) {
                    cout << "Õ»¶¥ÔªËØÎª:" << e << endl;
                } else {
                    cout << "¶ÁÕ»¶¥ÔªËØÊ§°Ü" << endl;
                }
                break;
            case 5:
                s = StackEmpty(S) ? "Õ»¿Õ" : "Õ»·Ç¿Õ";
                cout << s << endl;
                break;
            case 6:
                DestroyStack(S);
                cout << "ÒÑÏú»Ù" << endl;
                exit(0);
                break;
            default:
                cout << "´íÎóÊäÈë" << endl;
                test02(S);
        }
    }
}

void menu() {
    cout << "1.³õÊ¼»¯" << endl;
    cout << "2.ÈëÕ»" << endl;
    cout << "3.³öÕ»" << endl;
    cout << "4.¶ÁÕ»¶¥ÔªËØ" << endl;
    cout << "5.ÅÐ¶ÏÕ»¿Õ/Âú" << endl;
    cout << "6.Ïú»Ù²¢ÍË³ö" << endl;
}

int main() {
    SqStack S;
    menu();
    test01(S);
    test02(S);

}