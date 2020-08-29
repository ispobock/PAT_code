#include <cstdio>
#include <cmath>
const int maxn = 100;
bool hashTable[maxn] = {false};
int P[maxn], n, count = 0;

void generateP(int index){
	if(index == n + 1){
		for(int i = 1; i <= n; i++){
			printf("%d", P[i]);
		}
		printf("\n");
		count++;
		return;
	}

	for(int i = 1; i <= n; i++){
		if(hashTable[i] == false){
			bool flag = true;
			for(int j = 1; j < index; j++){
				if(abs(j - index) == abs(P[j] - i)){
					flag = false;
					break;
				}
			}
			if(flag){
				P[index] = i;
				hashTable[i] = true;
				generateP(index + 1);
				hashTable[i] = false;
			}
		}
	}
}

int main(){
	n = 6;
	generateP(1);
	printf("%d\n", count);
	return 0;
}