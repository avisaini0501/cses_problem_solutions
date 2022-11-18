#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
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
/*using namespace __gnu_pbds; */ 
/*template <typename T> using ordered_set = tree<T, null_type, less<T> , rb_tree_tag, tree_order_statistics_node_update>;*/

ll arr[200005];

struct data{
    ll sum , suff , pref , ans;
};

data make_pair(ll val){
    data res;
    res.sum = val;
    res.ans = res.pref = res.suff = max(0ll , val);
    return res;
}

data combine(data l , data r){
    data res;
    res.sum = (l.sum + r.sum);
    res.pref = max(l.pref , (l.sum + r.pref));
    res.suff = max(r.suff , (r.sum + l.suff));
    res.ans = max(max(l.ans , r.ans) , (l.suff + r.pref));
    return res;
}

void build(ll ind , ll low , ll high , data seg[]){
    if(low == high){
        seg[ind] = make_pair(arr[low]);
        return;
    }

    ll mid = (low + high) >> 1;
    build(2*ind+1 , low , mid , seg);
    build(2*ind+2, mid + 1 , high , seg);
    seg[ind] = combine(seg[2*ind+1] , seg[2*ind+2]);
}

void update(ll ind , ll low , ll high , ll pos , ll val, data seg[]){
   if(low == high){
      seg[ind] = make_pair(val);
      return;
   }

   ll mid = (low + high) >> 1;
   if(pos <= mid) update(2*ind+1 , low , mid , pos , val , seg);
   else update(2*ind+2 , mid+1, high , pos , val , seg);
   seg[ind] = combine(seg[2*ind+1] , seg[2*ind+2]);
}

int main(){
    fast_io;
    ll n , q;
    cin>>n>>q;
    loop(0 , n){
        cin>>arr[i];
    }
    
    data seg[4*n];
    build(0 , 0 , n - 1 , seg);

    while(q--){
        ll pos , val;
        cin>>pos>>val;
        pos--;
        update(0 , 0 , n - 1 , pos , val , seg);
        cout<<seg[0].ans<<endl;
    }
}