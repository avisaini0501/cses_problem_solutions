#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define mod 1000000007

using namespace std;

int main(){
    ll n , x;
    cin>>n>>x;

    vector<ll>v(n);
    for(ll i = 0; i < n; i++)
    cin>>v[i];

    vector<ll> prev(x + 1 , 0) , curr(x + 1 , 0);

    for(ll i = 0; i <= x; i++){
        if(i % v[0] == 0) prev[i] = 1;
    }

    for(ll ind = 1; ind < n; ind++){
        for(ll tar = 0; tar <= x; tar++){
            ll nottake = prev[tar];

            ll take = 0;
            if(tar >= v[ind]) take = curr[tar - v[ind]];

            curr[tar] = (take + nottake) % mod;
        }
        prev = curr;
    }
    cout<<prev[x] % mod;
}