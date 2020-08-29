#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
	string name;
	int height;
}stu[10010];

bool cmp(node a, node b){
	if(a.height != b.height){
		return a.height > b.height;
	}
	else{
		return a.name < b.name;
	}
}

stack<string> s;
queue<string> q;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		cin>>stu[i].name>>stu[i].height;
	}
	sort(stu, stu + n, cmp);
	int index = 0;
	for(int i = 0; i < k; i++){
		if(i == 0 && n % k == 1){
			int cnt = 0;
			for(int j = 0; j < n / k + 1; j++){
				if(j % 2 == 0){
					q.push(stu[index++].name);
				}
				else{
					s.push(stu[index++].name);
				}
			}
			while(!s.empty()){
				printf("%s", s.top().c_str());
				s.pop();
				cnt++;
				if(cnt != n / k + 1){
					printf(" ");
				}
				else{
					printf("\n");
				}
			}
			while(!q.empty()){
				printf("%s", q.front().c_str());
				q.pop();
				cnt++;
				if(cnt != n / k + 1){
					printf(" ");
				}
				else{
					printf("\n");
				}
			}
		}
		else{
			int cnt = 0;
			for(int j = 0; j < n / k; j++){
				if(j % 2 == 0){
					q.push(stu[index++].name);
				}
				else{
					s.push(stu[index++].name);
				}
			}
			while(!s.empty()){
				printf("%s", s.top().c_str());
				s.pop();
				cnt++;
				if(cnt != n / k){
					printf(" ");
				}
				else{
					printf("\n");
				}
			}
			while(!q.empty()){
				printf("%s", q.front().c_str());
				q.pop();
				cnt++;
				if(cnt != n / k){
					printf(" ");
				}
				else{
					printf("\n");
				}
			}
		}
	}

	return 0;
}