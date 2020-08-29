#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

string unit[14] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string ten[14] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

string to_str[170];
map<string, int> to_int;

//打表
void init(){
    for(int i = 0; i < 13; i++){
        to_str[i] = unit[i];
        to_int[unit[i]] = i;
        to_str[i * 13] = ten[i];
        to_int[ten[i]] = i * 13;
    }

    for(int i = 1; i < 13; i++){
        for(int j = 1; j < 13; j++){
            to_str[i * 13 + j] = ten[i] + " " + unit[j];
            to_int[ten[i] + " " + unit[j]] = i * 13 + j;
        }
    }
}


int main(){
    init();
    int N;
    scanf("%d%*c", &N);
    
    for(int i = 0; i < N; i++){
        string str;
        getline(cin, str); //逐行读取
        if(str[0] >= '0' && str[0] <= '9'){
            int ans = 0;
            for(string::iterator it = str.begin(); it != str.end(); it++){
                ans = ans * 10 + (*it - '0');
            }
            cout<<to_str[ans]<<endl;
        }
        else{
            cout<<to_int[str]<<endl;
        }
    }
    return 0;
}