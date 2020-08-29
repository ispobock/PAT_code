#include <cstdio>
#include <vector>
using namespace std;

int n, k, h;

struct node{
	int data;
	int now;
	int next;
}L[100010];


int main(){
	scanf("%d %d %d", &h, &n, &k);
	for(int i = 0; i < n; i++){
		int add;
		scanf("%d", &add);
		L[add].now = add;
		scanf("%d %d", &L[add].data, &L[add].next);
	}
	int cur = h;
	vector<node> list;
	vector<node> prek;
	vector<node> aftk;
	for(int i = 0; i < n; i++){
		if(L[cur].data < 0){
			list.push_back(L[cur]);
		}
		else if(L[cur].data <= k){
			prek.push_back(L[cur]);
		}
		else{
			aftk.push_back(L[cur]);
		}
		cur = L[cur].next;
		if(cur == -1){
			break;
		}
	}
	for(int i = 0; i < prek.size(); i++){
		list.push_back(prek[i]);
	}
	for(int i = 0; i < aftk.size(); i++){
		list.push_back(aftk[i]);
	}

	for(int i = 0; i < list.size() - 1; i++){
		printf("%05d %d %05d\n", list[i].now, list[i].data, list[i + 1].now);	
	}
	printf("%05d %d -1\n", list[list.size() - 1].now, list[list.size() - 1].data);

	return 0;
}