#include<iostream>
using namespace std;
#include<stdio.h>
#define SIZE 110
#define INF 1000000;
int map[SIZE][SIZE];  //邻接矩阵存储
int len[SIZE];  	//d[i]表示源点到i这个点的距离
int visit[SIZE];  //节点是否被访问
int n, m, j, pos, ans;
int temp = INF;

int dijkstra(int from, int to, int* centreChar) {	//从源点到目标点
    int i;
    for (i = 1; i <= n; i++) {	//初始化
        visit[i] = 0;	//一开始每个点都没被访问
        len[i] = map[from][i];	//先假设源点到其他点的距离
        int inf = INF;
        if (map[from][i]!=inf) {
            centreChar[i] = from;     //如果源节点到各个节点有路径，那么初始化每个节点的中间节点为源节点的位置，
        }
    }
    visit[from] = 1;
    for (i = 1; i < n; ++i) {	//对除源点的每一个点进行最短计算
        int min = INF;  //记录最小len[i]
        //记录小len[i] 的点
        for (j = 1; j <= n; ++j) {
            if (!visit[j] && min > len[j]) {
                pos = j;        //每次选一个最小的路径点，
                min = len[j];
            }
        }
        visit[pos] = 1;
        for (j = 1; j <= n; ++j) {
            if (!visit[j] && (len[j] > (len[pos] + map[pos][j]))) { //如果j节点没有被访问过&&j节点到源节点的最短路径>pos节点到源节点的最短路径+pos节点到j节点的路径
                len[j] = len[pos] + map[pos][j];	//更新j节点到源节点的最短路径
                centreChar[j] = pos;      //修改j这个位置节点对应的中间节点位置，
            }
        }
    }
    return len[to];
}

int main()
{
    int i, j;
    //建筑物个数n和路径条数m
    cout << "请输入建筑物个数n和路径条数m：" << endl;
    cin >> n >> m;
    cout << endl;
    cout << "请输入建筑物代表字母：（如：A B C）" << endl;
    char* p = new char[n];
    for (i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (i = 1; i <= n; ++i) {	//设一开始每个点都不可达
        for (j = 1; j <= n; ++j) {
            map[i][j] = INF;
        }
    }
    //输入数据
    char a, b;
    int c;
    cout << "m：" << m << endl;
    for (i = 1; i <= m; ++i) {
        cout << "请输入路径：（示例：A B 1）" << endl;
        cin >> a >> b >> c;
        cout << endl;
        int x, y;
        for (int j = 0; j < n; j++)
        {
            if (p[j] == a) x = j + 1;
            if (p[j] == b) y = j + 1;
        }
        map[x][y] = map[y][x] = c;
    }
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= n; ++j) {
            if (map[i][j] == temp)
                map[i][j] = map[j][i];
        }
    }
    cout << "请输入from，to：" << endl;
    char from, to;
    cin >> from >> to;
    int x, y;
    for (int j = 0; j < n; j++)
    {
        if (p[j] == from) x = j + 1;
        if (p[j] == to) y = j + 1;
    }
    int* centreChar = new int(SIZE);   //源点到每个点的最短路径情况下，每个点的中间节点，
    cout << from << "到" << to << "的最短路径为：" << dijkstra(x, y,centreChar) << endl;
    cout << "最短路径为：" << from<<"---->";
    int idx = 0;
    int end[SIZE];
    int next = y;
    for (int i = 0; i < n; i++) {
        if (centreChar[next] == x) {
            break;
        }
        end[idx] = centreChar[next];
        next= centreChar[next];
        if (centreChar[next] != x) {
            idx++;
        }
    }
    for (int i = idx; i >=0; i--) {
        cout << p[end[i] - 1] << "---->";
    }
    cout << to;
    cout << endl;
    return 0;
}