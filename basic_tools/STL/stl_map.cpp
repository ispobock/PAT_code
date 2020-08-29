#include <cstdio>
#include <map>
using namespace std;

int main(){
    // <key_type, value_type>
    map<string, int> mp;
    mp["abs"] = 2;
    mp["ip"] = 210;
    mp["bp"] = 15;
    // 迭代器访问，也可以下标访问，如printf("%d", mp["abs"]);
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++){
        printf("%s %d\n", it->first.c_str(), it->second);
    }

    // find返回迭代器
    printf("%d\n", mp.find("abs")->second);

    // find找不到返回值为end()

    mp.erase("abs");
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++){
        printf("%s %d\n", it->first.c_str(), it->second);
    }

    // 返回键值对数量
    printf("%d", mp.size());


    return 0;
}

bool isPrime(int n){
    if(n <= 1) return false;
    for(int i = 2; i <= sqrt(1.0 * n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}