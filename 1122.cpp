#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

const int maxv = 210;
int G[maxv][maxv];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	fill(G[0], G[0] + maxv * maxv, 0);
	set<int> st;
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		G[a][b] = G[b][a] = 1;
		st.insert(a);
		st.insert(b);
	}
	
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		int num, u;
		scanf("%d %d", &num, &u);
		int start = u;
		bool isH = true;
		set<int> s;
		if(st.find(u) == st.end()){
			isH = false;
		}
		else{
			s.insert(u);
			for(int j = 0; j < num - 1; j++){
				int v;
				scanf("%d", &v);
				if(G[u][v] == 0){
					isH = false;
				}
				if(st.find(v) == st.end()){
					isH = false;
				}
				else{
					s.insert(v);
				}
				if(start == v && j != num - 2){
					isH = false;
				}
				if(start != v && j == num - 2){
					isH = false;
				}
				u = v;
			}
		}
		if(s.size() == st.size() && isH){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}

	return 0;
}