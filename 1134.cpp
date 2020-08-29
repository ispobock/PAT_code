#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

const int maxv = 10010;
vector<int> adj[maxv];
bool vis[maxv] = {false};

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(i);
		adj[b].push_back(i);
	}

	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		memset(vis, false, sizeof(vis));
		int nv;
		scanf("%d", &nv);
		int count = 0;
		for(int j = 0; j < nv; j++){
			int v;
			scanf("%d", &v);
			for(int l = 0; l < adj[v].size(); l++){
				if(vis[adj[v][l]] == false){
					count++;
					vis[adj[v][l]] = true;
				}
			}
		}

		if(count == m){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}

	return 0;
}