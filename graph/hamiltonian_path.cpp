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

ll n , m;
ll dp[20][1<<20];

ll dfs(ll src , ll mask , vi graph[]){

    if(__builtin_popcount(mask) == n) return 1;
    else if(src == n - 1) return 0;

    if(dp[src][mask] != -1) return dp[src][mask];

    ll res = 0;
    for(auto adj : graph[src]){
        if(mask & (1 << adj)) continue;

        res = (res + dfs(adj , mask | (1 << adj) , graph)) % mod;
    }
    return dp[src][mask] = res;

}

int main(){
    fast_io;
    cin>>n>>m;
    vi graph[n + 1];
    while(m--){
        ll a , b;
        cin>>a>>b;
        --a , --b;
        graph[a].pb(b);
    }
    memset(dp , -1 , sizeof(dp));
    cout<<dfs(0 , (1<<0) , graph);
}