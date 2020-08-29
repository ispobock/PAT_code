#include <cstdio>

const int maxn = 100010;

void swap(int &a, int &b){ //algorithm包里就有swap函数
	int c = a;
	a = b;
	b = c;
}

int main(){
	int N;
	scanf("%d", &N);
	int per[maxn], posi[maxn];
	for(int i = 0; i<N; i++){
		scanf("%d", &per[i]);
		posi[per[i]] = i;
	}
	
	int k = -1, j = -1, n = 0;
	int left = 0;
	bool flag = true;
	while(flag){
		k = posi[0];
		j = posi[k];
		while(k != 0){
			swap(per[k], per[j]);
			swap(posi[per[k]],posi[per[j]]);
			n++;
			k = j;
			j = posi[k];
		}

		for(; left < N; left++){  //不用再从头枚举了，否则超时
			if(per[left] != left){
				swap(per[0], per[left]);
				swap(posi[per[0]],posi[per[left]]);
				n++;
				break;
			}
			if(left == N-1){
				flag = false;
			}
		}
	}
	
	printf("%d\n", n);

	return 0;
}