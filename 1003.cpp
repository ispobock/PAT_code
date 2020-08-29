#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXV = 510;
const int INF = 0x3fffffff;
int n, m, c1, c2;
int G[MAXV][MAXV];
int d[MAXV];
int path_num[MAXV] = {0}, team_num[MAXV] = {0}, team[MAXV] = {0};
bool vis[MAXV] = {false};

void Dijkstra(){
    fill(d, d + MAXV, INF);
    for(int i = 0; i < n; i++){
        team_num[i] = team[i];
    }
    d[c1] = 0;
    path_num[c1] = 1;
    for(int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        vis[u] = true;
        for(int v = 0; v < n; v++){
            if(vis[v] == false && G[u][v] != INF){
                if(G[u][v] + d[u] < d[v]){
                    d[v] = d[u] + G[u][v];
                    path_num[v] = path_num[u];
                    if(team_num[u] + team[v] > team_num[v]){
                        team_num[v] = team_num[u] + team[v];
                    }
                }
                else if(G[u][v] + d[u] == d[v]){
                    path_num[v] += path_num[u];
                    if(team_num[u] + team[v] > team_num[v]){
                        team_num[v] = team_num[u] + team[v];
                    }
                }
            }
        }
    }
}

int main(){
    fill(G[0], G[0] + MAXV * MAXV, INF);
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    for(int i = 0; i < n; i++){
        scanf("%d", &team[i]);
    }
    int temp1, temp2, len;
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &temp1, &temp2, &len);
        G[temp1][temp2] = len;
        G[temp2][temp1] = len;
    }
    Dijkstra();
    printf("%d %d", path_num[c2], team_num[c2]);
    return 0;
}