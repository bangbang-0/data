#include<iostream>
using namespace std;
#include<stdio.h>
#define SIZE 110
#define INF 1000000;
int map[SIZE][SIZE];  //�ڽӾ���洢
int len[SIZE];  	//d[i]��ʾԴ�㵽i�����ľ���
int visit[SIZE];  //�ڵ��Ƿ񱻷���
int n, m, j, pos, ans;
int temp = INF;

int dijkstra(int from, int to, int* centreChar) {	//��Դ�㵽Ŀ���
    int i;
    for (i = 1; i <= n; i++) {	//��ʼ��
        visit[i] = 0;	//һ��ʼÿ���㶼û������
        len[i] = map[from][i];	//�ȼ���Դ�㵽������ľ���
        int inf = INF;
        if (map[from][i]!=inf) {
            centreChar[i] = from;     //���Դ�ڵ㵽�����ڵ���·������ô��ʼ��ÿ���ڵ���м�ڵ�ΪԴ�ڵ��λ�ã�
        }
    }
    visit[from] = 1;
    for (i = 1; i < n; ++i) {	//�Գ�Դ���ÿһ���������̼���
        int min = INF;  //��¼��Сlen[i]
        //��¼Сlen[i] �ĵ�
        for (j = 1; j <= n; ++j) {
            if (!visit[j] && min > len[j]) {
                pos = j;        //ÿ��ѡһ����С��·���㣬
                min = len[j];
            }
        }
        visit[pos] = 1;
        for (j = 1; j <= n; ++j) {
            if (!visit[j] && (len[j] > (len[pos] + map[pos][j]))) { //���j�ڵ�û�б����ʹ�&&j�ڵ㵽Դ�ڵ�����·��>pos�ڵ㵽Դ�ڵ�����·��+pos�ڵ㵽j�ڵ��·��
                len[j] = len[pos] + map[pos][j];	//����j�ڵ㵽Դ�ڵ�����·��
                centreChar[j] = pos;      //�޸�j���λ�ýڵ��Ӧ���м�ڵ�λ�ã�
            }
        }
    }
    return len[to];
}

int main()
{
    int i, j;
    //���������n��·������m
    cout << "�����뽨�������n��·������m��" << endl;
    cin >> n >> m;
    cout << endl;
    cout << "�����뽨���������ĸ�����磺A B C��" << endl;
    char* p = new char[n];
    for (i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (i = 1; i <= n; ++i) {	//��һ��ʼÿ���㶼���ɴ�
        for (j = 1; j <= n; ++j) {
            map[i][j] = INF;
        }
    }
    //��������
    char a, b;
    int c;
    cout << "m��" << m << endl;
    for (i = 1; i <= m; ++i) {
        cout << "������·������ʾ����A B 1��" << endl;
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
    cout << "������from��to��" << endl;
    char from, to;
    cin >> from >> to;
    int x, y;
    for (int j = 0; j < n; j++)
    {
        if (p[j] == from) x = j + 1;
        if (p[j] == to) y = j + 1;
    }
    int* centreChar = new int(SIZE);   //Դ�㵽ÿ��������·������£�ÿ������м�ڵ㣬
    cout << from << "��" << to << "�����·��Ϊ��" << dijkstra(x, y,centreChar) << endl;
    cout << "���·��Ϊ��" << from<<"---->";
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