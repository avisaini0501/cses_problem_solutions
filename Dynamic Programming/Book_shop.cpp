#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define mod 1000000007

using namespace std;

int main(){
    ll n , p;
    cin>>n>>p;

    vector<pair<ll , ll>>v(n);
    for(ll i = 0; i < n; i++)  cin>>v[i].first;
    for(ll i = 0; i < n; i++)  cin>>v[i].second;
    
    vector<ll> prev(p + 1 , 0) , curr(p + 1 , 0);
    
    for(ll j = 0; j <= p; j++){
        if(j >= v[0].first) prev[j] = v[0].second;   
    }


    for(ll ind = 1; ind < n; ind++){
        for(ll tar = 0; tar <= p; tar++){
            ll nottake = prev[tar];

            ll take = -1e9;
            if(tar >= v[ind].first) take = v[ind].second + prev[tar - v[ind].first];

            curr[tar] = max(take , nottake) % mod;
        }
        prev = curr;
    }
    cout<<prev[p] % mod;
}