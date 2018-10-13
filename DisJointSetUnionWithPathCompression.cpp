#include<iostream>
using namespace std;
#define size 10000
int parent[size];
void makeset(int u){
    parent[u]=u;
    return;
}

void int_disjoint_set(int NthNodes){
    for(int i=1;i<NthNodes;i++){
        makeset(i);
    }
    return;
}

int FindRepresentative(int u){
    if(parent[u]==u)
        return u;
        return parent[u]=FindRepresentative(parent[u]);//with path compression
}
void Union(int a,int b){
 int u=FindRepresentative(a);
 int v=FindRepresentative(b);
 if(u!=v)
    parent[u]=v;
    return;
}

int main()
{
    int_disjoint_set(6);//There are six nodes.
   
   
    Union(2,1);          //     1    
    Union(3,2);          //    / 
                       //     2
                       //   /
                       //  3
                
                    
    Union(5,4);         //      4
    Union(6,5);        //      /
                        //    5
                        //   /
                        //  6
    
    Union(4,1);       //       1
                    //        / \
                    //      2    4
                    //     /       \
                    //    3         5
                    //               \
                    //                6           
    
                    
    
    
    cout<<FindRepresentative(5)<<endl;
    return 0;
}

