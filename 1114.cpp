#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int area;
	int set;
};

struct Node{
	string famid;
	double avgarea;
	double avgset;
	int num;
};

bool cmp(Node a, Node b){
	if(a.avgarea != b.avgarea){
		return a.avgarea > b.avgarea;
	}
	else{
		return a.famid < b.famid;
	}
}

map<string, bool> vis;
map<string, vector<string> > mp;
map<string, node> pro;
vector<Node> ans;

string fam_id;
int total_area, total_set;
int total_num;

void dfs(string s){
	vis[s] = true;
	total_num++;
	if(pro.find(s) != pro.end()){
		total_area += pro[s].area;
		total_set += pro[s].set;
	}
	if(s < fam_id){
		fam_id = s;
	}
	for(int i = 0; i < mp[s].size(); i++){
		if(vis[mp[s][i]] == false){
			dfs(mp[s][i]);
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		string id, fa, ma;
		cin>>id>>fa>>ma;
		vector<string> vi;
		mp[id] = vi;
		if(fa != "-1"){
			mp[id].push_back(fa);
			mp[fa].push_back(id);
			vis[fa] = false;
		}
		if(ma != "-1"){
			mp[id].push_back(ma);
			mp[ma].push_back(id);
			vis[ma] = false;
		}
		int k;
		scanf("%d", &k);
		for(int j = 0; j < k; j++){
			string ch;
			cin>>ch;
			mp[id].push_back(ch);
			mp[ch].push_back(id);
			vis[ch] = false;
		}
		int set, area;
		scanf("%d %d", &set, &area);
		pro[id].area = area;
		pro[id].set = set;
		vis[id] = false;
	}

	for(map<string, vector<string> >::iterator it = mp.begin(); it != mp.end(); it++){
		if(vis[it->first] == false){
			fam_id = it->first;
			total_area = 0;
			total_set = 0;
			total_num = 0;
			dfs(it->first);
			Node temp;
			temp.num = total_num;
			temp.famid = fam_id;
			double avga = (double)total_area / (double)total_num;
			double avgs = (double)total_set / (double)total_num;
			temp.avgarea = avga;
			temp.avgset = avgs;
			ans.push_back(temp);
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); i++){
		printf("%s %d %.3lf %.3lf\n", ans[i].famid.c_str(), ans[i].num, ans[i].avgset, ans[i].avgarea);
	}

	return 0;
}