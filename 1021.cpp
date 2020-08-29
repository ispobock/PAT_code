#include <cstdio>
#include <vector>
#include <set>
using namespace std;

const int maxv = 10010;
vector<int> adj[maxv];

int father[maxv];
int find_father(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	while(father[a] != x){
		int b = father[a];
		father[a] = x;
		a = b;
	}
	return x;
}

void Union(int a, int b){
	int fa = find_father(a);
	int fb = find_father(b);
	if(fa != fb){
		father[fa] = fb;
	}
}

bool vis[maxv] = {false};
int deepest;
void dfs(int s, int layer){
	vis[s] = true;
	layer++;
	if(layer > deepest){
		deepest = layer;
	}
	for(int i = 0; i < adj[s].size(); i++){
		//无向图有回去的边,不能走回头路
		if(vis[adj[s][i]] == false){
			dfs(adj[s][i], layer);
		}
	}
	vis[s] = false;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		father[i] = i;
	}
	for(int i = 0; i < n - 1; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		Union(u, v);
	}
	set<int> st;
	for(int i = 1; i <= n; i++){
		st.insert(find_father(i));
	}
	if(st.size() != 1){
		printf("Error: %d components\n", st.size());
		return 0;
	}
	set<int> ans;
	int Deepest = 0;
	for(int i = 1; i <= n; i++){
		deepest = 0;
		dfs(i, 0);
		if(deepest > Deepest){
			Deepest = deepest;
			ans.clear();
			ans.insert(i);
		}
		else if(deepest == Deepest){
			ans.insert(i);
		}
	}
	for(set<int>::iterator it = ans.begin(); it != ans.end(); it++){
		printf("%d\n", *it);
	}

	return 0;
}