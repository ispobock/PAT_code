#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct node{
	string id;
	int gp, gm, gf;
	int g;
}stu[100010];

map<string, int> mp;

bool cmp(node a, node b){
	if(a.g != b.g){
		return a.g > b.g;
	}
	else{
		return a.id < b.id;
	}
}

int main(){
	int p, m, n;
	scanf("%d %d %d", &p, &m, &n);
	int index = 0;
	for(int i = 0; i < p; i++){
		string str;
		int temp;
		cin>>str>>temp;
		if(mp.find(str) != mp.end()){
			stu[mp[str]].gp = temp;
		}
		else{
			stu[index].id = str;
			stu[index].gp = temp;
			stu[index].gm = stu[index].gf = stu[index].g = -1;
			mp[str] = index;
			index++;
		}
	}
	for(int i = 0; i < m; i++){
		string str;
		int temp;
		cin>>str>>temp;
		if(mp.find(str) != mp.end()){
			stu[mp[str]].gm = temp;
		}
		else{
			stu[index].id = str;
			stu[index].gm = temp;
			stu[index].gp = stu[index].gf = stu[index].g = -1;
			mp[str] = index;
			index++;
		}
	}
	for(int i = 0; i < n; i++){
		string str;
		int temp;
		cin>>str>>temp;
		if(mp.find(str) != mp.end()){
			stu[mp[str]].gf = temp;
		}
		else{
			stu[index].id = str;
			stu[index].gf = temp;
			stu[index].gm = stu[index].gp = stu[index].g = -1;
			mp[str] = index;
			index++;
		}
	}
	int count = 0;
	for(int i = 0; i < index; i++){
		if(stu[i].gp >= 200 && stu[i].gm > stu[i].gf){
			stu[i].g = stu[i].gm * 0.4 + stu[i].gf * 0.6 + 0.5;
			if(stu[i].g >= 60) count++;
		}
		else if(stu[i].gp >= 200 && stu[i].gm <= stu[i].gf){
			stu[i].g = stu[i].gf;
			if(stu[i].g >= 60) count++;
		}
	}
	sort(stu, stu + index, cmp);
	for(int i = 0; i < count; i++){
		printf("%s %d %d %d %d\n", stu[i].id.c_str(), stu[i].gp, stu[i].gm, stu[i].gf, stu[i].g);
	}

	return 0;
}