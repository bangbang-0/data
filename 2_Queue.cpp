
#include<iostream>

#define OK 1
#define ERROR 0
#define MAXSIZE 100
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
using namespace std;

//顺序队列
typedef struct {
    ElemType *base;
    int front;
    int rear;
} Queue;

//初始化顺序队列
Status InitQueue(Queue &Q) {
    Q.base = new ElemType[MAXSIZE];
    if (!Q.base)return OVERFLOW;
    Q.front = Q.rear = 0;
    return OK;
}

//数据元素入队
Status EnQueue(Queue &Q, ElemType number) {
    if (Q.rear == MAXSIZE)return ERROR;
    Q.base[Q.rear] = number;
    Q.rear++;
    return OK;
}

//数据元素出队
Status DeQueue(Queue &Q, ElemType &e) {
    if (Q.front == Q.rear)return ERROR;
    e = Q.base[Q.front];
    Q.front++;
    return OK;
}

//读队头元素
Status GetHead(Queue Q, ElemType &e) {
    if (Q.rear == Q.front)return ERROR;
    e = Q.base[Q.front];
    return OK;
}

//判定数据元素空/满
bool QueueEmpty(Queue Q) {
    if (Q.front == Q.rear)
        return true;
    else return false;
}

//销毁顺序队列
Status DestoryQueue(Queue &Q) {
    if (Q.base) {
        Q.rear = Q.front = 0;
        delete[] Q.base;
    }
    Q.base = nullptr;
    return OK;
}

//队列长度
Status QueueLength(Queue Q) {
    return Q.rear - Q.front;
}

void menu() {
    cout << "1.初始化队列" << endl;
    cout << "2.入队" << endl;
    cout << "3.出队" << endl;
    cout << "4.输出队头" << endl;
    cout << "5.查看队是否空" << endl;
    cout << "6.队列长度" << endl;
    cout << "0.销毁并退出" << endl;
}

int main() {
    int choose = -1;
    ElemType e;
    Queue Q;
    InitQueue(Q);
    menu();
    while (choose != 0) {
        cout << "请选择操作：" << endl;		//输入选择
        do {
            cin >> choose;
            if (choose < 0 || choose>6)
                cout << "输入错误,请重新输入:" << endl;
        } while (choose < 0 || choose>6);
        switch (choose) {
            case 1:
               if (InitQueue(Q))cout<<"队列初始化完成"<<endl;
                break;
            case 2:
                cout<<"输入入队元素"<<endl;
                cin>>e;
                EnQueue(Q,e);
                cout<<"该元素入队成功"<<endl;
                break;
            case 3:
                DeQueue(Q,e);
                cout<<"元素"<<e<<"出队"<<endl;
                break;
            case 4:
                if(GetHead(Q,e))cout<<"队头为"<<e<<endl;
                else cout<<"队列为空"<<endl;
                break;
            case 5:
                if(QueueEmpty(Q))cout<<"该队列为空"<<endl;
                else cout<<"该队列非空"<<endl;
            case 6:
                cout<<"长度为:"<<QueueLength(Q)<<endl;
            case 0:
                exit(0);
            default:
                break;
        }
        }
    system("pause");
    return 0;
}