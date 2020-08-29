#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;

const int maxn = 2005;
const int inf = 0x7fffffff;
int G[maxn][maxn];
bool vis[maxn] = {false};
int n, k;
int index = 0;
map<string, int> mp;
int total, num;
int weight[maxn] = {0};
int maxw, maxi;

void DFS(int u){
    vis[u] = true;
    num++;
    if(weight[u] > maxw){
        maxw = weight[u];
        maxi = u;
    }
    for(int v = 0; v < index; v++){
        if(G[u][v] != inf){
            total += G[u][v];
            if(vis[v] == false){
                DFS(v);
            } 
        }
    }
}

int main(){
    for(int i = 0; i < 2002; i++){
        for(int j = 0; j < 2002; j++){
            G[i][j] = inf;
        }
    }
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        string name1, name2;
        cin>>name1>>name2;
        int time;
        scanf("%d", &time);
        if(mp.find(name1) == mp.end()){
            mp[name1] = index;
            index++;
        }
        if(mp.find(name2) == mp.end()){
            mp[name2] = index;
            index++;
        }
        if(G[mp[name1]][mp[name2]] == inf){
            G[mp[name1]][mp[name2]] = time;
            //G[mp[name2]][mp[name1]] = time;
        }
        else{
            G[mp[name1]][mp[name2]] += time;
            //G[mp[name2]][mp[name1]] += time;
        }
    }

    for(int i = 0; i < index; i++){
        for(int j = 0; j < index; j++){
            if(G[i][j] != inf){
                weight[i] += G[i][j];
                weight[j] += G[i][j];
            }
        }
    }

    int ans = 0;
    map<string, int> head;
    for(int i = 0; i < index; i++){
        if(vis[i] == false){
            maxw = -1;
            total = 0;
            num = 0;
            DFS(i);
            if(total > k && num > 2){
                ans++;
                for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++){
                    if(it->second == maxi){
                        head[it->first] = num;
                        break;
                    }
                }
            }
        }
    }
    printf("%d\n", ans, num);
    for(map<string, int>::iterator it = head.begin(); it != head.end(); it++){
        printf("%s %d\n", it->first.c_str(), it->second);
    }

    return 0;
}