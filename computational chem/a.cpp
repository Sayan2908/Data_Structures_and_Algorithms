#include<bits/stdc++.h>

using namespace std;

void read_dat(vector<int>&arr,int i,int n){
    if(i==n) return;
    cin>>arr[i];
    read_dat(arr,i+1,n);
}

void print(vector<int> arr,int i){
    cout<<arr[i]<<endl;
    print(arr,i+1);
}
int main()
{   int n=6;
    vector<int> arr(n);
    read_dat(arr,0,n);
    print(arr,0);
    for(int i=0;i<n;i++) cout<<arr[i]<<endl;
    return 0;
}