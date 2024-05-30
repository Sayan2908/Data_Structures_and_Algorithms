#include <bits/stdc++.h>
using namespace std;

#define long long ll
#define mod 1000000007
#define pb push_back
#define vector<int> vi
#define vector<long long> vll
#define vector<vector<int>> vvi

int zz(){

}

int main(){
    int T;
    cin >> T;

    while (T--){
        int n;
        cin >> n;
        string s,t;
        cin >> s;
        t = s;
        sort(t.begin(),t.end());
        if (t==s)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;

    }
    return 0;
}