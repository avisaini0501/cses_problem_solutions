#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define mod 1000000007

using namespace std;

int main(){
    ll n , m;
    cin>>n>>m;

    vector<ll>v(n + 1);
    for(ll i = 1; i <= n; i++)
     cin>>v[i];

     vector<ll> prev(m+2, 0) , curr(m+2 , 0);

     for(ll i = 1; i <= m; i++){
        if(v[1] == i || v[1] == 0) prev[i] = 1;
     }
     

     for(ll i = 2; i <= n; i++){
        for(ll x = 1; x <= m; x++){
           if(v[i] == 0 || v[i] == x)
            curr[x] = (prev[x - 1] % mod + prev[x] % mod + prev[x + 1] % mod) % mod;
            else curr[x] = 0;
        }
        prev = curr;
    }
    ll ans = 0;
    for(ll i = 1; i<= m; i++)
      ans += prev[i];

    cout<<ans % mod;
}