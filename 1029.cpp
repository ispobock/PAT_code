#include <cstdio>

int s1[1000010], s2[1000010];
const int INF = 0x7fffffff;

int main(){
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &s1[i]);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &s2[i]);
    }

    s1[n] = s2[m] = INF;
    long long med = (n + m - 1) / 2;
    int i = 0, j = 0;
    long long count = 0;
    while(count < med){
        if(s1[i] < s2[j]){
            i++;
        }
        else{
            j++;
        }
        count++;
    }

    if(s1[i] < s2[j]){
        printf("%d\n", s1[i]);
    }
    else{
        printf("%d\n", s2[j]);
    }

    return 0;
}
