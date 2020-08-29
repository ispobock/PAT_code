//Kruskal算法，基于并查集实现，适用于边数较少的图，复杂度O(ElogE)
//此算法的实现与前几种图算法不同：没有用邻接矩阵或者邻接表来存储图，而是用了E[MAXE]来存储边
#include <algorithm>
using namespace std;

const int MAXE = 100;

struct edge{
    int u, v;
    int cost;
}E[MAXE];

bool cmp(edge a, edge b){
    return a.cost < b.cost;
}

int father[N];
int findFather(int x){
    int a = x;
    while(x != father[x]){
        x = father[x];
    }
    //将“寻父路径”上所有点的父亲都改为x（路径压缩）
    while(a != father[a]){
        int z = a;
        father[z] = x;
        a = father[a];
    }
    return x;
}

//n为顶点数，m为边数
int kruskal(int n, int m){
    int ans = 0, num_edge = 0;
    for(int i = 1; i <= n; i++){
        father[i] = i;
    }
    sort(E, E + m, cmp);
    for(int i = 0; i < m; i++){
        int fa_u = findFather(E[i].u);
        int fa_v = findFather(E[i].v);
        if(fa_u != fa_v){ //此边两个端点不在一个集合
            father[fa_u] = fa_v;
            ans += E[i].cost;
            num_edge++;
            if(num_edge == n - 1){ //边数等于顶点数减一
                break;
            }
        }
    }
    if(num_edge != n - 1){
        return -1;
    }
    else{
        return ans;
    }
}