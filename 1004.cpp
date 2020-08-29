#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct node{
    int level;
    vector<int> child;
}Node[105];

int n, m;
int count[105] = {0};
int maxlevel = 0;
void BFS(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        if(Node[top].level > maxlevel){
            maxlevel = Node[top].level;
        }
        if(Node[top].child.size() == 0){
            count[Node[top].level]++;
        }
        else{
            for(int i = 0; i < Node[top].child.size(); i++){
                Node[Node[top].child[i]].level = Node[top].level + 1;
                q.push(Node[top].child[i]);
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int id, k;
        scanf("%d %d", &id, &k);
        for(int j = 0; j < k; j++){
            int temp;
            scanf("%d", &temp);
            Node[id].child.push_back(temp);
        }
    }
    Node[1].level = 1;
    BFS(1);
    for(int i = 1; i <= maxlevel; i++){
        printf("%d", count[i]);
        if(i != maxlevel){
            printf(" ");
        }
    }

    return 0;
}