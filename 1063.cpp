#include <cstdio>
#include <set>
using namespace std;

int main(){
    int n, m;
    set<int> st[10010];
    int temp;
    scanf("%d", &n);
    for(int i = 1; i < n + 1; i++){
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            scanf("%d", &temp);
            st[i].insert(temp);
        }
    }

    int k;
    scanf("%d", &k);
    int st1, st2, count = 0;
    for(int i = 0; i < k; i++){
        scanf("%d %d", &st1, &st2);
        for(set<int>::iterator it = st[st1].begin(); it != st[st1].end(); it++){
            if(*st[st2].find(*it) == (*it)){ //还有种判断是否查到的方法：st[st2].find(*it) != st[st2].end()
                count++;
            }
        }
        int size = st[st1].size() + st[st2].size() - count;
        printf("%.1f%%\n", 100.0 * count/size); //如果要输出%，则应输入%%
        count = 0;
    }

    return 0;
}