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
    ll count = 0;
    map<ll , ll>seen;
    seen[0]++;
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        sum += v[i];
        ll rem = sum % n;
        if(rem < 0) rem += n;
        count += seen[rem];
        seen[rem]++; 
    }
    cout<<count;
}