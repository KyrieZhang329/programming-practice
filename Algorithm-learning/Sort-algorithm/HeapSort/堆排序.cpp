#include <iostream>
#include <vector>
using namespace std;

void Heapify(vector<int>& v,int n,int i) 
{
    int largest=i;
    int left=2*i+1; 
    int right=2*i+2;
    if (left<n&&v[left]>v[largest]) 
        largest=left;
    if (right<n&&v[right]>v[largest]) 
        largest= right;
    if (largest!=i) 
    {
        swap(v[i],v[largest]);
        Heapify(v,n,largest);
    }
}

void HeapSort(vector<int>& v) 
{
    int n=v.size();
    for(int i=n/2-1;i>=0;i--) 
        Heapify(v,n,i);
    for(int i=n-1;i>0;i--) 
    {
        swap(v[0],v[i]);
        Heapify(v,i,0);
    }
}

int main() 
{
    vector<int> v={12, 11, 13, 5, 6, 7};
    HeapSort(v);
    for(int& i:v)
        cout<<i<<" ";
    return 0;
}