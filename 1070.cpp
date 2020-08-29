#include <cstdio>
#include <algorithm>
using namespace std;

struct mooncake{
	double amm;
	double pri; 
}mc[1010];

bool cmp(mooncake a, mooncake b){
	if(a.pri > b.pri){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	double allprice;
	int	N;
	double demand;
	double profit = 0.0;
	scanf("%d %lf", &N, &demand);
	for(int i = 0; i < N; i++){
		scanf("%lf", &mc[i].amm);
	}
	for(int i = 0; i < N; i++){
		scanf("%lf", &allprice);
		mc[i].pri = allprice / mc[i].amm;
	}
	sort(mc, mc+N, cmp);
	int j = 0;
	while(demand > 0.0 && j < N){  //不加j < N会发生段错误
		if(mc[j].amm <= demand){
			profit += mc[j].amm*mc[j].pri;
			demand -= mc[j].amm;
		}
		else{
			profit += mc[j].pri*demand;
			demand = 0.0;
		}
		j++;
	}
	printf("%.2lf\n", profit);
	return 0;
}