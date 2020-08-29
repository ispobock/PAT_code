#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <queue>
using namespace std;

struct node{
    double num; //操作数
    char op;  //操作符
    bool flag;  //true表操作数，false表操作符
};

string str;
stack<node> s;
queue<node> q;
map<char, int> op;

//中缀表达式转后缀表达式
void change(){
    double num;
    node temp;
    for(int i = 0; i < str.length();){
        if(str[i] >= '0' && str[i] <= '9'){
            temp.flag = true;
            temp.num = str[i] - '0';
            i++;
            while(str[i] >= '0' && str[i] <= '9' && i < str.length()){
                temp.num = temp.num * 10 + str[i] - '0';
                i++;
            }
            q.push(temp);
        }
        else if(str[i] == '('){
            temp.flag = false;
            temp.op = str[i];
            s.push(temp);
            i++;
        }
        else if(str[i] == ')'){  // 把两个括号之间的操作符全部移入队列
            while(s.top().op != '('){
                q.push(s.top());
                s.pop();
            }
            s.pop();
            i++;
        }
        else{
            temp.flag = false;
            while(!s.empty() && op[str[i]] <= op[s.top().op]){
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i++;
        }
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

double calculate(){
    double temp1, temp2;
    node cur, temp;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(cur.flag == true){
            s.push(cur);
        }
        else{
            temp2 = s.top().num;
            s.pop();
            temp1 = s.top().num;
            s.pop();
            temp.flag = true;
            switch(cur.op){
                case '+':
                temp.num = temp1 + temp2;
                break;
                case '-':
                temp.num = temp1 - temp2;
                break;
                case '*':
                temp.num = temp1 * temp2;
                break;
                case '/':
                temp.num = temp1 / temp2;
                break;
            }
            s.push(temp);
        }
    }
    return s.top().num;
}

int main(){
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    op['('] = 0;
    while(getline(cin, str), str != "0"){ //逗号表达式，从左往右执行，最后一个表达式的值决定真假
        for(string::iterator it = str.begin(); it != str.end(); it++){
            if(*it == ' '){
                str.erase(it);
            }
        }
        while(!s.empty()){
            s.pop();
        }
        change();
        printf("%.2f\n", calculate());
    }
    return 0;
}

