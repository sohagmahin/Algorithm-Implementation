#include<iostream>
using namespace std;
int kadans(int arry[],int n)
{
    int max_current,max_global;
    int max_left,max_right;
    max_current=max_global=arry[0];
    max_left=max_right=0;
    for(int i=1;i<=n-1;i++)
    {
       // max_current=max(arry[i],max_current+arry[i]);
        if(arry[i]>max_current+arry[i])
        {
            max_current=arry[i];
            max_left=max_right=i;
        }
        else{
            max_current+=arry[i];
        }

        if(max_current>max_global){
        max_global=max_current;
        max_right=i;
        }
    }

    for(int i=max_left;i<=max_right;i++)
        cout<<arry[i]<<" ";
    cout<<endl;
    return max_global;
}
int main()
{
    int arry[]={-1,3,-2,5,-6,1};
    cout<<"Maximum Sum: "<<kadans(arry,6)<<endl;
    return 0;
}
