#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T> , rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define endl '\n'

int main(){
    ll n , k;
    cin>>n>>k;
    vector<ll>v(n);
    for(ll i = 0; i < n; i++)
    cin>>v[i];

    ordered_set<pair<ll ,ll>>win;
    for(ll i = 0; i < k; i++)
     win.insert({v[i] , i});
    cout<<win.find_by_order((k - 1) / 2)->first<<" ";

    for(ll i = 1; i < n - k +1; i++){
        win.erase({v[i -1] , i -1});
        win.insert({v[i + k - 1] , i + k - 1});
        cout<<win.find_by_order((k - 1) / 2)->first<<" ";
    }
}