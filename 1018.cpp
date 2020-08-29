#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXV = 510;
const int INF = 0x3fffffff;
int G[MAXV][MAXV];
int c[MAXV];
int d[MAXV];
bool vis[MAXV] = {false};
int cmax, n, s, m, half;
vector<int> pre[MAXV];
vector<int> temp, path;
int send = INF, take = 0;

void Dijkstra(){
    fill(d, d + MAXV, INF);
    d[0] = 0;
    for(int i = 0; i <= n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j <= n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        vis[u] = true;
        for(int v = 0; v <= n; v++){
            if(vis[v] == false && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(d[u] + G[u][v] == d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int st){
    if(st == 0){
        temp.push_back(st);
        int collected = 0, need = 0;  //过程模拟
        for(int i = temp.size() - 2; i >= 0; i--){
            if(c[temp[i]] > half){
                collected += (c[temp[i]] - half);
            }
            else{
                if(collected > half - c[temp[i]]){
                    collected -= (half - c[temp[i]]);
                }
                else{
                    need += (half - collected - c[temp[i]]);
                    collected = 0;
                }
            }
        }
        if(need < send){
            path = temp;
            send = need;
            take = collected;
        }
        else if(need == send){
            if(collected < take){
                path = temp;
                take = collected;
            }
        }
        temp.pop_back();
    }
    temp.push_back(st);
    for(int i = 0; i < pre[st].size(); i++){
        DFS(pre[st][i]);
    }
    temp.pop_back();
}

int main(){
    fill(G[0], G[0] + MAXV * MAXV, INF);
    scanf("%d %d %d %d", &cmax, &n, &s, &m);
    half = cmax / 2;
    for(int i = 1; i <= n; i++){
        scanf("%d", &c[i]);
    }
    int u, v;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra();
    DFS(s);
    printf("%d ", send);
    for(int i = path.size() - 1; i >= 0; i--){
        printf("%d", path[i]);
        if(i != 0){
            printf("->");
        }
        else{
            printf(" ");
        }
    }
    printf("%d", take);
    
    return 0;
}