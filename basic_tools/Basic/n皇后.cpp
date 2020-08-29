#include <cstdio>
const int maxn = 11;
//P为当前排列,hashTable记录整数x是否在P中
int n, P[maxn], hashTable[maxn] = {false};

int count  = 0;
//暴力法判断合法方案
void generateP(int index){
	if(index == n+1){
		bool flag = true;
		for(int i = 1; i <= n; i++){  //遍历任意两个皇后
			for(int j = i+1; j <= n; j++){
				if(abs(i-j) == abs(P[i] - P[j])){ //如果在一条对角线上
					flag = false; //不合法
				}
			}
		}
		if(flag) count++;
		return;
	}
	for(int x = 1; x <= n; x++){
		if(hashTable[x] == false){
			P[index] = x;
			hashTable[x] = true;
			generateP(index + 1);
			hashTable[x] = false;
		}
	}
}

//回溯法
void generateP1(int index){
	if(index == n + 1){
		count++;
		return;
	}
	for(int x = 1; x <= n; x++){
		if(hashTable[x] == false){ //第x行还没有皇后
			bool flag = true;
			for(int pre = 1; pre < index; pre++){  //遍历之前的皇后
				if(abs(index - pre) == abs(x - P[pre])){
					flag = false;
					break;
				}
			}
			if(flag){
				P[index] = x;
				hashTable[x] = true;
				generateP1(index + 1);
				hashTable[x] = false;
			}
		}
	}
}
