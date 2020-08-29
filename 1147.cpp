#include <cstdio>
using namespace std;
int n, m;

int h[1010];

int cnt = 0;
void postorder(int root){
	if(root > m){
		return;
	}
	postorder(root * 2);
	postorder(root * 2 + 1);
	printf("%d", h[root]);
	cnt++;
	if(cnt < m){
		printf(" ");
	}
	else{
		printf("\n");
	}
}

int main(){
	
	scanf("%d %d", &n, &m);
	for(int j = 0; j < n; j++){
		for(int i = 1; i <= m; i++){
			scanf("%d", &h[i]);
		}
		bool ismax = true, ismin = true;
		for(int i = 1; 2 * i <= m; i++){
			if(2 * i + 1 <= m){
				if(h[i] < h[2 * i] || h[i] < h[2 * i + 1]){
					ismax = false;
				}
				if(h[i] > h[2 * i] || h[i] > h[2 * i + 1]){
					ismin = false;
				}
			}
			if(2 * i + 1 > m){
				if(h[i] < h[2 * i]){
					ismax = false;
				}
				if(h[i] > h[2 * i]){
					ismin = false;
				}
			}
		}

		if(ismax){
			printf("Max Heap\n");
		}
		else if(ismin){
			printf("Min Heap\n");
		}
		else{
			printf("Not Heap\n");
		}
		postorder(1);
		cnt = 0;
	}
	
	return 0;
}