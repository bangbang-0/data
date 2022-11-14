
#include<iostream>

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
int toQueue(Queue &Q, int number) {
    if (Q.rear == sizeof(Q.sts))return -1;
    Q.sts[Q.rear] = number;
    Q.rear++;
    return 0;
}

//数据元素出队
int outQueue(Queue &Q, int &number) {
    if (Q.front == Q.rear)return -1;
    number = Q.sts[Q.front];
    Q.front++;
    return number;
}

//读队头元素
int headQueue(Queue Q) {
    return Q.sts[Q.front];
}

//判定数据元素空/满
int judgeQueue(Queue Q) {
    if (Q.front == Q.rear) return -1;
    if (Q.rear == sizeof(Q.sts) - 1) return 1;
    return 0;
}

//销毁顺序队列
void delQueue(Queue &Q) {
    delete[] Q.sts;
    cout << "over";
}

void test01() {
    Queue s;
    int MAX;
    cout << "输入队列长度：";
    cin >> MAX;
    iniQueue(s, MAX);
    int i = 0;
    while (i++ < MAX) {
        printf("输入第%d个数", i);
        int n;
        cin >> n;
        toQueue(s, n);
    }
    int n = MAX;
    while (n-- > 0) {
        int n;
        cout << "出队元素:" << outQueue(s, n) << endl;
    }
    delQueue(s);
}

int main() {
    test01();
    system("pause");
    return 0;
}