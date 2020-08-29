#include <cstdio>
#include <cmath>

typedef long long LL;

int main(){
    LL n;
    scanf("%lld", &n);
    LL maxn = 0, first = 0;
    for(LL i = 2; i < sqrt(n * 1.0); i++){ //第一个 数只可能小于sqrt(n)
        if(n % i == 0){
            LL j = i, temp = 1;
            temp *= j; //必须要有这个temp，不能单独除。此处temp可能超出int表示范围。
            while(n % temp == 0){
                j++;
                temp *= j;
            }
            if(j - i > maxn){
                maxn = j - i;
                first = i;
            }
        }
    }

    if(maxn == 0){
        first = n;
        maxn = 1;
    }

    printf("%lld\n", maxn);
    for(LL i = first; i < first + maxn; i++){
        printf("%lld", i);
        if(i != first + maxn - 1){
            printf("*");
        }
    }
    return 0;
}