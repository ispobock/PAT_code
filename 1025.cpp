#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct testee{
	char id[15];
	int score;
	int final_rank;
	int loca_num;
	int local_rank;
};

bool cmp(testee a,testee b){
	if(a.score != b.score){
		return a.score > b.score;
	}else{
		return strcmp(a.id, b.id) < 0;
	}
}

int main(){
	testee test[30010];
	int N, K, n =0;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &K);
		for(int j = 0; j < K; j++){
			scanf("%s %d", test[n + j].id, &test[n + j].score);
			test[n + j].loca_num = i+1;
		}
		//Sorting
		sort(test+n, test+n+K, cmp);
		//Ranking
		test[n].local_rank = 1;
		for(int j = 1; j< K; j++){
			if(test[n+j].score == test[n+j-1].score){
				test[n+j].local_rank = test[n+j-1].local_rank;
			}else{
				test[n+j].local_rank = j+1;
			}
		}

		n += K;
	}

	sort(test, test + n, cmp);
	test[0].final_rank = 1;
	for(int i = 1; i < n; i++){
		if(test[i].score == test[i-1].score){
			test[i].final_rank = test[i-1].final_rank;
		}else{
			test[i].final_rank = i+1;
		}
	}

	printf("%d\n", n);
	for(int i=0; i < n; i++){
		printf("%s %d %d %d\n", test[i].id, test[i].final_rank, test[i].loca_num, test[i].local_rank);
	}
	

	
	return 0;
}