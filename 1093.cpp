#include <cstdio>
#include <cstring>

int main(){
    char str[100010];
    scanf("%s", str);
    int len = strlen(str);
    int leftPNum[100010];
    int rightTNum[100010];
    for(int i = 0; i < len; i++){
        if(i == 0){
            leftPNum[i] = 0;
        }
        else{
            leftPNum[i] = leftPNum[i - 1];
        }
        if(str[i] == 'P'){
            leftPNum[i]++;
        }
    }
    int ans = 0;
    for(int i = len - 1; i >= 0; i--){
        if(i == len - 1){
            rightTNum[i] = 0;
        }
        else{
            rightTNum[i] = rightTNum[i + 1];
        }
        if(str[i] == 'T'){
            rightTNum[i]++;
        }
        if(str[i] == 'A'){
            ans = (ans + leftPNum[i] * rightTNum[i]) % 1000000007;
        }
    }

    printf("%d\n", ans);
    return 0;
}