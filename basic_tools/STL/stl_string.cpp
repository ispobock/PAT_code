#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
    string str1;
    string str2 = "abcdefg";
    // cin cout
    cin>>str1;
    for(int i = 0; i < str1.size(); i++){
        printf("%c", str1[i]);
    }
    cout<<'\n'<<str1<<endl;

    // string::iterator
    for(string::iterator it = str2.begin(); it != str2.end(); it++){
        printf("%c", *it);
    }
    cout<<endl;
    
    // + =
    string str3;
    str3 = str1 + str2;
    printf("%s\n", str3.c_str());

    // insert( , , )
    str2.insert(str2.begin() + 2, str1.begin(), str1.end());
    cout<<str2<<endl;

    // 只有substr(pos, len)
    cout<<str2.substr(3, 5)<<endl;

    // str2.find(str1), 当str1是str2的字串时，返回其在str2中第一次出现的位置
    // string::npos = -1 or 2^32 - 1
    if(str2.find(str1) != string::npos){
        cout<<str2.find(str1)<<endl;
    }
    
    // str1(it1, it2, str2), 将str1中it1到it2的部分替换为str2
    cout<<str1.replace(str1.begin() + 2, str1.end(), str2)<<endl;

    return 0;
}