#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct Rec{
	char id[10];
	int hh,mm,ss;
	bool sta;
	int time;
}rec[10010];

bool cmp(Rec a, Rec b){
	if(strcmp(a.id, b.id) < 0){
		return 1;
	}
	else if(strcmp(a.id, b.id) == 0 && a.hh*10000+a.mm*100+a.ss < b.hh*10000+b.mm*100+b.ss){
		return 1;
	}
	else{
		return 0;
	}
}

int cptime(int h1, int m1, int s1, int h2, int m2, int s2){
	return (s2+m2*60+h2*3600) - (s1+m1*60+h1*3600);
}

int main_1(){
	int N, K;
	char status[5];
	scanf("%d %d", &N, &K);
	for(int i = 0; i<N; i++){
		scanf("%s %d:%d:%d", rec[i].id, &rec[i].hh, &rec[i].mm, &rec[i].ss);
		scanf("%s", status);
		if(strcmp(status,"in") == 0){
			rec[i].sta = true;
		}
		else{
			rec[i].sta = false;
		}
	}
	
	sort(rec, rec+N, cmp);

	for(int i = 0; i<K; i++){
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		int n = 0;
		for(int j = 0; j<N-1; j++){
			if(strcmp(rec[j].id, rec[j].id) == 0 && rec[j].sta == true && rec[j+1].sta == false){
				if(rec[j].hh*10000 + rec[j].mm*100 + rec[j].ss <= h*10000 + m*100 + s && rec[j+1].hh*10000 + rec[j+1].mm*100 + rec[j+1].ss > h*10000 + m*100 + s){
					n++;
				}
			}
		}
		printf("%d\n", n);
	}
	
	int longest = 0;
	for(int i = 0; i<N-1; i++){
		if(strcmp(rec[i].id, rec[i].id) == 0 && rec[i].sta == true && rec[i+1].sta == false){
			if(cptime(rec[i].hh, rec[i].mm, rec[i].ss, rec[i+1].hh, rec[i+1].mm, rec[i+1].ss) > longest){
				longest = cptime(rec[i].hh, rec[i].mm, rec[i].ss, rec[i+1].hh, rec[i+1].mm, rec[i+1].ss);
			}
		}
	}
	
	for(int i = 0; i<N-1; i++){
		if(strcmp(rec[i].id, rec[i].id) == 0 && rec[i].sta == true && rec[i+1].sta == false){
			if(cptime(rec[i].hh, rec[i].mm, rec[i].ss, rec[i+1].hh, rec[i+1].mm, rec[i+1].ss) == longest){
				printf("%s ", rec[i].id);
			}
		}
	}

	printf("%02d:%02d:%02d\n", longest/3600, (longest/60)%60, longest%60);


	return 0;
}