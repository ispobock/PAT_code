//无向图求解最小生成树(MST)，Prim算法，复杂度O(V^2)
const int MAXV = 1000;
const int INF = 100000000;
int n, G[MAXV][MAXV];
int d[MAXV]; //顶点与集合s的最短距离
bool vis[MAXV] = {false};

//默认树根为0
int prim(){
    fill(d, d + MAXV, INF);
    d[0] = 0;
    int ans = 0; //统计边权之和
    for(int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return -1;
        vis[u] = true;
        ans += d[u];
        for(int v = 0; v < n; v++){
            if(vis[v] == false && G[u][v] != INF && G[u][v] < d[v]){ //与Dijkstra仅此处不同
                d[v] = G[u][v];
            }
        }
    }
    return ans;
}