#include<bits/stdc++.h>
using namespace std;
int parent[100];
void makeSet(int u){
    parent[u]=u;
    return ;
}
int findRepresentative(int u){
    if(parent[u]==u)
    return u;
    return findRepresentative(parent[u]);
}
bool setunion(int u,int v){
    int x=findRepresentative(u);
    int y=findRepresentative(v);
    if(x!=y){
        parent[x]=y;
        return true;
    }
    return false;
}
void inti_set(int numNodes){
    for(int i=1;i<=numNodes;i++)
    makeSet(i);
    return;
}
struct edge{
    int u,v,w;
    edge(int _u,int _v,int _w){
        u=_u;
        v=_v;
        w=_w;
    }
};
bool comp(edge x,edge y){
    return x.w<y.w;
}
int main()
{
    vector<edge>edges;
    int numNodes,numEdges,sum=0;
    cin>>numNodes>>numEdges;
    inti_set(numNodes);
    for(int i=0;i<numEdges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(edge(u,v,w));
    }
    sort(edges.begin(),edges.end(),comp);
    for(int i=0;i<edges.size();i++){
        edge currentEdge= edges[i];
        bool check=setunion(currentEdge.u,currentEdge.v);
        if(check==true){
        sum+=currentEdge.w;
        }
    }
    cout<<"Minimum cost : "<<sum<<endl;
    return 0;
}

//input & output
/*
8 11
1 5 2
1 4 10
1 2 4
2 4 8
5 4 5
2 3 18
3 4 11
4 7 11
4 8 9
7 6 1
6 8 2
Minimum cost : 34
*/
