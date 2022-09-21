#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n , m;
    cin>>n>>m;
    set<pair<ll , ll>>s;
    for(ll i = 0; i < n; i++){
       ll a;
       cin>>a;
       s.insert({a , i});
    }
    for(ll i = 0; i < m; i++){
        ll t;
        cin>>t;
        auto it = s.lower_bound({t + 1 , 0});
        if(it == s.begin())
        cout<<"-1"<<endl;
        else{
            it--;
            cout<<(*it).first<<endl;
            s.erase(it);
        }
    }
    
    return 0;
}