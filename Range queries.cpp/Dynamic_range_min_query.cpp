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
    seg[ind] = min(seg[2 * ind + 1] , seg[2 * ind + 2]);
}

void update(ll ind , ll low , ll high, ll i, ll val, ll seg[]){
    if(low == high){
        seg[ind] = val;
        return;
    }
    
    ll mid = (low + high) >> 1;
    if(i <= mid) update(2*ind+1, low , mid , i , val,  seg);
    else update(2*ind+2, mid+1, high, i , val , seg);
    seg[ind] = min(seg[2*ind+1] , seg[2*ind+2]);
}

ll query(ll ind , ll low, ll high, ll l , ll r, ll seg[]){
    //no overlap
    if(l > high || r < low) return 1e9;

    //complete overlap 
    if(low >= l && high <= r) return seg[ind];

    //partial overlap
    ll mid = (low + high) >> 1;
    ll left = query(2*ind+1 , low , mid , l , r , seg);
    ll right = query(2*ind+2 , mid + 1 , high, l , r, seg);
    return min(left , right);
}


int main(){
    fast_io;
    cin>>n>>q;
    loop(0 , n){
        cin>>arr[i];
    }
    ll seg[4*n];
    build(0 , 0 , n - 1 , seg);
    while(q--){
        ll type;
        cin>>type;
        if(type == 2){
            ll a , b;
            cin>>a>>b;
            a--,b--;
          cout<<query(0 , 0 , n - 1 , a , b , seg)<<endl;
        }  
        else{
            ll i ,  val;
            cin>>i>>val;
            i--;
            update(0 , 0 , n - 1 , i ,val, seg);
            arr[i]= val;
        }
    }
}