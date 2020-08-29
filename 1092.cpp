#include <cstdio>
#include <cstring>

int main(){
	char str1[1010], str2[1010];
	int HashTable[128] = {0};
	gets(str1);
	gets(str2);

	for(int i = 0; i<strlen(str1); i++){
		HashTable[str1[i]]++;
	}
	bool flag = true;
	for(int i = 0; i<strlen(str2); i++){
		HashTable[str2[i]]--;
		if(HashTable[str2[i]] < 0){
			flag = false;
		}
	}
	if(flag){
		int n = 0;
		for(int i = 0; i<128; i++){
			n += HashTable[i];
		}
		printf("Yes %d\n", n);
	}
	else{
		int m = 0;
		for(int i = 0; i<strlen(str2); i++){
			if(HashTable[str2[i]] < 0){
				m += -HashTable[str2[i]];
				HashTable[str2[i]] = 0;
			}
		}
		printf("No %d\n", m);
	}

	return 0;
}