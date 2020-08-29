#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n;
double P, r;

struct node{
    double price;
    double amount;
    bool is_retailer;
    vector<int> child;
}Node[100010];

double sales = 0.0;
void BFS(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        if(Node[top].is_retailer == true){
            sales += Node[top].price * Node[top].amount;
        }
        else{
            for(int i = 0; i < Node[top].child.size(); i++){
                Node[Node[top].child[i]].price = Node[top].price * (1 + r * 0.01);
                q.push(Node[top].child[i]);
            }
        }
    }
}

int main(){
    scanf("%d %lf %lf", &n, &P, &r);
    for(int i = 0; i < n; i++){
        int k;
        scanf("%d", &k);
        if(k == 0){
            Node[i].is_retailer = true;
            scanf("%lf", &Node[i].amount);
        }
        else{
            Node[i].is_retailer = false;
            Node[i].amount = 0.0;
        }
        for(int j = 0; j < k; j++){
            int temp;
            scanf("%d", &temp);
            Node[i].child.push_back(temp);
        }
    }
    Node[0].price = P;
    BFS(0);
    printf("%.1f", sales);
    return 0;
}