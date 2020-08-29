#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int to_int(char s[]){
    int stu = 0;
    for(int i = 0; i < 3; i++){
        stu = stu*26 + s[i] - 'A';
    }
    stu = stu * 10 + s[3] - '0';
    return stu;
}

vector<int> hashtable[26*26*26*10+10];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++){
        int id, x;
        scanf("%d %d", &id, &x);
        for(int j = 0; j < x; j++){
            char name[5];
            scanf("%s", name);
            int stu = to_int(name);
            hashtable[stu].push_back(id);
        }
    }

    for(int i = 0; i < n; i++){
        char name1[5];
        scanf("%s", name1);
        int stu1 = to_int(name1);
        sort(hashtable[stu1].begin(), hashtable[stu1].end());
        printf("%s %d", name1, hashtable[stu1].size());
        vector<int>::iterator it;
        for(it = hashtable[stu1].begin(); it != hashtable[stu1].end(); it++){
            printf(" %d", *it);
        }
        printf("\n");
    }

    return 0;
}