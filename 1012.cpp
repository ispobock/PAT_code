#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct Stu{
	char id[10];
	int grade_a;
	int grade_c;
	int grade_m;
	int grade_e;
	int c_r;
	int m_r;
	int a_r;
	int e_r;
	int b_r;
	char b_r_k;
}stu[2010];

struct C_stu{
	char id[10];
}c_stu[2010];

bool cmp_a(Stu a, Stu b){
	return a.grade_a > b.grade_a;
}

bool cmp_c(Stu a, Stu b){
	return a.grade_c > b.grade_c;
}

bool cmp_m(Stu a, Stu b){
	return a.grade_m > b.grade_m;
}

bool cmp_e(Stu a, Stu b){
	return a.grade_e > b.grade_e;
}

int main(){
	//input
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		scanf("%s %d %d %d", stu[i].id, &stu[i].grade_c, &stu[i].grade_m, &stu[i].grade_e);
		stu[i].grade_a = (double)(stu[i].grade_c+stu[i].grade_m+stu[i].grade_e)/3.0;
	}
	for(int i = 0; i<M; i++){
		scanf("%s", c_stu[i].id);
	}
	
	//sorting & ranking
	sort(stu, stu+N, cmp_a);
	stu[0].a_r = 1;
	for(int i = 1; i < N; i++){
		if(stu[i].grade_a < stu[i-1].grade_a){
			stu[i].a_r = i+1;
		}else{
			stu[i].a_r = stu[i-1].a_r;
		}
	}

	sort(stu, stu+N, cmp_c);
	stu[0].c_r = 1;
	for(int i = 1; i < N; i++){
		if(stu[i].grade_c < stu[i-1].grade_c){
			stu[i].c_r = i+1;
		}else{
			stu[i].c_r = stu[i-1].c_r;
		}
	}

	sort(stu, stu+N, cmp_m);
	stu[0].m_r = 1;
	for(int i = 1; i < N; i++){
		if(stu[i].grade_m < stu[i-1].grade_m){
			stu[i].m_r = i+1;
		}else{
			stu[i].m_r = stu[i-1].m_r;
		}
	}

	sort(stu, stu+N, cmp_e);
	stu[0].e_r = 1;
	for(int i = 1; i < N; i++){
		if(stu[i].grade_e < stu[i-1].grade_e){
			stu[i].e_r = i+1;
		}else{
			stu[i].e_r = stu[i-1].e_r;
		}
	}
	
	//choosing best rank
	for(int i = 0; i < N; i++){
		if(stu[i].a_r <= stu[i].c_r && stu[i].a_r <= stu[i].m_r && stu[i].a_r <= stu[i].e_r){
			stu[i].b_r = stu[i].a_r;
			stu[i].b_r_k = 'A';
		}
		else if(stu[i].c_r <= stu[i].m_r && stu[i].c_r <= stu[i].e_r){
			stu[i].b_r = stu[i].c_r;
			stu[i].b_r_k = 'C';
		}
		else if(stu[i].m_r <= stu[i].e_r){
			stu[i].b_r = stu[i].m_r;
			stu[i].b_r_k = 'M';
		}else{
			stu[i].b_r = stu[i].e_r;
			stu[i].b_r_k = 'E';
		}
	}
	
	//output
	for(int i = 0; i<M; i++){
		bool flag = true;
		for(int j = 0; j<N; j++){
			if(strcmp(stu[j].id,c_stu[i].id)==0){
				printf("%d %c\n", stu[j].b_r, stu[j].b_r_k);
				flag = false;
			}
		}
		if(flag){
			printf("N/A\n");
		}
	}
	
	return 0;

}