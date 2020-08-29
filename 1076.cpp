#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int MAXV = 1010;

struct node{
    int id;
    int layer;
};

vector<node> adj[MAXV];
bool inq[MAXV] = {false};
int n, l;
int num[MAXV] = {0};

void BFS(int u){
    queue<node> q;
    node start;
    start.id = u;
    start.layer = 0;
    q.push(start);
    inq[u] = true;
    while(!q.empty()){
        node top = q.front();
        q.pop();
        if(top.layer >= 1 && top.layer < l + 1){
            num[u]++;
        }
        for(int i = 0; i < adj[top.id].size(); i++){
            node next = adj[top.id][i];
            if(inq[next.id] == false){
                next.layer = top.layer + 1;
                q.push(next);
                inq[next.id] = true;
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &l);
    int m, temp_id;
    node temp;
    for(int i = 1; i <= n; i++){
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            scanf("%d", &temp_id);
            temp.id = i;
            adj[temp_id].push_back(temp);
        }
    }
    int k, query;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d", &query);
        BFS(query);
        // for(int j = 1; j <= n; j++){
        //     inq[j] = false;
        // }
        memset(inq, false, sizeof(inq));
        printf("%d\n", num[query]);
    }

    return 0;
}