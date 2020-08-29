#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
	int id, time;
};

bool cmp(node a, node b){
	if(a.time != b.time){
		return a.time > b.time;
	}
	else{
		return a.id < b.id;
	}
}

bool Hash[50010] = {false};
vector<node> v;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		int item;
		scanf("%d", &item);
		for(int j = 0; j < v.size() && j < k; j++){
			if(j == 0){
				printf("%d:", item);
			}
			printf(" %d", v[j].id);
		}
		if(i != 0){
			printf("\n");
		}
		if(Hash[item] == false){
			node temp;
			temp.id = item;
			temp.time = 1;
			v.push_back(temp);
			Hash[item] = true;
			if(v.size() <= k){
				sort(v.begin(), v.end(), cmp);
			}
			else{
				if(v[k - 1].time == 1 && v[k - 1].id > item){
					swap(v[k - 1], v[v.size() - 1]);
				}
				sort(v.begin(), v.begin() + k, cmp);
			}
		}
		else{
			int j;
			for(j = 0; j < v.size(); j++){
				if(v[j].id == item){
					v[j].time++;
					break;
				}
			}
			sort(v.begin(), v.begin() + j + 1, cmp);
		}
	}
	return 0;
}