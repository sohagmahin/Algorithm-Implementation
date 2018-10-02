#include<iostream>
using namespace std;
int kadans(int arry[],int n)
{
    int max_current,max_global;
    max_current=max_global=arry[0];
    for(int i=1;i<=n-1;i++)
    {
       max_current=max(arry[i],max_current+arry[i]);
        if(max_current>max_global)
        max_global=max_current;

    }
    return max_global;
}
int main()
{
    int arry[]={-1,3,-2,5,-6,1};
    cout<<"Maximum Sum: "<<kadans(arry,6)<<endl;
    return 0;
}

