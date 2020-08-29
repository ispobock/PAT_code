#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int hashTable[100010] = {0};

int gbc(int a, int b){
	if(b == 0){
		return a;
	}
	return gbc(b, a % b);
}

bool isprime(int x){
	for(int i = 1; i <= (int)sqrt(x); i++){
		if(gbc(x, i) != 1){
			return false;
		}
	}
	return true;
}


int main(){
	int ms, n, m;
	scanf("%d %d %d", &ms, &n, &m);
	while(!isprime(ms)){
		ms++;
	}
	for(int i = 0; i < n; i++){
		int key;
		scanf("%d", &key);
		int h;
		for(int j = 0; j < ms; j++){
			h = (key + j * j) % ms;
			if(hashTable[h] == 0){
				hashTable[h] = key;
				break;
			}
			if(j == ms - 1){
				printf("%d cannot be inserted.\n", key);
			}
		}
	}

	double ans = 0.0;
	for(int i = 0; i < m; i++){
		int q;
		scanf("%d", &q);
		int j = 0, hq;
		for(; j <= ms; j++){
			ans++;
			hq = (q + j * j) % ms;
			if(hashTable[hq] == q || hashTable[hq] == 0){
				break;
			}
		}
	}
	printf("%.1lf\n", ans / (1.0 * m));

	return 0;
}