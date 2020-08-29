#include <cstdio>
#include <algorithm>

using namespace std;

struct App{
	int id;
	int GE,GI;
	int pre[6];
}app[40010];

struct School{
	int ad[40010];
	int l_GE,l_GI;
	int num;
}sch[105];

bool cmp(App a, App b){
	if((a.GE+a.GI) > (b.GE + b.GI)){
		return 1;
	}
	else if((a.GE+a.GI) == (b.GE + b.GI) && a.GE > b.GE){
		return 1;
	}
	else{
		return 0;
	}
}

bool cmp1(int a, int b){
	return a < b;
}

int main(){
	int	N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	int quota[105];
	for(int i = 0; i < M; i++){
		scanf("%d", &quota[i]);
	}
	for(int i = 0; i < N; i++){
		scanf("%d %d", &app[i].GE, &app[i].GI);
		app[i].id = i;
		for(int j = 0; j<K; j++){
			scanf("%d", &app[i].pre[j]);
		}
	}
	
	sort(app, app+N, cmp);
	
	for(int i = 0; i<M; i++){
		sch[i].num = 0;
		sch[i].l_GE = -1;
		sch[i].l_GI = -1;
	}

	for(int i = 0; i<N; i++){
		for(int j = 0; j<K; j++){
			if(sch[app[i].pre[j]].num < quota[app[i].pre[j]]){
				sch[app[i].pre[j]].ad[sch[app[i].pre[j]].num++] = app[i].id;
				sch[app[i].pre[j]].l_GE = app[i].GE;
				sch[app[i].pre[j]].l_GI = app[i].GI;
				break;
			}
			else if(app[i].GE == sch[app[i].pre[j]].l_GE && app[i].GI == sch[app[i].pre[j]].l_GI){
				sch[app[i].pre[j]].ad[sch[app[i].pre[j]].num++] = app[i].id;
				break;
			}
		}
	}

	for(int i = 0; i<M; i++){
		sort(sch[i].ad, sch[i].ad+sch[i].num, cmp1);
		for(int j = 0; j<sch[i].num; j++){
			if(j == sch[i].num-1){
				printf("%d", sch[i].ad[j]);
			}
			else{
				printf("%d ",sch[i].ad[j]);
			}
		}
		printf("\n");
	}


	return 0;
}