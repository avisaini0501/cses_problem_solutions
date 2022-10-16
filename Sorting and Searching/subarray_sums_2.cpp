#include<bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n, x;
    cin>>n>>x;
    vector<ll>v(n);
    
    for(ll i = 0; i < n; i++)
    cin>>v[i];

    map<ll , ll>seen;
    seen[0]++;

    ll sum = 0;
    ll count = 0;

    for(ll i = 0; i < n; i++){
      sum += v[i];
      count += seen[sum - x];
      seen[sum]++;
    }
    cout<<count;
}