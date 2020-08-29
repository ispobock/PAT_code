#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, s;

struct node{
    int wight;
    int sum;
    vector<int> child;
}Node[105];

bool cmp(int a, int b){
    return Node[a].wight > Node[b].wight;
}

void preorder(int root, int sum, vector<int> vi){
    sum += Node[root].wight;
    vi.push_back(Node[root].wight);
    if(sum > s){ //剪枝
        return;
    }
    if(sum == s && Node[root].child.empty()){
        for(int i = 0; i < vi.size(); i++){
            printf("%d", vi[i]);
            if(i != vi.size() - 1){
                printf(" ");
            }
        }
        printf("\n");
    }
    for(int i = 0; i < Node[root].child.size(); i++){
        preorder(Node[root].child[i], sum, vi);
    }
    vi.pop_back();
}

int main(){
    scanf("%d %d %d", &n, &m, &s);
    for(int i = 0; i < n; i++){
        scanf("%d", &Node[i].wight);
    }
    for(int i = 0; i < m; i++){
        int id, k, temp;
        scanf("%d %d", &id, &k);
        for(int j = 0; j < k; j++){
            scanf("%d", &temp);
            Node[id].child.push_back(temp);
        }
        sort(Node[id].child.begin(), Node[id].child.end(), cmp);
    }

    vector<int> vi;
    preorder(0, 0, vi);

    return 0;
}