
#include<iostream>

#define OK 1
#define ERROR 0
#define MAXSIZE 100
#define OVERFLOW -2
typedef int Status;
using namespace std;
typedef struct {
    int *sts;
    int front;
    int rear;
} Queue;

//��ʼ��˳�����
void iniQueue(Queue &Q, int i) {
    Q.sts = new int[i];
    Q.front = Q.rear = 0;
}

//����Ԫ�����
Status toQueue(Queue &Q, int number) {
    if (Q.rear == sizeof(Q.sts))return OVERFLOW;
    Q.sts[Q.rear] = number;
    Q.rear++;
    return OK;
}

//����Ԫ�س���
Status outQueue(Queue &Q) {
    int number;
    if (Q.front == Q.rear)return -1;
    number = Q.sts[Q.front];
    Q.front++;
    return number;
}

//����ͷԪ��
Status headQueue(Queue Q) {
    return Q.sts[Q.front];
}

//�ж�����Ԫ�ؿ�/��
void judgeQueue(Queue Q, int i) {
    string judge;
    if (Q.front == Q.rear)
        judge = "��";
    else
        judge = "�ǿ�";
    cout << "�ö���Ϊ" << judge << endl;
}

//����˳�����
void delQueue(Queue &Q) {
    delete[] Q.sts;
    cout << "������";
}

void menu() {
    cout << "1.����" << endl;
    cout << "2.�����ͷ" << endl;
    cout << "3.�鿴���Ƿ��" << endl;
    cout << "0.���ٲ��˳�" << endl;
}

void choice(Queue &s, int MAX) {
    int choose = 0;
    while (true) {
        system("pause");
        system("cls");
        menu();
        cout << "�������:" << endl;
        cin >> choose;
        switch (choose) {
            case 1:
                if (MAX == 0) cout << "������";
                int n;
                cout << "���Ӽ���Ԫ��";
                cin >> n;
                while (n > MAX) {
                    cout << "��������";
                    cin >> n;
                }
                MAX -= n;
                while (n-- > 0) {
                    cout << "����Ԫ��:" << outQueue(s) << endl;
                }
                break;
            case 2:
                cout << headQueue(s) << endl;
                break;
            case 3:
                judgeQueue(s, MAX);
                break;
            case 0:
                exit(0);
            default:
                cout << "��������:" << endl;
                choice(s, MAX);
        }
    }
}


void test01() {
    Queue s;
    int MAX;
    cout << "������г���:";
    cin >> MAX;
    iniQueue(s, MAX);
    int i = 0;
    while (i++ < MAX) {
        printf("�����%d����", i);
        int n = 0;
        cin >> n;
        toQueue(s, n);
    }
    choice(s, MAX);

    delQueue(s);
}

int main() {
    test01();
    system("pause");
    return 0;
}