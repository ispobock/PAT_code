#include <cstdio>

int s[1000010];
const int INF = 0x7fffffff;

int main(){
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &s[i]);
    }
    scanf("%d", &m);
    int temp;
    scanf("%d", &temp);
    int med = (n + m - 1) / 2;
    int i = 0, j = 0;
    int count = 0;
    for(; count < med;){
        if(s[i] < temp){
            i++;
        }
        else if(j < m - 1){
            scanf("%d", &temp);
            j++;
        }
        else if(j == m - 1){
            temp = INF;
        }
        count++;
    }

    s[n] = INF;

    if(s[i] < temp){
        printf("%d\n", s[i]);
    }
    else{
        printf("%d\n", temp);
    }

    return 0;
}
