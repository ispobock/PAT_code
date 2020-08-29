#include <cstdio>
#include <cstring>

const int MAXV = 1010;
int G[MAXV][MAXV];
int n, m, k, c;
bool vis[MAXV] = {false};

void DFS(int v){
    vis[v] = true;
    for(int i = 1; i <= n; i++){
        if(vis[i] == false && G[v][i] != -1 && i != c){
            DFS(i);
        }
    }
}

int DFSTrave(){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i] == false && i != c){
            DFS(i);
            count++;
        }
    }
    return count;
}

int main(){
    memset(G, -1, sizeof(G));
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        G[u][v] = G[v][u] = 1;
    }
    for(int i = 0; i < k; i++){
        scanf("%d", &c);
        printf("%d\n", DFSTrave() - 1);
        memset(vis, false, sizeof(vis));
    }
    return 0;
}