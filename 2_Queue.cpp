
#include<iostream>

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
int toQueue(Queue &Q, int number) {
    if (Q.rear == sizeof(Q.sts))return -1;
    Q.sts[Q.rear] = number;
    Q.rear++;
    return 0;
}

//����Ԫ�س���
int outQueue(Queue &Q, int &number) {
    if (Q.front == Q.rear)return -1;
    number = Q.sts[Q.front];
    Q.front++;
    return number;
}

//����ͷԪ��
int headQueue(Queue Q) {
    return Q.sts[Q.front];
}

//�ж�����Ԫ�ؿ�/��
int judgeQueue(Queue Q) {
    if (Q.front == Q.rear) return -1;
    if (Q.rear == sizeof(Q.sts) - 1) return 1;
    return 0;
}

//����˳�����
void delQueue(Queue &Q) {
    delete[] Q.sts;
    cout << "over";
}

void test01() {
    Queue s;
    int MAX;
    cout << "������г��ȣ�";
    cin >> MAX;
    iniQueue(s, MAX);
    int i = 0;
    while (i++ < MAX) {
        printf("�����%d����", i);
        int n;
        cin >> n;
        toQueue(s, n);
    }
    int n = MAX;
    while (n-- > 0) {
        int n;
        cout << "����Ԫ��:" << outQueue(s, n) << endl;
    }
    delQueue(s);
}

int main() {
    test01();
    system("pause");
    return 0;
}