#include <cstdio>

struct frac{
    long long n, d;
};

long long gcd(long long a, long long b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a % b);
    }
}

frac reduction(frac a){
    int x;
    if(a.n < 0){
        x = a.n * (-1);
    }
    else{
        x = a.n;
    }
    long long g = gcd(x, a.d);
    if(g != 1){
        a.n = a.n / g;
        a.d = a.d / g;
    }

    return a;
}

frac add(frac a, frac b){
    frac result;
    result.n = a.n * b.d + a.d * b.n;
    result.d = a.d * b.d;
    result = reduction(result);
    return result;
}

int main(){
    int n;
    scanf("%d", &n);
    frac ans, temp;
    ans.d = 1;
    ans.n = 0;
    for(int i = 0; i < n; i++){
        scanf("%lld/%lld", &temp.n, &temp.d);
        ans = add(ans, temp);
    }

    if(ans.n / ans.d != 0){
        printf("%lld", ans.n / ans.d);
        if(ans.n % ans.d != 0){
            printf(" %lld/%lld", ans.n - (ans.n / ans.d) * ans.d, ans.d);
        }
    }
    else if(ans.n % ans.d != 0){
        printf("%lld/%lld", ans.n - (ans.n / ans.d) * ans.d, ans.d);
    }
    else{
        printf("0");
    }

    return 0;
}