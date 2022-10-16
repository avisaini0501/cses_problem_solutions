#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define mod 1000000007

using namespace std;

int main(){
    ll n , x;
    cin>>n>>x;

    vector<ll>v(n);
    for(ll i = 0; i < n; i++)
      cin>>v[i];

    vector<ll>dp(x + 1 , 1e9);
    dp[0] = 0;
    
    for(ll i = 0; i < n; i++){
        for(ll tar = 1; tar <= x; tar++){
            if(tar >= v[i])
              dp[tar] = min(dp[tar] , dp[tar - v[i]] + 1);
        }
    }
    if(dp[x] == 1e9) cout<<"-1";
     else cout<<dp[x];

}