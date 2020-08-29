#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    string str1, str2;
    cin>>str1>>str2;

    //找到小数点，并将其去除
    string str3 = ".";
    int pos1, pos2;
    pos1 = str1.length();
    pos2 = str2.length();   
    if(str1.find(str3) != string::npos){
        pos1 = str1.find(str3);
        str1.erase(pos1, 1);
    }
    if(str2.find(str3) != string::npos){
        pos2 = str2.find(str3);
        str2.erase(pos2, 1);
    }

    //去除前面多余的0, 并统计0的个数
    string::iterator it1 = str1.begin();
    string::iterator it2 = str2.begin();
    int count1 = 0, count2 = 0;
    while(*it1 == '0'){
        count1++;
        it1++;
    }
    while(*it2 == '0'){
        count2++;
        it2++;
    }
    str1 = str1.substr(count1, str1.size() - count1);
    str2 = str2.substr(count2, str2.size() - count2);

    // 截出有效位（本体）
    string str4, str5, str6 = "0";
    str5 = str2.substr(0, n);
    str4 = str1.substr(0, n);
    if(str4.size() < n){
        for(int i = str4.size(); i < n; i++){
            str4.insert(i, str6);
        }
    }
    if(str5.size() < n){
        for(int i = str5.size(); i < n; i++){
            str5.insert(i, str6);
        }
    }

    //算出次方（指数）
    if(str4 == str5){
        cout<<"YES ";
        cout<<"0."<<str4<<"*10^"<<pos1 - count1;
    }
    else{
        cout<<"NO ";
        cout<<"0."<<str4<<"*10^"<<pos1 - count1;
        cout<<" 0."<<str5<<"*10^"<<pos2 - count2;
    }

    // 可以将重复步骤写到函数中
    return 0;
}