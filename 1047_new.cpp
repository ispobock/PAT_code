#include <cstdio>
#include <set>
#include <string>
#include <iostream>
using namespace std;

/*
int to_int(char s[]){
    int ans = 0;
    for(int i = 0; i < 3; i++){
        ans = ans * 26 + s[i] - 'A';
    }
    ans = ans * 10 + s[3] - '0';
    return ans;
}

void to_str(int ans, char s[]){
    s[3] = (char)(ans % 10 + '0');
    ans /= 10;
    for(int i = 2; i >= 0; i--){
        s[i] = (char)(ans % 26 + 'A'); 
        ans /= 26;
    }
}
*/

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    set<string> course[2510];
    int num, id;
    for(int i = 0; i < n; i++){
        string name;
        cin>>name;
        scanf("%d", &num);
        for(int i = 0; i < num; i++){
            scanf("%d", &id);
            course[id].insert(name);
        }
    }

    for(int i = 1; i < k + 1; i++){
        printf("%d %d\n", i, course[i].size());
        set<string>::iterator it;
        for(it = course[i].begin(); it != course[i].end(); it++){
            printf("%s\n", (*it).c_str());
        }
    }

    return 0;
}