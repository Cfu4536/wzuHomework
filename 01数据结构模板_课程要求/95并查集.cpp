#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct
{
    int * parent;
    int size;
}SNode,* Set;

Set createSet(int size){
    Set s=(Set)malloc(sizeof(SNode));
    s->size=size;
    s->parent=(int*)malloc((size+1)*sizeof(int));
    return s;
}
void initSet(Set S){
    for(int i=0;i<S->size;i++){
        S->parent[i]=-1;
    }
}
int findSet(Set S,int x){
    int r=x;
    while(S->parent[r]!=-1){
        r=S->parent[r];
    }
    int t=x;
    while(S->parent[t]!=-1){
        x=t;
        t=S->parent[t];
        S->parent[x]=r;
    }
    return r;
}
void unionSet(Set S,int x,int y){
    int i=findSet(S,x);
    int j=findSet(S,y);
    if(i!=j){
        S->parent[i]=j;
    }
}
void destroySet(Set S){
    free(S->parent);
    free(S);
}
int main()
{
   int n,a,b;
   cin>>n;
   Set S=createSet(n);
   initSet(S);
   cin>>n;
   for(int i=1;i<=n;i++){
        cin>>a>>b;
        unionSet(S,a,b);
   }
   cin>>n;
   for(int i=1;i<=n;i++){
       cin>>a>>b;
       if(findSet(S,a)==findSet(S,b)){
           cout<<"yes"<<endl;
       }else{
           cout<<"no"<<endl;
       }
   }
    return 0;
}
