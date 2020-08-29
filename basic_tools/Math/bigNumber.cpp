#include <cstdio>
#include <cstring>

struct bign{
    int d[1000];
    int len;
    bign(){
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign to_bign(char n[]){
    bign a;
    a.len = strlen(n);
    for(int i = 0; i < a.len; i++){
        a.d[i] = n[a.len - 1 - i] - '0';
    }
    return a;
}

bign add(bign a, bign b){
    bign c;
    int carry = 0;
    int temp;
    for(int i = 0; i < a.len || i < b.len; i++){
        temp = a.d[i] + b.d[i] + carry;
        c.d[i] = temp % 10;
        carry = temp / 10;
        c.len++;
    }
    if(carry != 0){
        c.d[c.len++] = carry;
    }
    return c;
}

bign minu(bign a, bign b){
    bign c;
    for(int i = 0; i < a.len || i < b.len; i++){
        if(a.d[i] < b.d[i]){
            a.d[i + 1]--;
            a.d[i] += 10;
        }
        c.d[i] = a.d[i] - b.d[i];
        c.len++;
    }
    if(c.len > 1 && c.d[c.len - 1] == 0){
        c.len--;
    }
    return c;
}

bign multi(bign a, int b){
    bign c;
    int carry = 0, temp;
    for(int i = 0; i < a.len; i++){
        temp = a.d[i] * b + carry;
        c.d[i] = temp % 10;
        carry = temp / 10;
        c.len++;
    }
    if(carry > 0){
        while(carry != 0){
            c.d[c.len++] = carry % 10;
            carry /= 10;
        }
    }
    return c;
}

bign divide(bign a, int b, int &r){
    r = 0;
    bign c;
    c.len = a.len;
    for(int i = a.len - 1; i >= 0; i--){
        r = r * 10 + a.d[i];
        if(r < b){
            c.d[i] = 0;
        }
        else{
            c.d[i] = r / b;
            r %= b;
        }
    }
    while(c.len > 1 && c.d[c.len - 1] == 0){
        c.len--;
    }
    return c;
}

void print_bign(bign a){
    for(int i = a.len - 1; i >= 0; i--){
        printf("%d", a.d[i]);
    }
    printf("\n");
}


int main(){
    char n1[1000], n2[1000];
    scanf("%s %s", n1, n2);
    bign a = to_bign(n1);
    bign b = to_bign(n2);
    bign c = add(a, b);
    bign d = minu(a, b);
    bign e = multi(a, 100);
    int r = 0;
    bign f = divide(a, 100, r);
    print_bign(c);
    print_bign(d);
    print_bign(e);
    print_bign(f);
    printf("%d", r);
    
    return 0;
}