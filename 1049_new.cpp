#include <cstdio>

int main(){
    long long a;
    scanf("%lld", &a);
    long long ans = 0;
    long long i = 10;
    while((a * 10 / i) != 0){
        if(((a % i)*10 / i) > 1){
            ans += (a / i + 1) * (i / 10);
        }
        else if(((a % i)*10 / i) < 1){
            ans += (a / i) * (i / 10);
        }
        else{
            //ans += (a / i + 1) * (a % (i / 10) + 1);
            ans += (a / i) * (i / 10) + a % (i / 10) + 1;
        }

        i *= 10;
    }

    printf("%lld\n", ans);

    return 0;
}