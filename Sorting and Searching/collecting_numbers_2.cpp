#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n , q;
    cin>>n>>q;

    vector<ll>v(n + 1);
    vector<ll>pos(n + 1);
    for(ll i = 1; i <= n; i++){
        cin>>v[i];
        pos[v[i]] = i;
    }
    ll ans = 1;
    for(ll i = 1; i < n; i++){
        if(pos[i] > pos[i + 1])
          ans++;
    }
    set<pair<ll , ll>>pairs;
    while(q--){
        ll l , r;
        cin>>l>>r;

        if(v[l] + 1 <= n)
        pairs.insert({v[l] , v[l] + 1});
        if(v[l] - 1 >= 1)
        pairs.insert({v[l] - 1, v[l]});
        if(v[r] + 1 <= n)
        pairs.insert({v[r] , v[r] + 1});
        if(v[r] - 1 >= 1)
        pairs.insert({v[r] - 1, v[r]});

        for(pair<ll , ll> z : pairs){
            if(pos[z.first] > pos[z.second])
            ans--;
        }
        
        swap(v[l] , v[r]);
        pos[v[l]] = l;
        pos[v[r]] = r;

        for(pair<ll , ll> z : pairs){
            if(pos[z.first] > pos[z.second])
            ans++;
        }
        cout<<ans<<endl;
        pairs.clear();
    }

}