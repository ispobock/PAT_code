#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct Rec{
	char id[10];
	char name[10];
	int grade;
}rec[100010];

bool cmp1(Rec a, Rec b){
	return strcmp(a.id, b.id) < 0;
}

bool cmp2(Rec a, Rec b){
	if(strcmp(a.name, b.name) < 0){
		return 1;
	}
	else if(strcmp(a.id, b.id) < 0 && strcmp(a.name, b.name) == 0){
		return 1;
	}
	else{
		return 0;
	}
}

bool cmp3(Rec a, Rec b){
	if(a.grade < b.grade){
		return 1;
	}
	else if(strcmp(a.id, b.id) < 0 && a.grade == b.grade){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	int N, C;
	scanf("%d %d", &N, &C);
	for(int i = 0; i < N; i++){
		scanf("%s %s %d", rec[i].id, rec[i].name, &rec[i].grade);
	}
	
	if(C == 1){
		sort(rec, rec+N, cmp1);
	}
	else if(C == 2){
		sort(rec, rec+N, cmp2);
	}
	else{
		sort(rec, rec+N, cmp3);
	}

	for(int i = 0; i<N; i++){
		printf("%s %s %d\n", rec[i].id, rec[i].name, rec[i].grade);
	}

	return 0;
}