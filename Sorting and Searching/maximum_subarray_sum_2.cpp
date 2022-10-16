#include<bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n , a , b;
    cin>>n>>a>>b;
    vector<ll>v(n + 1);
    for(ll i = 1; i <= n; i++){
        cin>>v[i];
    }
    for(ll i = 1; i <= n; i++){
        v[i] += v[i - 1];
    }
    set<pair<ll ,ll>>s;
    for(ll i = a; i <= b; i++)
    s.insert({v[i] , i});
    
    ll max_sum = -1e18;
    for(ll i = 1; i <= n - a + 1; i++){
        max_sum = max(max_sum , s.rbegin()->first - v[i - 1]);
        s.erase({v[i + a - 1] , i + a - 1});
        if(i + b <= n){
            s.insert({v[i + b] , i + b});
        }
    }
    cout<<max_sum;
}