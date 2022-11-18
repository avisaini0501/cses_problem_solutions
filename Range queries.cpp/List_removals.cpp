#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define endl '\n'
#define mod 1000000007
#define pb push_back
#define pii pair<ll , ll>
#define vc vector
#define vp vector<pair<ll , ll>>
#define vi vector<ll>
#define vii vector<vector<<ll>>
#define loop(a , b) for(ll i = a; i < b; i++)
#define rep(a , b) for(ll i = a; i <= b; i++)
#define all(x) x.begin() , x.end()
#define triplet pair<ll , pair<ll , ll>>
#define goog(tno) cout<<"Case #"<<tno<<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T> , rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    fast_io;
    ll n;
    cin>>n;
    ll arr[n];
    ordered_set<ll>set;
    
    loop(0, n){
        cin>>arr[i];
        set.insert(i);
    }
    
    loop(0 , n){
        ll ind;
        cin>>ind;
        ind--;
        ll pos = *set.find_by_order(ind);
        cout<<arr[pos]<<" ";
        set.erase(pos);
    }
}

