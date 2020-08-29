#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int G[250][250];
const int INF = 1000000000;

int main(){
	int nv, ne;
	scanf("%d %d", &nv, &ne);
	fill(G[0], G[0] + 250 * 250, INF);
	for(int i = 0; i < ne; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u][v] = 1;
		G[v][u] = 1;
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int k;
		scanf("%d", &k);
		int temp;
		bool Hash[250] = {false};
		vector<int> st;
		bool isclique = true;
		for(int j = 0; j < k; j++){
			scanf("%d", &temp);
			Hash[temp] = true; //不能在这里判断，让他输入完！！！
			/*
			for(int l = 0; l < st.size(); l++){ 
				if(G[st[l]][temp] != 1){
					isclique = false;
					break;
				}
			}
			*/
			st.push_back(temp);

		}
		for(int j = 0; j < k; j++){
			for(int l = j + 1; l < k; l++){
				if(G[st[j]][st[l]] != 1){
					isclique = false;
					break;
				}
			}
			if(isclique == false){
				printf("Not a Clique\n");
				break;
			}
		}

		if(isclique == false) continue; 

		bool isMaximal = true;
		for(int j = 1; j <= nv; j++){
			if(Hash[j] == true) continue;
			for(int l = 0; l < st.size(); l++){
				if(G[st[l]][j] != 1){
					break;
				}
				if(l == st.size() - 1) isMaximal = false;
			}	
			if(!isMaximal){
				printf("Not Maximal\n");
				break;
			}
		}
		if(isMaximal){
			printf("Yes\n");
		}
	}
	
	return 0;
}