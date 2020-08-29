//拓扑排序，即将所给有向无环图(DAG)中的顶点排成一个序列，若图中存在边u->v，则序列中u一定在v之前
//用队列实现
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAXV = 100;

vector<int> G[MAXV];
int n, m;
int inDegree[MAXV]; //每个顶点的入度

bool topological_sort(){
    int num = 0;
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        printf("%d", u);
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i];
            inDegree[v]--;
            if(inDegree[v] == 0){ //只有入度减为0的顶点才能入队
                q.push(v);
            }
        }
        num++;
    }
    if(num == n){
        return true;
    }
    else{
        return false;
    }
}