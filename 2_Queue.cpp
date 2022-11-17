
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
void iniQueue(Queue &Q, int i) {
    Q.sts = new int[i];
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
Status outQueue(Queue &Q) {
    int number;
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
void judgeQueue(Queue Q, int i) {
    string judge;
    if (Q.front == Q.rear)
        judge = "空";
    else
        judge = "非空";
    cout << "该队列为" << judge << endl;
}

//销毁顺序队列
void delQueue(Queue &Q) {
    delete[] Q.sts;
    cout << "已销毁";
}

void menu() {
    cout << "1.出队" << endl;
    cout << "2.输出队头" << endl;
    cout << "3.查看队是否空" << endl;
    cout << "0.销毁并退出" << endl;
}

void choice(Queue &s, int MAX) {
    int choose = 0;
    while (true) {
        system("pause");
        system("cls");
        menu();
        cout << "输入操作:" << endl;
        cin >> choose;
        switch (choose) {
            case 1:
                if (MAX == 0) cout << "无数据";
                int n;
                cout << "出队几个元素";
                cin >> n;
                while (n > MAX) {
                    cout << "重新输入";
                    cin >> n;
                }
                MAX -= n;
                while (n-- > 0) {
                    cout << "出队元素:" << outQueue(s) << endl;
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
                cout << "重新输入:" << endl;
                choice(s, MAX);
        }
    }
}


void test01() {
    Queue s;
    int MAX;
    cout << "输入队列长度:";
    cin >> MAX;
    iniQueue(s, MAX);
    int i = 0;
    while (i++ < MAX) {
        printf("输入第%d个数", i);
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