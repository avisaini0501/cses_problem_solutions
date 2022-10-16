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
    ordered_set<ll>child;
    for(ll i = 1; i <= n; i++){
        child.insert(i);
    }
    ll startpos = 0;
    while(child.size() > 0){
        startpos = startpos % child.size();
        ll pos_remove = (startpos + k) % child.size();
        startpos = pos_remove;
        auto t = child.find_by_order(pos_remove);
        cout<<*t<<" ";
        child.erase(t);
    }
}