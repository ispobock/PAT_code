#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct Sub{
	char id[10];
	int num;
	int score;
}sub[100010];

struct User{
	int rank;
	char id[10];
	int total;
	int s[10];
	int p_s;
	bool is_null[10];
	bool has_0;
}user[10010];

bool cmp1(Sub a, Sub b){
	if(strcmp(a.id, b.id)<0){
		return 1;
	}
	else if(strcmp(a.id, b.id) == 0 && a.num < b.num){
		return 1;
	}
	else if(strcmp(a.id, b.id) == 0 && a.num == b.num && a.score > b.score){
		return 1;
	}
	else{
		return 0;
	}
}

bool cmp2(User a, User b){
	if(a.total > b.total){
		return 1;
	}
	else if(a.total == b.total && a.p_s > b.p_s){
		return 1;
	}
	else if(a.total == b.total && a.p_s == b.p_s && strcmp(a.id, b.id) < 0){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	int N, K, M;
	int p[6];
	scanf("%d %d %d", &N, &K, &M);
	for(int i = 0; i<K; i++){
		scanf("%d", &p[i]);
	}
	for(int i = 0; i<M; i++){
		scanf("%s %d %d", sub[i].id, &sub[i].num, &sub[i].score);
	}
	
	sort(sub, sub+M, cmp1);
	
	int subUserNum = 0;
	strcpy(user[subUserNum].id,sub[0].id);
	user[subUserNum].p_s = 0;
	user[subUserNum].total = 0;
	if(sub[0].score >= 0){
		user[subUserNum].s[sub[0].num-1] = sub[0].score;
		user[subUserNum].total += sub[0].score;
		user[subUserNum].is_null[sub[0].num-1] = true;
		if(sub[0].score == 0){
			user[subUserNum].has_0 = true;
		}
	}
	if(sub[0].score < 0){
		user[subUserNum].s[sub[0].num-1] = 0;
		user[subUserNum].total += 0;
		user[subUserNum].is_null[sub[0].num-1] = true;
	}
	if(sub[0].score == p[sub[0].num-1]){
		user[subUserNum].p_s++;
	}
	for(int i = 1; i<M; i++){
		if(strcmp(sub[i-1].id,sub[i].id) != 0){
			strcpy(user[++subUserNum].id,sub[i].id);
			user[subUserNum].p_s = 0;
			user[subUserNum].total = 0;
			if(sub[i].score >= 0){
				user[subUserNum].s[sub[i].num-1] = sub[i].score;
				user[subUserNum].total += sub[i].score;
				user[subUserNum].is_null[sub[i].num-1] = true;
				if(sub[i].score == 0){
					user[subUserNum].has_0 = true;
				}
			}
			if(sub[i].score < 0){
				user[subUserNum].s[sub[i].num-1] = 0;
				user[subUserNum].total += 0;
				user[subUserNum].is_null[sub[i].num-1] = true;
			}
			if(sub[i].score == p[sub[i].num-1]){
				user[subUserNum].p_s++;
			}
		}
		else{
			if(sub[i-1].num != sub[i].num){
				if(sub[i].score >= 0){
					user[subUserNum].s[sub[i].num-1] = sub[i].score;
					user[subUserNum].total += sub[i].score;
					user[subUserNum].is_null[sub[i].num-1] = true;
					if(sub[i].score == 0){
						user[subUserNum].has_0 = true;
					}
				}
				if(sub[i].score < 0){
					user[subUserNum].s[sub[i].num-1] = 0;
					user[subUserNum].total += 0;
					user[subUserNum].is_null[sub[i].num-1] = true;
				}
				if(sub[i].score == p[sub[i].num-1]){
					user[subUserNum].p_s++;
				}
			}
		}
	}

	sort(user, user+subUserNum+1, cmp2);

	user[0].rank = 1;
	for(int i = 1; i<subUserNum+1; i++){
		if(user[i-1].total == user[i].total){
			user[i].rank = user[i-1].rank;
		}
		else{
			user[i].rank = i+1;
		}
	}

	for(int i = 0; i<subUserNum+1; i++){
		if(user[i].total > 0 || (user[i].total == 0 && user[i].has_0)){
			printf("%d %s %d ", user[i].rank, user[i].id, user[i].total);
			for(int j = 0; j<K; j++){
				if(user[i].s[j] >= 0 && user[i].is_null[j]){
					printf("%d", user[i].s[j]);
				}
				else{
					printf("-");
				}
				if(j != K-1){
					printf(" ");
				}
			}
			printf("\n");
		}
	}

	return 0;
}