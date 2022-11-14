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

bool vis[501];
vi graph[501];
ll n , m, k , c;
ll mt[501];

bool kuhns(ll u){
    if(vis[u]) return false;

    vis[u] = 1;
    for(ll v : graph[u]){
        if(!mt[v] || kuhns(mt[v])){
            mt[v] = u;
            return true;
        }
    }
    return false;
}

int main(){
    fast_io;
    cin>>n>>m>>k;

    loop(0 , k){
        ll a , b;
        cin>>a>>b;
        graph[a].pb(b);
    }

    loop(1 , m + 1){
        fill(vis + 1 , vis + n + 1 , false);
        kuhns(i);
    }

    c = 0;  
    vp ans;
    if(m > n) swap(n , m);
    loop(1 , n + 1){
      if(mt[i]){
        ans.pb({mt[i] , i});
        c++;
      }
    }
    
    cout<<c<<endl;
    for(auto p : ans){
        cout<<p.first<<" "<<p.second<<endl;
    }
}