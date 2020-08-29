#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAXV = 210;
const int INF = 0x3fffffff;
int G[MAXV][MAXV];
int w[MAXV];
int d[MAXV];
bool vis[MAXV] = {false};
map<string, int> toInt;
map<int, string> toString;
int n, k;
string st;
vector<int> pre[MAXV];
vector<int> temp, path;
int num = 0, hap, avg_hap;

void Dijkstra(int s){
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
        vis[u] = true;
        for(int v = 0; v < n; v++){
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

void DFS(int s){
    if(s == 0){
        num++;
        temp.push_back(s);
        int h = 0, avg;
        for(int i = 0; i < temp.size() - 1; i++){
            h += w[temp[i]];
        }
        avg = h / (temp.size() - 1);
        if(h > hap){
            path = temp;
            hap = h;
            avg_hap = avg;
        }
        else if(h == hap){
            if(avg > avg_hap){
                path = temp;
                avg_hap = avg;
            }
        }
        temp.pop_back();
    }
    temp.push_back(s);
    for(int i = 0; i < pre[s].size(); i++){
        DFS(pre[s][i]);
    }
    temp.pop_back();
}

int main(){
    fill(G[0], G[0] + MAXV * MAXV, INF);
    cin>>n>>k>>st;
    toInt[st] = 0;
    toString[0] = st;
    string str;
    for(int i = 1; i < n; i++){
        cin>>str>>w[i];
        toInt[str] = i;
        toString[i] = str;
    }
    string str1, str2;
    int cost;
    for(int i = 0; i < k; i++){
        cin>>str1>>str2>>cost;
        G[toInt[str1]][toInt[str2]] = cost;
        G[toInt[str2]][toInt[str1]] = cost;
    }
    Dijkstra(0);
    DFS(toInt["ROM"]);
    printf("%d %d %d %d\n", num, d[toInt["ROM"]], hap, avg_hap);
    for(int i = path.size() - 1; i >= 0; i--){
        printf("%s", toString[path[i]].c_str());
        if(i != 0){
            printf("->");
        }
    }
    
    return 0;
}