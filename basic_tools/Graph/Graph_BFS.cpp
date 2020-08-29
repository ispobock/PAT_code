#include <queue>
#include <vector>
using namespace std;
//邻接矩阵
const int maxv = 100;
const int INF = 1000000000;
int n;
int G[maxv][maxv];
bool inq[maxv] = {false}; //结点是否被访问

void BFS(int u){
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            if(inq[i] == false && G[top][i] != INF){
                q.push(i);
                inq[i] = true;
            }
        }
    }
}

void BFSTrave(){
    for(int i = 0; i < n; i++){
        if(inq[i] == false){
            BFS(i);
        }
    }
}

//邻接链表
vector<int> Adj[maxv];

void BFS_1(int u){
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(int i = 0; i < Adj[top].size(); i++){
            if(inq[Adj[top][i]] == false){
                q.push(Adj[top][i]);
                inq[Adj[top][i]] = true;
            }
        }
    }
}

void BFS_trave(){
    for(int i = 0; i < n; i++){
        if(inq[i] == false){
            BFS_1(i);
        }
    }
}