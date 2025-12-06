#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

void CountingSort(vector<int>& v,int exp)
{
    vector<int> output((int)v.size());
    vector<int> count(19,0);

    for(int i:v)
        count[(i/exp)%10+9]++;
    for(int i=1;i<(int)count.size();i++)
        count[i]+=count[i-1];
    
    for(int i=(int)v.size()-1;i>=0;i--)
    {
        int digit=(v[i]/exp)%10+9;
        output[count[digit]-1]=v[i];
        count[digit]--;
    }
    v=output;
}

void RadixSort(vector<int>& v)
{
    int max_val=max(abs(*max_element(v.begin(),v.end())),abs(*min_element(v.begin(),v.end())));
    for(int exp=1;max_val/exp>0;exp*=10)
        CountingSort(v,exp);
}

int main()
{
    vector<int> v{23,3948,129,387,-1992,3728,388,459,-837,9};
    RadixSort(v);
    for(int i:v)
        cout<<i<<" ";
    return 0;
}