#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define mod 1000000007
#define pb push_back
#define pii pair<ll , ll>
#define vc vector
#define vi vector<ll>
#define vii vector<vector<<ll>>
#define loop(a , b) for(ll i = a; i < b; i++)
#define rep(a , b) for(ll i = a; i <= b; i++)
#define all(x) x.begin() , x.end()
#define triplet pair<ll , pair<ll , ll>>
#define goog(tno) cout<<"Case #"<<tno<<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

vi graph1[100005] , graph2[100005],b[100005];
bool vis[100005];
ll coins[100005];
ll comp[100005];
ll sum[100005];
ll k = 0;
vi topo;

void dfs(ll src){
    vis[src] = 1;
    for(auto adj : graph1[src]){
        if(!vis[adj]) dfs(adj);
    }
    topo.pb(src);
}

void dfs2(ll src){
  vis[src] = 1;
  comp[src] = k;

  for(auto adj : graph2[src]){
    if(!vis[adj]){
        dfs2(adj);
    }
  }
}
int main(){
    fast_io;
    ll n , m;
    cin>>n>>m;
    loop(1 , n + 1){
        cin>>coins[i];
    }
    
    loop(0 , m){
        ll a , b;
        cin>>a>>b;
        graph1[a].pb(b);
        graph2[b].pb(a);
    }

    loop(1 , n + 1){
        if(!vis[i]) dfs(i);
    }
    
    memset(vis , 0 , sizeof(vis));
    
    for(ll i = topo.size() - 1; i >= 0; i--){
        ll x = topo[i];
        if(!vis[x]){
            k++;
          dfs2(x);
        }
    }
    loop(1 , n + 1){
        sum[comp[i]] += coins[i];
    }

    loop(1 , n + 1){
        for(auto j : graph1[i]){
            if(comp[j] != comp[i])
               b[comp[i]].pb(comp[j]);
        }
    }

    memset(vis , 0 , sizeof(vis));
    vi v;
    while(!topo.empty()){
      ll i = topo.back();
      topo.pop_back();
      if(!vis[comp[i]]){
         v.pb(comp[i]);
         vis[comp[i]] = 1;
      }
    }
    while(!v.empty()){
        ll u = v.back();
        v.pop_back();
        ll mx = sum[u];
        for(auto adj : b[u]){
           mx = max(mx , sum[u] + sum[adj]);
        }
        sum[u] = mx;
    }
    ll ans = 0;
    loop(1 , k + 1){
      ans = max(ans , sum[i]);
    }
    cout<<ans;
}