#include <iostream>
#include <map>
#include <utility>
#include <string>
using namespace std;

int main(){
    map<string, int> mp;

    // 可作为map的键值对插入
    mp.insert(make_pair<string, int>("haha", 1));
    mp.insert(pair<string, int>("heihei", 2));

    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    return 0;
}