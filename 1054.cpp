#include <cstdio>
#include <map>
using namespace std;

int main(){
    int m, n;
    int temp;
    map<int, int> mp;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &temp);
            if(mp.find(temp) == mp.end()){ //找不到
                mp[temp] = 1;
            }
            else{ //找到
                mp[temp]++;
            }
        }
    }

    int now = 0;
    int dom;
    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
        if(it->second > (m * n) / 2){
            if(it->second > now){
                now = it->second;
                dom = it->first;
            }
        }
    }

    printf("%d", dom);
    return 0;
}