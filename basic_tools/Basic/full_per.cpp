#include <cstdio>

const int maxn = 100;
bool hashTable[maxn] = {false};
int P[maxn], n;

void generateP(int index){
	if(index == n + 1){
		for(int i = 1; i <= n; i++){
			printf("%d", P[i]);
		}
		printf("\n");
		return;
	}

	for(int i = 1; i <= n; i++){
		if(hashTable[i] == false){
			P[index] = i;
			hashTable[i] = true;
			generateP(index + 1);
			hashTable[i] = false;
		}
	}
}

int main(){
	n = 2;
	generateP(1);
	return 0;
}