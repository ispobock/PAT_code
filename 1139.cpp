#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXV = 310;
const int INF = 0x7fffffff;
int G[MAXV][MAXV];
bool ismale[MAXV] = {false};

struct node{
	string a;
	string b;
};

vector<node> v;

bool cmp(node a, node b){
	if(a.a != b.a){
		return a.a < b.a;
	}
	else{
		return a.b < b.b;
	}
}

int main(){
	int n, m;
	map<string, int> mp;
	map<int, string> mp1;
	scanf("%d %d", &n, &m);
	fill(G[0], G[0] + MAXV * MAXV, INF);
	int index = 0;
	for(int i = 0; i < m; i++){
		string str1, str2;
		cin>>str1>>str2;
		if(str1[0] != '-'){
			if(mp.find(str1) == mp.end()){
				mp[str1] = index;
				mp1[index] = str1;
				ismale[index] = true;
				index++;
			}
		}
		else{
			str1 = str1.substr(1, str1.size());
			if(mp.find(str1) == mp.end()){
				mp[str1] = index;
				mp1[index] = str1;
				index++;
			}
		}
		if(str2[0] != '-'){
			if(mp.find(str2) == mp.end()){
				mp[str2] = index;
				mp1[index] = str2;
				ismale[index] = true;
				index++;
			}
		}
		else{
			str2 = str2.substr(1, str2.size());
			if(mp.find(str2) == mp.end()){
				mp[str2] = index;
				mp1[index] = str2;
				index++;
			}
		}
		G[mp[str1]][mp[str2]] = G[mp[str2]][mp[str1]] = 1;
	}

	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		string str1, str2;
		cin>>str1>>str2;
		if(str1[0] == '-'){
			str1 = str1.substr(1, str1.size());
		}
		if(str2[0] == '-'){
			str2 = str2.substr(1, str2.size());
		}
		if(mp.find(str1) == mp.end() || mp.find(str2) == mp.end()){
			printf("0\n");
			continue;
		}
		int p1 = mp[str1], p2 = mp[str2];
		for(int j = 0; j < n; j++){
			if(G[p1][j] == 1 && ismale[p1] == ismale[j] && j != p2){
				for(int l = 0; l < n; l++){
					if(G[j][l] == 1 && ismale[l] == ismale[p2] && G[p2][l] == 1 && l != p1){
						node pa;
						pa.a = mp1[j];
						pa.b = mp1[l];
						v.push_back(pa);
					}
				}
			}
		}
		sort(v.begin(), v.end(), cmp);
		printf("%d\n", v.size());
		for(vector<node>::iterator it = v.begin(); it != v.end(); it++){
			printf("%s %s\n", (*it).a.c_str(), (*it).b.c_str());
		}
		v.clear();
	}

	return 0;
}