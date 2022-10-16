#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n;
    cin>>n;
    
    multiset<ll> s;
    for(ll i = 0; i < n; i++){
        ll x;
        cin>>x;
        auto it = s.upper_bound(x);
        if(it == s.end()) s.insert(x);
        else{
            s.erase(it);
            s.insert(x);
        }
    }
    cout<<s.size();
}