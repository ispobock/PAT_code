#include<cstdio>  
#include<cstring>  
#include<string>  
#include<algorithm>  
#include<map>  
using namespace std;  
struct node{  
    char id[10];  
    int h,m,s,flag;  
    char t[5];  
    friend bool operator==(const node& a,const node& b){  
        return a.h==b.h&&a.s==b.s&&a.m==b.m;  
    }  
    friend bool operator < (const node& a,const node& b){  
        if(a.h!=b.h) return a.h<b.h;  
        else if(a.m!=b.m) return a.m<b.m;  
        else if(a.s!=b.s) return a.s<b.s;  
        else return strcmp(a.id,b.id)<0;  
    }  
};  
node k[10005];  
int main(){  
    int n,m,maxn=0;  
    scanf("%d%d",&n,&m);  
    map<string,int>si;  
    map<string,int>time;  
    map<string,int>ans;  
    for(int i=0;i<n;++i)  
        scanf("%s %d:%d:%d %s",k[i].id,&k[i].h,&k[i].m,&k[i].s,k[i].t);  
    sort(k,k+n);  
    for(int i=0;i<n;++i){  
        string temp(k[i].id);  
        string te(k[i].t);  
        if(te=="in"){  
            si[temp]=i;  
            time[temp]=(k[i].h*3600+k[i].m*60+k[i].s);  
            if(time[temp]==0) time[temp]=-1;  
        }  
        else if(time[temp]){  
            if(time[temp]==-1) time[temp]=0;  
            ans[temp]+=(k[i].h*3600+k[i].m*60+k[i].s-time[temp]);  
            k[si[temp]].flag=1;  
            k[i].flag=1;  
            time[temp]=0;  
            maxn=max(ans[temp],maxn);  
        }  
    }  
    int j=0,an=0;   
    for(int i=0;i<m;++i){  
        int a,b,c;  
        scanf("%d:%d:%d",&a,&b,&c);  
        for(;j<n;++j){  
            if(a*3600+b*60+c>=k[j].h*3600+k[j].m*60+k[j].s){  
              if(k[j].flag&&k[j].t[0]=='i') an++;  
              else if(k[j].flag&&k[j].t[0]=='o') an--;  
           }  
           else break;  
        }  
        printf("%d\n",an);  
    }  
    int y=0;  
    map<string,int>::iterator it;  
    for(it=ans.begin();it!=ans.end();it++){  
        if(it->second==maxn){  
            if(y) printf(" %s",it->first.c_str());  
            else{  
                y=1;  
                printf("%s",it->first.c_str());  
            }  
        }  
    }  
    printf(" %02d:%02d:%02d\n",maxn/3600,maxn%3600/60,maxn%60);  
    return 0;
}