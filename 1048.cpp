#include <cstdio>

int main(){
	int N, M;
	int HashTable[1010] = {0};
	scanf("%d %d", &N, &M);
	for(int i = 0; i<N; i++){
		int a;
		scanf("%d", &a);
		HashTable[a]++;
	}
	for(int i = 0; i < M; i++){
		if(HashTable[i] && HashTable[M - i]){
			if(i == M - i && HashTable[i] <= 1){
				continue;
			}
			printf("%d %d", i, M-i);
			return 0;
		}
	}
	printf("No Solution\n");
	return 0;
}