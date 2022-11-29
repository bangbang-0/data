
#include<iostream>
#include <string>
//��ջ
using namespace std;

#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

using namespace std;


typedef struct sqstack {
    ElemType data;          //������
    sqstack *next;          //ָ����
} *Sqstack;
//��1����ʼ��
Status InitStack(Sqstack &S) /*��ջ�ĳ�ʼ��*/
{
    Sqstack head = new sqstack;  //ͷ���
    head->next = nullptr;
    S = head;
    return OK;
}

//��2����ջ
Status Push(Sqstack &S, ElemType e) {
    Sqstack p = new sqstack;
    if(!p)return OVERFLOW;
    p->data = e;     //��ֵ
    p->next = S->next; //����ͷ������Ԫ���֮��
    S->next = p;     // ��ͷ�������
    return OK;
}

//��3����ջ
Status Pop(Sqstack &S, ElemType &e) {
    if(S->next) {       //����ǿ�
        Sqstack p = S->next;
        e = p->data;
        S->next = p->next;   //����Ԫ����ͷ�������
        delete p;  //ɾ����Ԫ���
        return OK;
    }
    else return ERROR;
}

//��4����ջ��Ԫ�أ�
Status GetTop(Sqstack S, ElemType &e) //ȡջ��
{
    if (S->next) {
        e = S->next->data;
        return OK;
    } else return ERROR;
}

//��5���ж�ջ��/��������
bool StackEmpty(Sqstack &S)//ջ�п�
{
    return S->next == nullptr;
}

//��6��������ջ��
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
    while(p) //�����õ�����
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
    InitStack(S); cout << "��ջ:" << endl << endl;
    cout << "1. ��ջ�ĳ�ʼ��" << endl;
    cout << "2. ջ�Ƿ�Ϊ��" << endl;
    cout << "3. ��ջ�ĳ���" << endl;
    cout << "4. ������ջ" << endl;
    cout << "5. ��ջ" << endl;
    cout << "6. ��ջ" << endl;
    cout << "7. ȡջ��Ԫ��" << endl;
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
                if (InitStack(S))  cout << "��ջ��ʼ���ɹ���" << endl << endl;
                else cout << "˳��ջ��ʼ��ʧ�ܣ�" << endl << endl;;
                break;
            case 2:
                if (StackEmpty(S))	cout << "��ջΪ�գ�" << endl << endl;
                else cout << "��ջ��Ϊ�գ�" << endl << endl;
                break;
            case 3:
                cout << "��ʱջ�ڹ���" << StackLength(S) << "��Ԫ��" << endl<<endl;
                break;
            case 4:
                if (DestroyStack(S)) cout << "������ջ�ɹ�" << endl << endl;
                break;
            case 5:
                cout << "������" << endl;
                cin >> e;
                if (Push(S, e))	cout << "��Ԫ����ջ�ɹ�" << endl << endl;
                break;
            case 6:
                if(Pop(S, e)) {
                    cout << "��ջԪ��Ϊ��" << endl;
                    cout << e << endl << endl;
                } else cout<<"��ջΪ�գ�"<<endl;
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