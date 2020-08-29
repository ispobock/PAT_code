#include <cstdio>
#include <cstring>

int main(){
	char str1[100],str2[100];
	bool HashTable[128] = {false};
	scanf("%s", str1);
	scanf("%s", str2);
	
	for(int i = 0; i<strlen(str1); i++){
		char c1, c2;
		int j;
		c1 = str1[i];
		if(c1 >= 'a' && c1 <= 'z'){
			c1 -= 32;
		}
		for(j = 0; j<strlen(str2); j++){
			c2 = str2[j];
			if(c2 >= 'a' && c2 <= 'z'){
				c2 -= 32;
			}
			if(c1 == c2){
				break;
			}
		}
		if(j == strlen(str2) && HashTable[c1] == false){
			printf("%c", c1);
			HashTable[c1] = true;
		}
	}

	return 0;
}