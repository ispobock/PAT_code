#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring> //string函数
#include <string> //用到string数据类型需要引入此包

using namespace std;

struct Rec{
	char id[10];
	int time;
	bool sta;
}rec[10010], valid[10010];

int trans_time(int hh, int mm, int ss){
	return hh*3600 + mm*60 +ss;
}

bool cmpById(Rec a, Rec b){
	if(strcmp(a.id, b.id)){
		return strcmp(a.id, b.id) < 0;
	}
	else if(a.time < b.time){
		return 1;
	}
	else{
		return 0;
	}
}

bool cmpByTime(Rec a, Rec b){
	return a.time < b.time;
}

map<string, int> mp;

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	int hh, mm, ss;
	char status[6];
	for(int i = 0; i < N; i++){
		scanf("%s %d:%d:%d", rec[i].id, &hh, &mm, &ss);
		rec[i].time = trans_time(hh, mm, ss);
		scanf("%s", status);
		if(strcmp(status, "in") == 0){
			rec[i].sta = true;
		}
		else{
			rec[i].sta = false;
		}
	}

	sort(rec, rec+N, cmpById);
	
	//将有效记录提出，并计算每辆车的停留时间
	int num = 0;
	int longest = -1;
	for(int i = 0; i<N-1; i++){
		if(strcmp(rec[i].id, rec[i+1].id) == 0 && rec[i].sta == true && rec[i+1].sta == false){
			valid[num++] = rec[i];
			valid[num++] = rec[i+1];
			//统计该车牌在映射中有无记录
			if(mp.count(rec[i].id) == 0){
				//注意是[]
				mp[rec[i].id] = 0;
			}
			//时间累加
			mp[rec[i].id] += rec[i+1].time - rec[i].time;
			longest = max(longest, mp[rec[i].id]);
		}
	}

	sort(valid, valid+num, cmpByTime);

	int cars = 0;
	int time;
	int j = 0;
	for(int i = 0; i<K; i++){
		scanf("%d:%d:%d", &hh, &mm, &ss);
		time = trans_time(hh, mm, ss);
		while(valid[j].time <= time && j < num){ 
			//j < num不加会有段错误
			if(valid[j].sta == true){
				cars ++;
			}
			else{
				cars --;
			}
			j++;
		}
		printf("%d\n", cars);
	}

	for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++){
		if(it->second == longest){
			printf("%s ", it->first.c_str());
		}
	}

	printf("%02d:%02d:%02d\n", longest/3600, (longest/60)%60, longest%60);

	return 0;
}