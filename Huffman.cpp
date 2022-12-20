
//哈夫曼树
#include<iostream>
#include<string>
#include <map>
#include<queue>
#include <algorithm>

using namespace std;
typedef struct node {
    int weight, parent, lchild, rchild;
} *Node;

int main() {
    string ques;
    cin >> ques;
    while (ques != "0") {
        map<char, int> sts;
        for (int i = 0; i < ques.size(); ++i) {
            if (sts.end() != sts.find(ques[i]))sts[ques[i]]++;
            else sts.insert(pair<char, int>(ques[i], 1));
        }
        for (auto x: sts) {
            cout << x.first << ":" << x.second << "  ";
        }
        cout<<endl;
        int len = sts.size();
        Node T = new node[2 * len];
        for (int i = 0; i < 2 * len; ++i) {
            T[i].weight = T[i].parent = T[i].rchild = T[i].lchild = 0;
        }
        int i = 1;
        for (auto x: sts) {
            T[i].weight = x.second;
            ++i;
        }
        //创建哈夫曼树
        for (int j = len + 1; j < 2 * len; ++j) {
            int s1, s2;
            int min = INT_MAX;
            int loc;
            for (int i = 1; i < j - 1; i++) {
                if (T[i].weight < min&&T[i].parent==0) {
                    loc = i;
                    min = T[i].weight;
                    s1=i;
                }
            }
            int temp=T[loc].weight,tep=loc;//暂存,再找第二个最小值
            T[loc].weight= INT_MAX;
            min = INT_MAX;
            for (int i = 1; i <= j - 1; i++) {
                if (T[i].weight < min&&T[i].parent==0) {
                    loc = i;
                    min = T[i].weight;
                    s2=i;
                }
            }
            T[tep].weight=temp;
           //
            T[s1].parent = j;
            T[s2].parent = j;
            T[j].lchild = s1;
            T[j].rchild = s2;
            T[j].weight = T[s1].weight + T[s2].weight;

        }
        for (int i = 1; i < 2 * len; ++i) {
            cout<<i<<" " << T[i].weight << " " << T[i].parent << " " << T[i].lchild << " " << T[i].rchild << endl;
        }

        cin >> ques;
    }
}