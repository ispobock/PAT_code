#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n, m;
struct node{
    int generation;
    vector<int> child;
}Node[105];

int generation[105];
int highest = 0;

void BFS(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        if(highest < Node[top].generation){
            highest = Node[top].generation;
        }
        generation[Node[top].generation]++;
        for(int i = 0; i < Node[top].child.size(); i++){
            Node[Node[top].child[i]].generation = Node[top].generation + 1;
            q.push(Node[top].child[i]);
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
    Node[1].generation = 1;
    BFS(1);
    int longest = 0, longest_gen = 0;
    for(int i = 1; i <= highest; i++){
        if(generation[i] > longest){
            longest = generation[i];
            longest_gen = i;
        }
    }
    printf("%d %d", longest, longest_gen);

    return 0;
}