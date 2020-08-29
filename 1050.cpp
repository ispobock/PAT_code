#include <cstdio>
#include <cstring>

int main(){
	bool HashTable[128] = {false};
	char str1[10010], str2[10010];
	gets(str1);
	gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i = 0; i<len2; i++){
		if(HashTable[str2[i]] == false){
			HashTable[str2[i]] = true;
		}
	}

	for(int i = 0; i<len1; i++){
		if(HashTable[str1[i]] == false){
			printf("%c", str1[i]);
		}
	}
	return 0;
}