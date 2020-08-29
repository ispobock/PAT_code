#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

struct frac{
    ll up, down;
};

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

frac reduction(frac result){
    if(result.down < 0){
        result.up = result.up * (-1);
        result.down = result.down * (-1);
    }
    if(result.up == 0){
        result.down = 1;
    }
    ll g = gcd(abs(result.up), abs(result.down));
    if(g != 1){
        result.up = result.up / g;
        result.down = result.down / g;
    }

    return result;
}

frac add(frac a, frac b){
    frac result;
    result.up = a.up * b.down + a.down * b.up;
    result.down = a.down * b.down;
    return reduction(result);
}

frac minu(frac a, frac b){
    frac result;
    result.up = a.up * b.down - a.down * b.up;
    result.down = a.down * b.down;
    return reduction(result);
}

frac multi(frac a, frac b){
    frac result;
    result.up = a.up * b.up;
    result.down = a.down * b.down;
    return reduction(result);
}

frac divide(frac a, frac b){
    frac result;
    if(b.up == 0){
        result.down = 0;
        return result;
    }
    result.up = a.up * b.down;
    result.down = a.down * b.up;
    return reduction(result);
}

void show(frac result){
    if(result.down == 1){
        if(result.up < 0){
            printf("(%lld)", result.up);
        }
        else{
            printf("%lld", result.up);
        }
    }
    else if(result.down == 0){
        printf("Inf");
    }
    else if(abs(result.up) > abs(result.down)){
        if(result.up < 0){
            printf("(%lld %lld/%lld)", result.up / result.down, abs(result.up) % result.down, result.down);
        }
        else{
            printf("%lld %lld/%lld", result.up / result.down, abs(result.up) % result.down, result.down);
        }
    }
    else{
        if(result.up < 0){
            printf("(%lld/%lld)", result.up, result.down);
        }
        else{
            printf("%lld/%lld", result.up, result.down);
        }
    }
}

int main(){
    frac num1, num2;
    scanf("%lld/%lld %lld/%lld", &num1.up, &num1.down, &num2.up, &num2.down);

    num1 = reduction(num1);
    num2 = reduction(num2);

    char oprator[5] = {'+', '-', '*', '/'};
    for(int i = 0; i < 4; i++){
        show(num1);
        printf(" %c ", oprator[i]);
        show(num2);
        printf(" = ");
        if(i == 0){
            show(add(num1, num2));
        }
        else if(i == 1){
            show(minu(num1, num2));
        }
        else if(i == 2){
            show(multi(num1, num2));
        }
        else{
            show(divide(num1, num2));
        }
        printf("\n");
    }

    return 0;
}