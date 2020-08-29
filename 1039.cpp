#include <cstdio>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

//由于数据量太大，此解法太慢，无法通过最后一个测试点
//通过构建学生姓名的Hash表可以大大加快查询速度，即以空间换时间
struct course{
    set<string> stu;
}cou[2505];


int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 0; i < k; i++){
        int num, id;
        scanf("%d %d", &id, &num);
        for(int j = 0; j < num; j++){
            string temp;
            cin>>temp;
            cou[id].stu.insert(temp);
        }
    }

    bool hashtable[2500] = {false};
    int count = 0;
    for(int i = 0; i < n; i++){
        string name;
        cin>>name;
        for(int j = 1; j < k + 1; j++){
            if(*(cou[j].stu.find(name)) == name){
                hashtable[j] = true;
                count++;
            }
        }
        printf("%s %d", name.c_str(), count);
        for(int j = 1; j < k + 1; j++){
            if(hashtable[j] == true){
                printf(" %d", j);
            }
        }

        printf("\n");
        count = 0;
        fill(hashtable + 1, hashtable + k + 1, false);
    }

    return 0;
}