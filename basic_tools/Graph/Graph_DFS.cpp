// 图(Graph)的表示包括邻接矩阵和邻接链表
// 图的遍历分为DFS和BFS

const int MAXV = 1000;
const int INF = 0x7fffffff;

// DFS邻接矩阵
int n, G[MAXV][MAXV];
bool vis[MAXV] = {false};

void DFS(int u, int depth){ // 对邻接矩阵每一行访问
    vis[u] = true;
    // 对v可到达的结点枚举
    for(int v = 0; v < n; v++){
        if(vis[v] == false && G[u][v] != INF){
            DFS(v, depth + 1);
        }
    }
}

void DFSTrave(){ // 对每个结点进行遍历
    for(int u = 0; u < n; u++){
        if(vis[u] == false){
            DFS(u, 1);
        }
    }
}

// DFS邻接链表，用vector代替链表
#include <vector>
using namespace std;
vector<int> Adj[MAXV];

void DFS_1(int u, int depth){
    vis[u] = true;

    for(int i = 0; i < Adj[u].size(); i++){
        int v = Adj[u][i];
        if(vis[v] == false){
            DFS_1(v, depth + 1);
        }
    }
}

void DFSTrave_1(){
    for(int u = 0; u < n; u++){
        if(vis[u] == false){
            DFS_1(u, 1);
        }
    }
}