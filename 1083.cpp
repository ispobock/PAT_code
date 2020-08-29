#include <cstdio>
#include <algorithm>

using namespace std;

struct Stu{
	char name[15];
	char id[15];
	int grade;
}stu[100000];

bool cmp(Stu a, Stu b){
	return a.grade > b.grade;
}

int main(){
	int bou1, bou2;
	int N;
	scanf("%d", &N);
	for(int i = 0; i<N; i++){
		scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
	}
	scanf("%d %d", &bou1, &bou2);

	sort(stu, stu+N, cmp);
	
	bool flag = true;
	for(int i = 0; i<N; i++){
		if(stu[i].grade >= bou1 && stu[i].grade <= bou2){
			printf("%s %s\n", stu[i].name, stu[i].id);
			flag = false;
		}
	}
	if(flag){
		printf("NONE\n");
	}
	return 0;
}