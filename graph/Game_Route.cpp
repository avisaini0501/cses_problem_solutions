#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define mod 1000000007
#define pb push_back
#define pii pair<ll , ll>
#define loop(a , b) for(ll i = a; i < b; i++)
#define rep(a , b) for(ll i = a; i <= b; i++)
#define all(x) x.begin() , x.end()
#define triplet pair<ll , pair<ll , ll>>
#define goog(tno) cout<<"Case #"<<tno<<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll node , edge;
vector<ll>graph[100005];
vector<ll>dp(100005 , 0);
vector<ll>v;
vector<bool>vis(100005);
ll t = 0;
void dfs(ll src){
    vis[src] = 1;
    for(auto adj : graph[src]){
        if(!vis[adj])
          dfs(adj);
    } 
    v.pb(src);
}

int main(){
    cin>>node>>edge;
    loop(0 , edge){
        ll a , b;
        cin>>a>>b;
        graph[b].pb(a);
    }
    
    loop(1, node + 1){
        if(!vis[i]) dfs(i);
    }

    dp[1] = 1;
    for(auto i : v){
        for(auto j : graph[i]){
              dp[i] = (dp[i] + dp[j]) % mod;
        }
    }
    cout<<dp[node] % mod;
}