#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T> , rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define endl '\n'

struct range{
    ll l , r , index;
    bool operator < (const range &other) const{
        if(l == other.l)
          return r > other.r;
        return l < other.l;
    }
};

int main(){
    ll n;
    cin>>n;
    vector<range> ranges(n);
    vector<ll>contained(n);
    vector<ll>contains(n);
    ordered_set<pair<ll , ll>> rightbound;
    for(ll i = 0; i < n; i++){
        cin>>ranges[i].l;
        cin>>ranges[i].r;
        ranges[i].index = i;
    }
    sort(ranges.begin() , ranges.end());

    for(ll i = 0; i < n; i++){
        rightbound.insert({ranges[i].r , -1 * i});
        contained[ranges[i].index] = rightbound.size() - rightbound.order_of_key({ranges[i].r , -1 * i}) - 1;
    }
    rightbound.clear();
    
    for(ll i = n - 1; i >= 0; i--){
        rightbound.insert({ranges[i].r , -1 * i});
        contains[ranges[i].index] = rightbound.order_of_key({ranges[i].r , -1 * i});
    }
     for(ll i = 0; i < n; i++){
        cout<<contains[i]<<" ";
    }
    cout<<endl;
    for(ll i = 0; i < n; i++){
        cout<<contained[i]<<" ";
    }
}