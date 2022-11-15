
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
void iniQueue(Queue &Q, int MAX) {
    Q.sts = new int[MAX];
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
Status outQueue(Queue &Q, int number) {
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
Status judgeQueue(Queue Q) {
    if (Q.front == Q.rear) return OVERFLOW;
    if (Q.rear == sizeof(Q.sts) - 1) return OK;
    return ERROR;
}

//����˳�����
void delQueue(Queue &Q) {
    delete[] Q.sts;
    cout << "������";
}

void test01() {
    Queue s;
    string judge;
    judge = judgeQueue(s)?"��":"�ǿ�";
    cout<<"�ö���Ϊ"<<judge<<endl;
    int MAX;
    cout << "������г��ȣ�";
    cin >> MAX;
    iniQueue(s, MAX);
    int i = 0;

    while (i++ < MAX) {
        printf("�����%d����",i);
        int n=0;
        cin >> n;
        toQueue(s, n);
        cout<<"��ͷΪ��"<<headQueue(s)<<endl;
    }
    int n = MAX;
    while (n-- > 0) {
        cout << "����Ԫ��:" << outQueue(s, n) << endl;
    }
    delQueue(s);
}

int main() {
    test01();
    system("pause");
    return 0;
}