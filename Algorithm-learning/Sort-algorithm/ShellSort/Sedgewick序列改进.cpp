#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void ShellSortSedgewick(vector<int>& v)
{
    int n=v.size();
    if(n<=1) 
        return;
    vector<int> gaps;
    int k=0;
    while(true) 
    {
        int gap;
        if (k%2==0) 
            gap=9*(static_cast<int>(pow(2,k))-static_cast<int>(pow(2,k/2)))+1;
        else
            gap=8*static_cast<int>(pow(2, k))-6*static_cast<int>(pow(2,(k+1)/2))+1;
        if(gap>n) 
            break;
        gaps.push_back(gap);
        k++;
    }

    for (auto it=gaps.rbegin();it!=gaps.rend();it++) 
    {
        int gap=*it;
        for (int i=gap;i<n;i++) 
        {
            int temp=v[i];
            int j;
            for (j=i;j>=gap&&v[j-gap]>temp;j-=gap)
                v[j]=v[j-gap];
            v[j]=temp;
        }
    }
}

int main() 
{
    vector<int> data={8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
    ShellSortSedgewick(data);
    for(int i:data)
        cout<<i<<" ";
    return 0;
}