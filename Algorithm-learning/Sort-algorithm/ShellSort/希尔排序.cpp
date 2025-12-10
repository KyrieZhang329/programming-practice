#include<iostream>
#include<vector>
using namespace std;

void ShellSort(vector<int>& v)
{
    int n=v.size();
    for(int gap=n/2;gap>0;gap/=2)
    {
        for(int i=gap;i<n;i++)
        {
            int temp=v[i];
            int j;
            for(j=i;j>=gap&&v[j-gap]>temp;j-=gap)
                v[j]=v[j-gap];
            v[j]=v[gap];
        }
    }
}

int main() 
{
    vector<int> data={8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
    ShellSort(data);
    for(int i:data)
        cout<<i<<" ";
    return 0;
}