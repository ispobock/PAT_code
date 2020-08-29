#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;

struct node{
	int id;
	int dis;
	int time;
};

const int maxv = 510;
const int inf = 0x3fffffff;
vector<node> adj[maxv];
int D[maxv];
int G[maxv][maxv];
int T[maxv];
bool vis[maxv] = {false};
vector<int> pre_d[maxv];
vector<int> pre_t[maxv];
int ed, st;

void dijkstra_d(int s){
	fill(D, D + maxv, inf);
	fill(vis, vis + maxv, false);
	D[s] = 0;
	for(int i = 0; i < n; i++){
		int u = -1, MIN = inf;
		for(int j = 0; j < n; j++){
			if(vis[j] == false && D[j] < MIN){
				u = j;
				MIN = D[j];
			}
		}
		vis[u] = true;
		for(int v = 0; v < adj[u].size(); v++){
			if(vis[adj[u][v].id] == false){
				if(D[u] + adj[u][v].dis < D[adj[u][v].id]){
					pre_d[adj[u][v].id].clear();
					D[adj[u][v].id] = D[u] + adj[u][v].dis;
					pre_d[adj[u][v].id].push_back(u);
				}
				else if(D[u] + adj[u][v].dis == D[adj[u][v].id]){
					pre_d[adj[u][v].id].push_back(u);
				}
			}
		}
	}
}

void dijkstra_t(int s){
	fill(T, T + maxv, inf);
	fill(vis, vis + maxv, false);
	T[s] = 0;
	for(int i = 0; i < n; i++){
		int u = -1, MIN = inf;
		for(int j = 0; j < n; j++){
			if(vis[j] == false && T[j] < MIN){
				u = j;
				MIN = T[j];
			}
		}
		vis[u] = true;
		for(int v = 0; v < adj[u].size(); v++){
			if(vis[adj[u][v].id] == false){
				if(T[u] + adj[u][v].time < T[adj[u][v].id]){
					pre_t[adj[u][v].id].clear();
					T[adj[u][v].id] = T[u] + adj[u][v].time;
					pre_t[adj[u][v].id].push_back(u);
				}
				else if(T[u] + adj[u][v].time == T[adj[u][v].id]){
					pre_t[adj[u][v].id].push_back(u);
				}
			}
		}
	}
}

vector<int> temp, path_d, path_t;
int mintime = inf, minsec = inf;
void dfs_d(int ed){
	if(ed == st){
		temp.push_back(ed);
		int timecost = 0;
		for(int i = temp.size() - 1; i > 0; i--){
			timecost += G[temp[i]][temp[i - 1]];
		}
		if(timecost < mintime){
			mintime = timecost;
			path_d = temp;
		}
		temp.pop_back();
		return;
	}
	temp.push_back(ed);
	for(int i = 0; i < pre_d[ed].size(); i++){
		dfs_d(pre_d[ed][i]);
	}
	temp.pop_back();
}

void dfs_t(int ed){
	if(ed == st){
		temp.push_back(ed);
		if(temp.size() < minsec){
			minsec = temp.size();
			path_t = temp;
		}
		temp.pop_back();
		return;
	}
	temp.push_back(ed);
	for(int i = 0; i < pre_t[ed].size(); i++){
		dfs_t(pre_t[ed][i]);
	}
	temp.pop_back();
}

int main(){
	fill(G[0], G[0] + maxv * maxv, inf);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int u, v, is, d, t;
		scanf("%d %d %d %d %d", &u, &v, &is, &d, &t);
		node temp;
		G[u][v] = t;
		temp.id = v;
		temp.dis = d;
		temp.time = t;
		adj[u].push_back(temp);
		if(is == 0){
			temp.id = u;
			adj[v].push_back(temp);
			G[v][u] = t;
		}
	}
	scanf("%d %d", &st, &ed);
	dijkstra_d(st);
	dfs_d(ed);
	temp.clear();
	dijkstra_t(st);
	dfs_t(ed);
	bool isSame = true;
	if(path_d.size() != path_t.size()){
		isSame = false;
	}
	else{
		for(int i = 0; i < path_d.size(); i++){
			if(path_d[i] != path_t[i]){
				isSame = false;
				break;
			}
		}
	}
	if(isSame){
		printf("Distance = %d; Time = %d: ", D[ed], T[ed]);
		for(int i = path_d.size() - 1; i >= 0; i--){
			printf("%d", path_d[i]);
			if(i != 0){
				printf(" -> ");
			}
			else{
				printf("\n");
			}
		}
	}
	else{
		printf("Distance = %d: ", D[ed]);
		for(int i = path_d.size() - 1; i >= 0; i--){
			printf("%d", path_d[i]);
			if(i != 0){
				printf(" -> ");
			}
			else{
				printf("\n");
			}
		}
		printf("Time = %d: ", T[ed]);
		for(int i = path_t.size() - 1; i >= 0; i--){
			printf("%d", path_t[i]);
			if(i != 0){
				printf(" -> ");
			}
			else{
				printf("\n");
			}
		}
	}

	return 0;
}