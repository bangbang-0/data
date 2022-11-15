
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

//初始化顺序队列
void iniQueue(Queue &Q, int MAX) {
    Q.sts = new int[MAX];
    Q.front = Q.rear = 0;
}

//数据元素入队
Status toQueue(Queue &Q, int number) {
    if (Q.rear == sizeof(Q.sts))return OVERFLOW;
    Q.sts[Q.rear] = number;
    Q.rear++;
    return OK;
}

//数据元素出队
Status outQueue(Queue &Q, int number) {
    if (Q.front == Q.rear)return -1;
    number = Q.sts[Q.front];
    Q.front++;
    return number;
}

//读队头元素
Status headQueue(Queue Q) {
    return Q.sts[Q.front];
}

//判定数据元素空/满
Status judgeQueue(Queue Q) {
    if (Q.front == Q.rear) return OVERFLOW;
    if (Q.rear == sizeof(Q.sts) - 1) return OK;
    return ERROR;
}

//销毁顺序队列
void delQueue(Queue &Q) {
    delete[] Q.sts;
    cout << "已销毁";
}

void test01() {
    Queue s;
    string judge;
    judge = judgeQueue(s)?"空":"非空";
    cout<<"该队列为"<<judge<<endl;
    int MAX;
    cout << "输入队列长度：";
    cin >> MAX;
    iniQueue(s, MAX);
    int i = 0;

    while (i++ < MAX) {
        printf("输入第%d个数",i);
        int n=0;
        cin >> n;
        toQueue(s, n);
        cout<<"队头为："<<headQueue(s)<<endl;
    }
    int n = MAX;
    while (n-- > 0) {
        cout << "出队元素:" << outQueue(s, n) << endl;
    }
    delQueue(s);
}

int main() {
    test01();
    system("pause");
    return 0;
}