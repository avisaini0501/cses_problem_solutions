#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n;
    cin>>n; 
    vector<ll>v(n);
    for(ll i = 0; i < n; i++)
    cin>>v[i];

    sort(v.begin() , v.end());

    ll ans = 1;
    for(ll i = 0; i < n; i++){
        if(ans < v[i])
        break;
        ans += v[i];
    }
    cout<<ans;
}