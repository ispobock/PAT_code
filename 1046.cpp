#include <cstdio>
#include <map>
using namespace std;

struct edge{
	int u;
	int v;
}E[10010];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &E[i].u, &E[i].v);
	}
	int k;
	map<int, int> mp;
	scanf("%d", &k);
	int flag = false;
	for(int i = 0; i < k; i++){
		for(int j = 0; j < n; j++){
			int temp;
			scanf("%d", &temp);
			mp[temp] = j;
		}
		for(int j = 0; j < m; j++){
			if(mp[E[j].u] > mp[E[j].v]){
				if(flag == false){
					printf("%d", i);
					flag = true;
					break;
				}
				else{
					printf(" %d", i);
					break;
				}
			}
		}
		mp.clear();
	}
	return 0;
}