#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main(){
    ll n;
    cin>>n;
    
    ll ans = 1;

    for(int i = 1; i <= n; i++){
        ans = (2 * ans) % mod;
    }
    cout<<ans;
}