#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n;
    cin>>n;

    vector<ll>v(n);
    vector<ll>pos(n);
    for(ll i = 0; i < n; i++){
        cin>>v[i];
        v[i]--;
        pos[v[i]] = i;
    }
    ll ans = 1;
    for(ll i = 1; i < n; i++){
        if(pos[i] < pos[i - 1])
          ans++;
    }
    cout<<ans;
}