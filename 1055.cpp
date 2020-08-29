#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct Man{
	char name[10];
	int age;
	int wor;
}man[100010], valid[100010];

struct Que{
	int num;
	int amin;
	int amax;
}que[1010];

bool cmp(Man a, Man b){
	if(a.wor > b.wor){
		return 1;
	}
	else if(a.wor == b.wor && a.age < b.age){
		return 1;
	}
	else if(a.wor == b.wor && a.age == b.age && strcmp(a.name,b.name) < 0){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++){
		scanf("%s %d %d", man[i].name, &man[i].age, &man[i].wor);
	}
	for(int i = 0; i < K; i++){
		scanf("%d %d %d", &que[i].num, &que[i].amin, &que[i].amax);
	}

	sort(man, man+N, cmp);
	
	int Age[100010] = {0};
	int validNum = 0;
	//put top 100 man into a new array
	for(int i = 0; i<N; i++){
		if(Age[man[i].age] < 100){
			Age[man[i].age]++;
			valid[validNum++] = man[i];
		}
	}

	int n;
	for(int i = 0; i<K; i++){
		printf("Case #%d:\n", i+1);
		n = 0;
		for(int j = 0; j < validNum && n < que[i].num; j++){
			if(valid[j].age >= que[i].amin && valid[j].age <= que[i].amax){
				printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].wor);
				n++;
			}
			if(n == 0 && j == N-1){
				printf("None\n");
			}
		}
	}

	return 0;
}