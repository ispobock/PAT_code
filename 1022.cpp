#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

struct book{
    string title;
    string author;
    string kewords;
    string publisher;
    string year;
};

map<string, book> mp;

int main(){
    int n;
    scanf("%d%*c", &n);
    string id, tit, au, key, pub, y;
    for(int i = 0; i < n; i++){
        getline(cin, id);
        getline(cin, tit);
        getline(cin, au);
        getline(cin, key);
        getline(cin, pub);
        getline(cin, y);
        mp[id].title = tit;
        mp[id].author = au;
        mp[id].kewords = key;
        mp[id].publisher = pub;
        mp[id].year = y;
    }

    int m;
    scanf("%d%*c", &m);
    string query;
    for(int i = 0; i < m; i++){
        bool flag = false;
        getline(cin, query);
        cout<<query<<endl;
        if(query[0] == '1'){
            query = query.substr(3, query.length() - 3);
            for(map<string, book>::iterator it = mp.begin(); it != mp.end(); it++){
                if(query == it->second.title){
                    cout<<it->first<<endl;
                    flag = true;
                }
            }
            if(!flag){
                cout<<"Not Found"<<endl;
            }
        }
        else if(query[0] == '2'){
            query = query.substr(3, query.length() - 3);
            for(map<string, book>::iterator it = mp.begin(); it != mp.end(); it++){
                if(query == it->second.author){
                    cout<<it->first<<endl;
                    flag = true;
                }
            }
            if(!flag){
                cout<<"Not Found"<<endl;
            }
        }
        else if(query[0] == '3'){
            query = query.substr(3, query.length() - 3);
            for(map<string, book>::iterator it = mp.begin(); it != mp.end(); it++){
                if(it->second.kewords.find(query) != string::npos){
                    cout<<it->first<<endl;
                    flag = true;
                }
            }
            if(!flag){
                cout<<"Not Found"<<endl;
            }
        }
        else if(query[0] == '4'){
            query = query.substr(3, query.length() - 3);
            for(map<string, book>::iterator it = mp.begin(); it != mp.end(); it++){
                if(it->second.publisher == query){
                    cout<<it->first<<endl;
                    flag = true;
                }
            }
            if(!flag){
                cout<<"Not Found"<<endl;
            }
        }
        else if(query[0] == '5'){
            query = query.substr(3, query.length() - 3);
            for(map<string, book>::iterator it = mp.begin(); it != mp.end(); it++){
                if(it->second.year == query){
                    cout<<it->first<<endl;
                    flag = true;
                }
            }
            if(!flag){
                cout<<"Not Found"<<endl;
            }
        }
        else{
            cout<<"Not Found"<<endl;
        }
    }

    return 0;
}