#include <cstdio>
#include <cmath>

bool isPrime(int n){
    if(n <= 1) return false;
    for(int i = 2; i <= sqrt(1.0 * n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

struct factor{
    int x, count;
}fac[10];

int main(){
    int a, n, num = 0;
    scanf("%d", &a);
    n = a;
    for(int i = 2; i <= sqrt(1.0 * n); i++){
        if(isPrime(i)){ //对每个数进行判断是否为质数
            if(n % i == 0){  //若是，则判断是否为质因子
                fac[num].x = i;
                fac[num].count = 1;
                n /= i;
                while(n % i == 0){  //求出该质因子的个数
                    fac[num].count++;
                    n /= i;
                }
                num++;
            }
        }
        else{
            continue;
        }
    }

    if(n > 1){  //根据定理，大于sqrt(n)的质因子至多只有一个
        fac[num].x = n;
        fac[num].count = 1;
        num++;
    }

    for(int i = 0; i < num; i++){
        if(i == 0){
            printf("%d=", a);
        }
        if(fac[i].count > 1){
            printf("%d^%d", fac[i].x, fac[i].count);
        }
        else{
            printf("%d", fac[i].x);
        }
        if(i != num - 1){
            printf("*");
        }
    }

    if(a == 1){  //处理特殊情况
        printf("1=1");
    }

    return 0;
}