#include<bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<pair<ll , ll>>v(n);

    for(ll i = 0; i < n; i++){
       cin>>v[i].first >> v[i].second;
    }

    sort(v.begin() , v.end());

    ll reward = 0;
    ll time = 0;

    for(ll i = 0; i < n; i++){
        reward += (v[i].second - v[i].first - time);
        time += v[i].first;
    }
    cout<<reward;
}