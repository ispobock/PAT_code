//Dijkstra算法，解决单源最短路问题，无法处理负边权
/*
Dijkstra的本质是“贪心”的思想，每一步都是局部最优——只着眼于当下的部分信息（如此点距离下一点的距离）就做出判断，
不考虑全局信息（如到距离其更远的点的距离），这样做在某些情况下可以达到全局最优（如无负边权），但有时候会因为忽略
了一些有用的信息而付出代价，从而达不到全局最优（如带负边权）。
*/
#include <algorithm>
#include <vector>
using namespace std;

const int MAXV = 1000;
const int INF = 0x3ffffff; //此处涉及两数相加，不可写为0x7ffffff

//邻接矩阵版
int n, G[MAXV][MAXV];
int d[MAXV]; //用来存储起点s到v的最短距离
int pre[MAXV]; //用来存储最短路径上结点V的前驱
int vis[MAXV] = {false};

void Dijkstra_1(int s){
    fill(d, d + MAXV, INF);
    d[s] = 0;
    //n次循环
    for(int i = 0; i < n; i++){
        int u = -1, MIN = INF; // u = 全局中使d[u]最小且还未被访问的顶点标号，作为这次循环的访问对象
        for(int j = 0; j < n; j++){
            if(vis[j] = false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return; //s与其他点不连通
        vis[u] = true; //访问u
        for(int v = 0; v < n; v++){ //遍历与u相邻的结点
            if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]){ //若可更新距离，则更新
                d[v] = d[u] + G[u][v];
                pre[v] = u;
            }
        }
    } 
}


//邻接表版
struct Node{
    int v, dis;
};
vector<Node> Adj[MAXV];

void Dijkstra_2(int s){
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int j = 0; j < Adj[u].size(); j++){
            int v = Adj[u][j].v;
            if(vis[v] == false && d[u] + Adj[u][j].dis < d[v]){
                d[v] = d[u] + Adj[u][v].dis;
                pre[v] = u;
            }
        }
    }
}

//递归输出最短路径
void DFS(int s, int v){
    if(v == s){
        printf("%d\n", s);
        return;
    }
    DFS(s, pre[v]);
    printf("%d\n", v);//到达最深处return回来,输出每一层顶点号
}