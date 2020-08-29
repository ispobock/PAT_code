#include <cstdio>
#include <set>
using namespace std;

int father[1000000];

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

set<int> bird;

int main(){
	for(int i = 0; i < 10000; i++){
		father[i] = i;
	}
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for(int i = 0; i < n; i++){
		int k;
		scanf("%d", &k);
		if(k > 0){
			int a, b;
			scanf("%d", &a);
			bird.insert(a);
			for(int j = 0; j < k - 1; j++){
				scanf("%d", &b);
				bird.insert(b);
				Union(a, b);
				a = b;
			}
		}
		else{
			cnt++;
		}
	}

	set<int> tree;
	for(int i = 1; i <= bird.size(); i++){
		tree.insert(find_father(i));
	}

	printf("%d %d\n", tree.size() + cnt, bird.size());

	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		if(u > bird.size() || v > bird.size() || u < 1 || v < 1){
			printf("No\n");
			continue;
		}
		if(find_father(u) == find_father(v)){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}

	return 0;
}
