#include <map>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

struct Node{
	string name;
	double tws1;
	int tws;
	int ns;
}node[100010];

bool cmp(Node a, Node b){
	if(a.tws > b.tws){
		return true;
	}
	if(a.tws == b.tws && a.ns < b.ns){
		return true;
	}
	if(a.tws == b.tws && a.ns == b.ns && strcmp(a.name.c_str(), b.name.c_str()) < 0){
		return true;
	}
	return false;
}

int main(){
	int n;
	scanf("%d", &n);
	int index = 0;
	map<string, int> mp;
	for(int i = 0; i < n; i++){
		string id, sch;
		double score;
		cin>>id;
		scanf("%lf", &score);
		cin>>sch;
		string s;
		for(int j = 0; j < sch.size(); j++){
			if(sch[j] >= 'A' && sch[j] <= 'Z'){
				s += sch[j] - 'A' + 'a'; 
			}
			else{
				s += sch[j];
			}
		}
		sch = s;

		if(mp.find(sch) != mp.end()){
			node[mp[sch]].ns++;
			if(id[0] == 'A'){
				node[mp[sch]].tws1 += score;
			}
			else if(id[0] == 'B'){
				node[mp[sch]].tws1 += score / 1.5;
			}
			else if(id[0] == 'T'){
				node[mp[sch]].tws1 += score * 1.5;
			}
		}
		else{
			mp[sch] = index;
			node[index].name = sch;
			node[index].ns = 1;
			if(id[0] == 'A'){
				node[index].tws1 = score;
			}
			else if(id[0] == 'B'){
				node[index].tws1 = score / 1.5;
			}
			else{
				node[index].tws1 = score * 1.5;
			}
			index++;
		}
	}
	for(int i = 0; i < index; i++){
		node[i].tws = (int)node[i].tws1;
	}
	printf("%d\n", index);
	sort(node, node + index, cmp);
	int rank = 1;
	for(int i = 0; i < index; i++){
		if(i == 0){
			printf("1 %s %d %d\n", node[0].name.c_str(), node[0].tws, node[0].ns);
			continue;
		}
		if(node[i - 1].tws == node[i].tws){
			printf("%d %s %d %d\n", rank, node[i].name.c_str(), node[i].tws, node[i].ns);
			continue;
		}
		if(node[i - 1].tws != node[i].tws){
			rank = i + 1;
			printf("%d %s %d %d\n", rank, node[i].name.c_str(), node[i].tws, node[i].ns);
			continue;
		}
	}
	return 0;
}