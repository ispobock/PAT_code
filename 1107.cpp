#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int father[1010];
map<int, int> mp;

int find_father(int x){
    while(x != father[x]){
        x = father[x];
    }
    return x;
}

void Union(vector<int> vi){
    int fa = find_father(vi[0]);
    for(int i = 0; i < vi.size(); i++){
        int fi = find_father(vi[i]);
        if(fa != fi){
            father[fi] = fa;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= 1000; i++){
        father[i] = i;
    }
    vector<int> vi[1010];
    for(int i = 0; i < n; i++){
        int k;
        scanf("%d:", &k);
        for(int j = 0; j < k; j++){
            int temp;
            scanf("%d", &temp);
            vi[i].push_back(temp);
        }
        Union(vi[i]);
    }
    for(int i = 0; i < n; i++){
        int fa = find_father(vi[i][0]);
        if(mp.find(fa) != mp.end()){
            mp[fa]++;
        }
        else{
            mp[fa] = 1;
        }
    }
    printf("%d\n", mp.size());
    int count = 0;
    vector<int> num;
    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
        num.push_back(it->second);
    }
    sort(num.begin(), num.end());
    for(int i = num.size() - 1; i >= 0; i--){
        printf("%d", num[i]);
        count++;
        if(count < mp.size()){
            printf(" ");
        }
    }

    return 0;
}