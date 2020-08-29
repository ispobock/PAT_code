#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxv = 10110;
const int inf = 0x7fffffff;

struct Sta{
	int id;
	int line;
};

vector<Sta> adj[maxv];
vector<Sta> path, temp;
int st, ed;
int min_trans = inf;
int MIN = inf;
int vis[maxv] = {false};

void DFS(int s){
	if(s == ed){
		if(temp.size() < MIN){
			path = temp;
			MIN = temp.size();
			int now = temp[0].line;                        // 思维漏洞
			int cnt = 0;
			for(int i = 1; i < temp.size(); i++){
				if(temp[i].line != now){
					cnt++;
					now = temp[i].line;
				}
			}
			min_trans = cnt;
		}
		else if(temp.size() == MIN){
			int now = temp[0].line;
			int cnt = 0;
			for(int i = 1; i < temp.size(); i++){
				if(temp[i].line != now){
					cnt++;
					now = temp[i].line;
				}
			}
			if(cnt < min_trans){
				path = temp;
				min_trans = cnt;
			}
		}
	}
	if(temp.size() > MIN){  //剪枝
		return;
	}
	for(int i = 0; i < adj[s].size(); i++){
		if(vis[adj[s][i].id] == false){ 
			temp.push_back(adj[s][i]);
			vis[adj[s][i].id] = true;  // 防止绕圈
			DFS(adj[s][i].id);
			vis[adj[s][i].id] = false;
			temp.pop_back();
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int k, a, b;
		Sta x, y;
		scanf("%d %d", &k, &a);
		x.id = a;
		x.line = i;
		for(int j = 0; j < k - 1; j++){
			scanf("%d", &b);
			y.id = b;
			y.line = i;
			adj[a].push_back(y);
			adj[b].push_back(x);
			a = b;
			x = y;
		}
	}

	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &st, &ed);
		min_trans = inf;
		MIN = inf;
		fill(vis, vis + maxv, false);
		vis[st] = true;
		DFS(st);
		printf("%d\n", MIN);
		int now = path[0].line;
		int u;
		u = st;
		for(int j = 1; j < path.size(); j++){
			if(path[j].line != now){
				printf("Take Line#%d from %04d to %04d.\n", now, u, path[j - 1].id);
				u = path[j - 1].id;
				now = path[j].line;
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", now, u, ed);
	}

	return 0;
}