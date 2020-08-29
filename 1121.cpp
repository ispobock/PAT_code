#include <cstdio>
#include <map>
#include <string>
#include <set>
using namespace std;

bool Hash[100000] = {false};

int main(){
	int n, m;
	scanf("%d", &n);
	map<int, int> mp;
	for(int i = 0; i < n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		mp[a] = b;
		mp[b] = a;
	}
	scanf("%d", &m);
	int gest[10010];
	for(int i = 0; i < m; i++){
		scanf("%d", &gest[i]);
		Hash[gest[i]] = true;
	}
	set<int> lone;
	for(int i = 0; i < m; i++){
		if(Hash[mp[gest[i]]] == false){
			lone.insert(gest[i]);
		}
	}
	printf("%d\n", lone.size());
	int cnt = 0;
	for(set<int>::iterator it = lone.begin(); it != lone.end(); it++){
		printf("%05d", *it);
		cnt++;
		if(cnt < lone.size()){
			printf(" ");
		}
		else{
			printf("\n");
		}
	}

	return 0;
}