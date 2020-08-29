#include <cstdio>
#include <cmath>

int gcd(int a, int b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a % b);
    }
}

struct Fraction{
    int up, down;
};

//化简
Fraction reduction(Fraction result){
    if(result.down < 0){
        result.up = -result.up;
        result.down = -result.down;
    }
    if(result.up == 0){
        result.down = 1;
    }else{
        int d = gcd(abs(result.up), abs(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;
}

//加法
Fraction add(Fraction f1, Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

//减法
Fraction minu(Fraction f1, Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

//乘法
Fraction multi(Fraction f1, Fraction f2){
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}

//除法
Fraction divide(Fraction f1, Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}

//输出
void showResult(Fraction r){
    r = reduction(r);
    if(r.down == 1){
        printf("%lld", r.up);
    }
    else if(abs(r.up) > r.down){
        //假分数
        printf("%d %d/%d", r.up / r.down, abs(r.up) % r.down, r.down);
    }
    else{
        //真分数
        printf("%d/%d", r.up, r.down);
    }
}

int main(){
    Fraction f1, f2;
    scanf("%d %d %d %d", &f1.up, &f1.down, &f2.up, &f2.down);
    Fraction r = minu(f1, f2);
    showResult(r);

    return 0;
}