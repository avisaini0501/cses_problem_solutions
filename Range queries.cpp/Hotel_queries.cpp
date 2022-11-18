#include<bits/stdc++.h>
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

ll n , q;
ll arr[200005];

void build(ll ind , ll low , ll high , ll seg[]){
    if(low == high){
        seg[ind] = arr[low];
        return;
    }

    ll mid = (low + high) >> 1;
    build(2 * ind + 1 , low , mid , seg);
    build(2 * ind + 2 , mid+1 , high , seg);
    seg[ind] = max(seg[2 * ind + 1] , seg[2 * ind + 2]);
}

void query(ll ind , ll low, ll high, ll val, ll seg[]){
    if(low == high){
        seg[ind] -= val;
        cout<<low+1<<" ";
        return;
    }
    
       ll mid = (low + high) >> 1;
       if(seg[2*ind+1] >= val) query(2*ind+1 , low , mid , val, seg);
       else query(2*ind+2 , mid + 1 , high, val, seg);
       seg[ind] = max(seg[2*ind+1] , seg[2*ind+2]);
       return;
      
}

int main(){
    fast_io;
    cin>>n>>q;
    loop(0 , n){
        cin>>arr[i];
    }
    ll seg[4*n];
    build(0 , 0 , n - 1, seg);

    while(q--){
        ll x;
        cin>>x;
        if(seg[0] < x) cout<<"0"<<" ";
        else query(0 , 0 , n - 1, x, seg);
    }
}