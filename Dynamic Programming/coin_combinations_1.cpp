#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define mod 1000000007

using namespace std;

int main(){
    ll n , x;
    cin>>n>>x;

    vector<ll>v(n);
    for(ll i = 0; i < n; i++){
        cin>>v[i];
    }
    vector<ll>dp(x + 1 , 0);
    dp[0] = 1;

    for(ll tar = 1; tar <= x; tar++){
        for(ll ind = 0; ind < n; ind++){
            if(tar >= v[ind])
            dp[tar] = (dp[tar] + dp[tar - v[ind]]) % mod;
        }
    }
    cout<<dp[x] % mod;
}