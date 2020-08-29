#include <cstdio>

int count(long long a){
    int num = 0;
    while(a != 0){
        if(a % 10 == 1){
            num++;
        }
        a /= 10;
    }
    return num;
}

int main(){
    long long n;
    scanf("%lld", &n);

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += count(i);
    }

    printf("%d\n", ans);
    return 0;
}