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
    ll n , q;
    cin>>n>>q;
    ll arr[n];
    ordered_set<pii> set;

    loop(0 , n){
        cin>>arr[i];
        set.insert({arr[i] , i});
    }

    while(q--){
        char type;
        cin>>type;
        if(type == '!'){
            ll a , b;
            cin>>a>>b;
            a--;
            set.erase({arr[a] , a});
            arr[a] = b;
            set.insert({arr[a] , a});
        }
        else{
            ll x , y;
            cin>>x>>y;
            cout<<set.order_of_key({y , mod}) - set.order_of_key({x - 1 , mod})<<endl;
        }
    }

}