#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;

bool cmp(int a, int b){
	return a < b;
}

int main(){
	int NC,NP;
	int coup[maxn], prod[maxn];
	scanf("%d", &NC);
	for(int i = 0; i<NC; i++){
		scanf("%d", &coup[i]);
	}
	scanf("%d", &NP);
	for(int i = 0; i<NP; i++){
		scanf("%d", &prod[i]);
	}
	
	sort(coup, coup+NC, cmp);
	sort(prod, prod+NP, cmp);

	int prof = 0;
	bool hashTable[maxn] = {false};
	int j = 0;
	for(int i = 0; i<NC; i++){
		if(coup[i] <= 0){
			for(; j<NP; j++){
				if(hashTable[j] == false){
					if(coup[i]*prod[j] <= 0){
						break;
					}
					prof += coup[i]*prod[j];
					hashTable[j] = true;
					break;
				}
			}
		}
		else{
			break;
		}
	}
	j = NP-1;
	for(int i = NC-1; i>=0; i--){
		if(coup[i] > 0){
			for(; j>=0; j--){
				if(hashTable[j] == false){
					if(coup[i]*prod[j] <= 0){
						break;
					}
					prof += coup[i]*prod[j];
					hashTable[j] = true;
					break;
				}
			}
		}
		else{
			break;
		}
	}
	printf("%d\n", prof);

	return 0;
}