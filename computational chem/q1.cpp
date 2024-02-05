#include<bits/stdc++.h>
using namespace std;

int onepow(int n){
    if(n%2 == 0) return 1;
    return -1;
}

int fact(int n){
    int ans = 1;
    while(n>1){
        ans*= n;
        n--;
    }
    return ans;
}

int sin(int n,int x){
    int res=0;
    while(n>=0){
        res+= onepow(n)*pow(x,2*n+1)/fact(2*n+1);
        n--;
    }
    return res;
}

int main(){
    int ans = sin(4,3.14);
    cout<<ans<<endl;
 return 0;
}