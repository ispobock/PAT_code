#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct record{
	char name[25];
	int time[4];
	char state[10];
}rec[1010];

struct Cus{
	char name[25];
	int mon;
	int online[505][3];
	int offline[505][3];
	int n;
	double charge[505];
	int time[505];
	double total;
}cus[1010];

bool cmp(record a, record b){
	if(strcmp(a.name,b.name) < 0){
		return 1;
	}
	else if(strcmp(a.name,b.name) == 0 && a.time[1]*10000+a.time[2]*100+a.time[3] < b.time[1]*10000+b.time[2]*100+b.time[3]){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	//input
	int rate[24];
	for(int i = 0; i<24; i++){
		scanf("%d", &rate[i]);
	}
	int N;
	scanf("%d", &N);
	for(int i = 0; i<N; i++){
		scanf("%s %d:%d:%d:%d %s", rec[i].name, &rec[i].time[0], &rec[i].time[1], &rec[i].time[2], &rec[i].time[3], rec[i].state);
	}
	
	//sorting
	sort(rec,rec+N,cmp);
	
	//record -> customer
	int j = 0;
	cus[j].n = 0;
	for(int i = 0;i < N-1; i++){
		//online - offline
		if(strcmp(rec[i].name,rec[i+1].name)==0 && strcmp(rec[i].state,"on-line")==0 && strcmp(rec[i+1].state,"off-line")==0){
			if(cus[j].n >= 1){
				if(strcmp(cus[j].name,rec[i].name)!=0){
					j++;
					cus[j].n = 0;
				}
			}
			strcpy(cus[j].name,rec[i].name);
			cus[j].online[cus[j].n][0] = rec[i].time[1];
			cus[j].online[cus[j].n][1] = rec[i].time[2];
			cus[j].online[cus[j].n][2] = rec[i].time[3];
			cus[j].offline[cus[j].n][0] = rec[i+1].time[1];
			cus[j].offline[cus[j].n][1] = rec[i+1].time[2];
			cus[j].offline[cus[j].n][2] = rec[i+1].time[3];
			cus[j].mon = rec[i].time[0];
			cus[j].n++;
		}
	}
	
	//computing time and cost
	for(int i = 0; i<=j; i++){
		for(int k = 0; k < cus[i].n; k++){
			cus[i].time[k] = 0;
			int a = cus[i].online[k][0], b = cus[i].online[k][1], c = cus[i].online[k][2];
			while(a < cus[i].offline[k][0] || b < cus[i].offline[k][1] || c < cus[i].offline[k][2]){
				if(c < 60){
					c++;
					cus[i].charge[k] += (double)rate[b]/100.00;
					cus[i].time[k]++; 
				}else{
					c = 0;
					b++;
				}
				if(b == 24){
					a++;
					b = 0;
				}
			}
			cus[i].total += cus[i].charge[k];
		}
	}

	//output
	for(int i = 0; i<=j; i++){
		printf("%s %02d\n", cus[i].name, cus[i].mon);
		for(int k = 0; k < cus[i].n; k++){
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", cus[i].online[k][0], cus[i].online[k][1], cus[i].online[k][2], cus[i].offline[k][0], cus[i].offline[k][1], cus[i].offline[k][2], cus[i].time[k], cus[i].charge[k]);
		}
		printf("Total amount: $%.2lf\n", cus[i].total);
	}
	
	return 0;
}