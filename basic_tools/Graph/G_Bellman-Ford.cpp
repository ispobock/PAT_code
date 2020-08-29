//Bellman-Ford算法，求解单源带负边权的最短路，复杂度O(VE)，图中若出现负环，此法无法求出最短简单路
//SPFA，BF算法的优化算法，无需经过固定轮暴力遍历所有边，用queue实现，复杂度O(kE)，通常k <= 2
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXV = 100;
const int INF = 1000000000;
struct Node{
    int v, dis;
}
vector<Node> Adj[MAXV];
int n;
int d[MAXV];

bool Bellman(int s){
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for(int i = 0; i < n - 1; i++){ //最多需要n - 1轮(最坏情况)更新可以确定所有最短路
        for(int u = 0; u < n; u++){
            for(int j = 0; j < Adj[u].size(); j++){ //与Dijkstra不同的是这里每轮都对所有边进行遍历，而不是对点
                int v = Adj[u][j].v;
                int dis = Adj[u][j].dis;
                if(d[u] + dis < d[v]){
                    //松弛操作
                    d[v] = d[u] + dis;
                }
            }
        }
    }
    //若图中存在源点可到达的“负环”，则n - 1次操作后仍会无法收敛，即此法无法求出该种情况最短简单路，返回false
    for(int u = 0; u < n; u++){
        for(int j = 0; j < Adj[u].size(); j++){
            int v = Adj[u][j].v;
            int dis = Adj[u][j].dis;
            //存在不能收敛的情况
            if(d[u] + dis < d[v]){
                return false;
            }
        }
    }
    return true;
}

int num[MAXV]; //记录每个顶点入队次数
bool inq[MAXV]; //顶点是否在队列中

//运用BFS遍历
bool SPFA(int s){
    fill(inq, inq + MAXV, false);
    fill(num, num + MAXV, 0);
    fill(d, d + MAXV, INF);
    queue<int> q;
    q.push(s);
    inq[s] = true;
    num[s]++;
    d[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        inq[u] = false;
        for(int j = 0; j < Adj[u].size(); j++){
            int v = Adj[u][j].v;
            int dis = Adj[u][j].dis;
            //松弛操作
            if(d[u] + dis < d[v]){
                d[v] = d[u] + dis;
                //SPFA算法相比BF算法的优化之处
                //只有在某点d[v]值被刷新了后，从它出发的边的邻接点的d才会被改变，故只需对这些点入队即可
                if(!inq[v]){
                    q.push(v);
                    inq[v] = true;
                    num[v]++;
                    if(num[v] >= n){
                        return false; //存在源点可达负环
                    }
                }
            }
        }
    }
    return true;
}