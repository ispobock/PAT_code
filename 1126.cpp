#include <cstdio>
#include <vector>
using namespace std;

const int maxv = 510;
int n, m;
vector<int> adj[maxv];
int st, ed;
vector<int> temp;
bool isE = false;
bool vis[maxv] = {false};

void dfs(int s){
	vis[s] = true;
	if(temp.size() == n - 1){
		isE = true;
		return;
	}
	temp.push_back(s);
	for(int i = 0; i < adj[s].size(); i++){
		if(vis[adj[s][i]] == false){
			dfs(adj[s][i]);
		}
	}
	temp.pop_back();
	vis[s] = false;
	return;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int count = 0;
	int flag = 0;
	for(int i = 1; i <= n; i++){
		int degree = adj[i].size();
		printf("%d", degree);
		if(i != n){
			printf(" ");
		}
		else{
			printf("\n");
		}
		if(count == 0 && degree % 2 == 1){
			flag++;
			st = i;
			count++;
		}
		else if(count == 1 && degree % 2 == 1){
			ed = i;
			flag++;
			count++;
		}
		else if(count > 1 && degree % 2 == 1){
			flag = 3;
		}
	}

	if(flag == 0){
		dfs(1);
		if(isE){
			printf("Eulerian\n");
			return 0;
		}
	}
	if(flag == 2){
		printf("Semi-Eulerian\n");
	}
	else{
		printf("Non-Eulerian\n");
	}
	return 0;
}