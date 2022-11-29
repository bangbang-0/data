
#include<iostream>

#define OK 1
#define ERROR 0
#define MAXSIZE 100
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
using namespace std;

//˳�����
typedef struct {
    ElemType *base;
    int front;
    int rear;
} Queue;

//��ʼ��˳�����
Status InitQueue(Queue &Q) {
    Q.base = new ElemType[MAXSIZE];
    if (!Q.base)return OVERFLOW;
    Q.front = Q.rear = 0;
    return OK;
}

//����Ԫ�����
Status EnQueue(Queue &Q, ElemType number) {
    if (Q.rear == MAXSIZE)return ERROR;
    Q.base[Q.rear] = number;
    Q.rear++;
    return OK;
}

//����Ԫ�س���
Status DeQueue(Queue &Q, ElemType &e) {
    if (Q.front == Q.rear)return ERROR;
    e = Q.base[Q.front];
    Q.front++;
    return OK;
}

//����ͷԪ��
Status GetHead(Queue Q, ElemType &e) {
    if (Q.rear == Q.front)return ERROR;
    e = Q.base[Q.front];
    return OK;
}

//�ж�����Ԫ�ؿ�/��
bool QueueEmpty(Queue Q) {
    if (Q.front == Q.rear)
        return true;
    else return false;
}

//����˳�����
Status DestoryQueue(Queue &Q) {
    if (Q.base) {
        Q.rear = Q.front = 0;
        delete[] Q.base;
    }
    Q.base = nullptr;
    return OK;
}

//���г���
Status QueueLength(Queue Q) {
    return Q.rear - Q.front;
}

void menu() {
    cout << "1.��ʼ������" << endl;
    cout << "2.���" << endl;
    cout << "3.����" << endl;
    cout << "4.�����ͷ" << endl;
    cout << "5.�鿴���Ƿ��" << endl;
    cout << "6.���г���" << endl;
    cout << "0.���ٲ��˳�" << endl;
}

int main() {
    int choose = -1;
    ElemType e;
    Queue Q;
    InitQueue(Q);
    menu();
    while (choose != 0) {
        cout << "��ѡ�������" << endl;		//����ѡ��
        do {
            cin >> choose;
            if (choose < 0 || choose>6)
                cout << "�������,����������:" << endl;
        } while (choose < 0 || choose>6);
        switch (choose) {
            case 1:
               if (InitQueue(Q))cout<<"���г�ʼ�����"<<endl;
                break;
            case 2:
                cout<<"�������Ԫ��"<<endl;
                cin>>e;
                EnQueue(Q,e);
                cout<<"��Ԫ����ӳɹ�"<<endl;
                break;
            case 3:
                DeQueue(Q,e);
                cout<<"Ԫ��"<<e<<"����"<<endl;
                break;
            case 4:
                if(GetHead(Q,e))cout<<"��ͷΪ"<<e<<endl;
                else cout<<"����Ϊ��"<<endl;
                break;
            case 5:
                if(QueueEmpty(Q))cout<<"�ö���Ϊ��"<<endl;
                else cout<<"�ö��зǿ�"<<endl;
            case 6:
                cout<<"����Ϊ:"<<QueueLength(Q)<<endl;
            case 0:
                exit(0);
            default:
                break;
        }
        }
    system("pause");
    return 0;
}