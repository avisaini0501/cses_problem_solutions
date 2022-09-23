#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i = 0; i < n; i++){
        cin>>v[i];
    }

    sort(v.begin() , v.end());

    ll cost = 0;
    ll med = v[n / 2];
    for(ll i = 0; i < n; i++){
        cost += abs(v[i] - med);
    }
    cout<<cost;
}