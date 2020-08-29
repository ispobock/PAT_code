#include <cstdio>
#include <vector>
using namespace std;

int n;
double P, r;

struct node{
    double price;
    vector<int> child;
}Node[100010];

double highest = 0;
int index = 0;
void DFS(int root){
    if(Node[root].child.size() == 0){
        if(Node[root].price == highest){
            index++;
        }
        if(Node[root].price > highest){
            highest = Node[root].price;
            index = 1;
        }
        return;
    }
    for(int i = 0; i < Node[root].child.size(); i++){
        Node[Node[root].child[i]].price = Node[root].price * (1 + r * 0.01);
        DFS(Node[root].child[i]);
    }
}

int main(){
    scanf("%d %lf %lf", &n, &P, &r);
    int root;
    for(int i = 0; i < n; i++){
        int temp;
        scanf("%d", &temp);
        if(temp == -1){
            root = i;
            continue;
        }
        Node[temp].child.push_back(i);
    }
    Node[root].price = P;
    DFS(root);
    printf("%.2lf %d", highest, index);
}