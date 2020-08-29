#include <cstdio>

const int maxn = 11;
int n, P[maxn], HashTable[maxn] = {false};

void generateP(int index){
	if(index == n+1){
		for(int i = 1; i<=n; i++){
			printf("%d", P[i]);
		}
		printf("\n");
		return;
	}

	for(int x = 1; x<=n; x++){
		if(HashTable[x] == false){
			P[index] = x;
			HashTable[x] = true;
			generateP(index + 1);
			HashTable[x] = false;
		}
	}
}

int main(){
	n = 3;
	generateP(1);
	return 0;
}