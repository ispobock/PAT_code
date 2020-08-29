#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
string trans(string a){
    string b;
    for(string::iterator it = a.begin(); it != a.end(); it++){
        if(*it >= 'A' && *it <= 'Z'){
            *it = (*it - 'A') + 'a';
            b += *it;
        }
        else if((*it >= '0' && *it <= '9') || (*it >= 'a' && *it <= 'z')){
            b += *it;
        }
        else{
            continue;
        }
    }

    return b;
}
*/

bool isalnu(char a){
    if(a >= 'A' && a <= 'Z'){
        return true;
    }
    else if(a >= 'a' && a <= 'z'){
        return true;
    }
    else if(a >= '0' && a <= '9'){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string str;
    map<string, int> mp;
    getline(cin, str);
    int i = 0;
    while(i < str.length()){
        string word;
        while(isalnu(str[i]) && i < str.length()){
            if(str[i] >= 'A' && str[i] <= 'Z'){
                word += str[i] - 'A' + 'a';
            }
            else{
                word += str[i];
            }
            i++;
        }
        if(mp.find(word) != mp.end()){
            mp[word]++;
        }
        else{
            mp[word] = 1;
        }
        while(!isalnu(str[i]) && i < str.length()){
            i++;
        }
    }
    /*
    while(cin.peek() != '\n'){
        cin>>str;
        if(str[0] == '\n'){
            break;
        }
        str = trans(str);
        if(str.empty()){
            continue;
        }
        if(mp.find(str) != mp.end()){
            mp[str]++;
        }
        else{
            mp[str] = 1;
        }
    }
    */

    int max = 0;
    string now;
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++){
        if(it->second > max){
            max = it->second;
            now = it->first;
        }
    }

    cout<<now<<" "<<max;

    return 0;
}