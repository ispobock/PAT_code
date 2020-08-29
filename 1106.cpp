#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n;
double p, r;
struct node{
    double price;
    bool isleaf;
    vector<int> child;
}Node[100010];

double lowest = 0;
int count = 0;
bool flag = false;
void BFS(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        if(Node[top].isleaf == true && flag == false){
            lowest = Node[top].price;
            flag = true;
        }
        if(flag == true && Node[top].price == lowest && Node[top].isleaf == true){
            count++;
        }
        if(flag == true && Node[top].price > lowest){
            break;
        }
        for(int i = 0; i < Node[top].child.size(); i++){
            Node[Node[top].child[i]].price = Node[top].price * (1 + r * 0.01);
            q.push(Node[top].child[i]);
        }
    }
}

int main(){
    scanf("%d %lf %lf", &n, &p, &r);
    for(int i = 0; i < n; i++){
        int k;
        scanf("%d", &k);
        if(k == 0){
            Node[i].isleaf = true;
            continue;
        }
        else{
            Node[i].isleaf = false;
            for(int j = 0; j < k; j++){
                int temp;
                scanf("%d", &temp);
                Node[i].child.push_back(temp);
            }
        }
    }
    Node[0].price = p;
    BFS(0);
    printf("%.4lf %d", lowest, count);
    return 0;
}