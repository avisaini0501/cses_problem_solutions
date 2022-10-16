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

    set<ll> heard;
    ll i , j;
    i = j = 0;
    ll ans = 0;
    
    while(i < n && j < n){
        while(j < n && !heard.count(v[j])){
            heard.insert(v[j]);
            ans = max(ans , j - i + 1);
            j++;
        }
        while(j < n && heard.count(v[j])){
            heard.erase(v[i]);
            i++;
        }
    }
    cout<<ans;
}