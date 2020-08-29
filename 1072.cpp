#include <cstdio>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXV = 1020;
const int INF = 0x3fffffff; 
int G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV];
int n, m, k, D;
map<int, double> min_dis, avg_dis;

int Hashing(string s){
    int ans = 0;
    if(s[0] == 'G'){
        for(string::iterator it = s.begin() + 1; it != s.end(); it++){
            ans = ans * 10 + (*it - '0');
        }
        ans += n;
        return ans;
    }
    else{
        for(string::iterator it = s.begin(); it != s.end(); it++){
            ans = ans * 10 + (*it - '0');
        }
        return ans;
    }
}

void Dijkstra(int s){
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for(int i = 1; i <= n + m; i++){
        int u = -1, MIN = INF;
        for(int j = 1; j <= n + m; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        vis[u] = true;
        for(int v = 1; v <= n + m; v++){
            if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]){
                d[v] = d[u] + G[u][v];
            }
        }
    }
}

int main(){
    fill(G[0], G[0] + MAXV * MAXV, INF);
    scanf("%d %d %d %d", &n, &m, &k, &D);
    string a, b;
    int dis;
    for(int i = 0; i < k; i++){
        cin>>a>>b>>dis;
        int u, v;
        u = Hashing(a);
        v = Hashing(b);
        G[u][v] = G[v][u] = dis;
    }

    int index = 0;
    double Max_min = 0; 
    for(int i = n + 1; i <= n + m; i++){
        Dijkstra(i);
        fill(vis, vis + MAXV, false);
        int min_d = INF, sum = 0;
        bool flag = true;
        for(int j = 1; j <= n; j++){
            if(d[j] > D){
                flag = false;
            }
            if(d[j] < min_d){
                min_d = d[j];
            }
            sum += d[j];
        }
        if(!flag){
            continue;
        }
        min_dis[i] = min_d;
        avg_dis[i] = (double)sum / (double)n;
        if(min_d > Max_min){
            index = i;
            Max_min = min_d;
        }
        else if(min_d == Max_min){
            if(avg_dis[i] < avg_dis[index]){
                index = i;
            }
        }
    }
    
    if(index == 0){
        printf("No Solution");
    }
    else{
        printf("G%d\n", index - n);
        printf("%.1lf %.1lf", min_dis[index], avg_dis[index]);
    }
    
    return 0;
}
