#include <iostream>
#include <string>
using namespace std;
#define Max 100
typedef int ver;
#define queueSize 10
typedef struct {
    char vexs[100];
    int arcs[100][100];
    int vexnum, arcnum; //图的当前点数和边数
}Graph;
int LocateVex(Graph G, char v) {
    for (int i = 0; i < G.vexnum; ++i) {
        if (G.vexs[i] == v) {
            return i;
        }
    }
    return -1;
}
//创建无向图
void CreateUDN(Graph &G) {
    cout << "请输入总顶点数和总边数：" << endl;
    cin >> G.vexnum >> G.arcnum;
    cout << "请输入顶点：" << endl;
    for (int i = 0; i < G.vexnum; ++i) {
        cin >> G.vexs[i];
    }
    for (int i = 0; i < G.vexnum; ++i)
        for (int j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = Max;
    //构造邻接矩阵
    for (int k = 0; k < G.arcnum; ++k) {
        cout << "输入一条边所依附的顶点及边的权值："<<endl;
        char v1, v2;
        int w;
        cin >> v1 >> v2 >> w;
        int i, j;
        //确定v1和v2在G中的位置
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        //cout << "v1和v2在G中的位置：" << i << " " << j << endl;
        G.arcs[i][j] = w;
        G.arcs[j][i] = G.arcs[i][j];
    }
}
//打印无向图邻接矩阵
void PrintUDN(Graph &G) {
    cout << "----------邻接矩阵为------------------" << endl;
    for (int i = 0; i < G.vexnum; ++i) {
        for (int j = 0; j < G.vexnum; ++j) {
            if (G.arcs[i][j] == Max) {
                cout << "∞";
            }else {
                cout <<G.arcs[i][j]<<" ";
            }
        };
        cout << endl;
    }
}
//深度优先遍历
void DFS(Graph G, int v,int *visited) {
    cout << "访问第" << v+1 << "个顶点"<<endl;
    visited[v] = 1;
    for (int i = 0; i < G.vexnum; i++) {
        if ((G.arcs[v][i] != Max) && (!visited[i]))
            DFS(G, i, visited);
    }

}
//广度优先遍历
void BFS(Graph G, int *visited) {
    cout << "访问第1个顶点" << endl;
    visited[0] = 1;
    for (int v = 0; v < G.vexnum; v++) {
        for (int i = 0; i < G.vexnum; i++) {
            if ((G.arcs[v][i] != Max) && (!visited[i])) {
                cout << "访问第"<<i+1<<"个顶点" << endl;
                visited[i] = 1;
            }
        }
    }
}

//有向图：

typedef struct ArcNode {
    int adjvex;//邻接点
    struct ArcNode *next;//指向下一个邻接点的边结点
}ArcNode;
typedef struct vexnode
{	ver data; //存储顶点
    ArcNode *firstedge;//边表头指针
}vexnode;
typedef struct {
    vexnode adjlist[Max];//顶点表
    int vex, edge;
}graph;
//查找顶点v 不存在返回0
int locatevex(graph g, ver v)
{
    int i;
    for (i = 0; i < g.vex; i++)
        if (g.adjlist[i].data == v)return i;
    return 0;
}
void print(graph g)
{
    int i;
    ArcNode *p;
    printf("图的邻接表为：");
    for (i = 0; i < g.vex; i++) {
        printf("\n%4c", g.adjlist[i].data);
        p = g.adjlist[i].firstedge;
        while (p != NULL) {
            printf("-->%d", p->adjvex);
            p = p->next;
        }
    }
    printf("\n");
}
void creategraph(graph *g) {
    int i, j, k;
    ver v1, v2;
    ArcNode *s;
    printf("请输入顶点数：");
    scanf("%d", &g->vex);
    printf("请输入边数：");
    scanf("%d", &g->edge);
    printf("请输入图的顶点信息：\n");
    getchar();
    for (i = 0; i <= g->vex; i++) {
        scanf("%c", &g->adjlist[i].data); //构造顶点信息
        g->adjlist[i].firstedge = NULL;
    }
    for (k = 0; k < g->edge; k++)
    {
        printf("请输入第%d条边的两个端点下标：", k + 1);
        scanf("%c %c", &v1, &v2);
        getchar();//输入一条边的两个顶点
        i = locatevex(*g, v1);
        j = locatevex(*g, v2);
        if (i >= 0 && j >= 0) {
            //建立邻接表
            s = (ArcNode *)malloc(sizeof(ArcNode));
            s->adjvex = j;
            s->next = g->adjlist[i].firstedge;
            g->adjlist[i].firstedge = s;
        }
    }
}
int visited[Max];

void DFS(graph g, int i)
{
    ArcNode *p;
    printf("%3c", g.adjlist[i].data);/*访问第i个项点*/
    visited[i] = 1;
    p = g.adjlist[i].firstedge;
    while (p != NULL) {
        if (visited[p->adjvex] == 0)
            DFS(g, p->adjvex);/*对i的尚未访问的邻接顶点j递归调用DFS*/
        p = p->next;
    }
}
void DFStraverse(graph  g) /*对图G进行深度优先遍历*/
{	int v;
    for (v = 0; v < g.vex; v++)visited[v] = 0; /*初始化标志数组*/
    for (v = 0; v < g.vex; v++) /*保证非连通图的遍历*/
        if (!visited[v])DFS(g, v);
}
//循环队列存储结构定义
typedef struct  cirqueue
{	ver  *data;      //队列存储空间的首地址
    int front;         //队头位置：指向当前队头元素
    int rear;    //队尾位置：指向当前队尾元素的下一位置
}cirqueue;             // 循环队列
int initqueue(cirqueue *q)
{	q->data = (ver *)malloc(queueSize * sizeof(cirqueue));
    if (q->data == NULL)return 0; // 存储分配失败
    q->front = q->rear = 0;
    return 1;
}
int enqueue(cirqueue *q, ver e)
{
    if ((q->rear + 1) % queueSize == q->front)
        return 0; //队列满
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % queueSize; //队尾后移一位
    return 1;
}
int dequeue(cirqueue *q, int *e)
{
    if (q->front == q->rear)  return 0; //队列为空
    *e = q->data[q->front];
    q->front = (q->front + 1) % queueSize; //队头后移一位
    return 1;
}
int getfront(cirqueue q, ver *e)
{
    if (q.front == q.rear)  return 0; //队列为空
    *e = q.data[q.front];
    return  1;
}
int queueempty(cirqueue q)//栈非空
{
    if (q.front == q.rear)return 1; //队列为空
    else return 0;
}
int queuelength(cirqueue q)
{
    return (q.rear - q.front + queueSize) % queueSize;
}
int BFSvisited[Max];
cirqueue q;
void BFS(graph g, int k) {
    int i;
    ArcNode *p;
    initqueue(&q);/*初始化队列*/
    printf("%3c", g.adjlist[k].data);/*访问第k个项点*/
    visited[k] = 1;
    enqueue(&q, k);/*第k个顶点进队*/
    while (queueempty(q) == 0) {/*队列非空*/
        dequeue(&q, &i);
        p = g.adjlist[i].firstedge;/*获取第1个邻接点*/
        while (p != NULL) {
            if (visited[p->adjvex] == 0) {
                /*访问第i个顶点的末曾访问的顶点*/
                printf("%3c", g.adjlist[p->adjvex].data);
                visited[p->adjvex] = 1;
                enqueue(&q, p->adjvex);/*第k个顶点进队*/
            }
            p = p->next;
        }
    }
}
void BFStraverse(graph  g) //对图G进行广度优先遍历
{
    int v;
    for (v = 0; v < g.vex; v++) //初始化标志数组
        visited[v] = 0;
    for (v = 0; v < g.vex; v++) //保证非连通图的遍历
        if (!visited[v])BFS(g, v);
    //从第v个顶点出发递归地深度优先遍历图
}