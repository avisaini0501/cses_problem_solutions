#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<pair<ll , ll>>v;
    for(ll i = 0; i < n; i++){
        ll a , b;
        cin>>a>>b;
        v.push_back({b , a});
    }
    sort(v.begin() , v.end());

    ll ans = 0;
    ll end = 0;
    for(auto it : v){
        if(it.second >= end){
            end = it.first;
            ans++;
        }
    }
    cout<<ans;
}