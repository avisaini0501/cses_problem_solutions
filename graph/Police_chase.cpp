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
ll path[501];
ll  n , m;
ll adj[501][501] , oadj[501][501];
vector<pii> ans;

bool reach(){
    memset(vis , 0 , sizeof(vis));
    queue<ll> q;
    q.push(1); vis[1] = 1;

    while(!q.empty()){
        ll i = q.front(); q.pop();
        for(ll j = 1; j <= n; j++){
          if(adj[i][j] && !vis[j]){
            q.push(j); vis[j] = 1;
            path[j] = i;
          }
        }
    }
    return vis[n];
}

int main(){
    fast_io;
    cin>>n>>m;
    loop(0 , m){
        ll a , b;
        cin>>a>>b;
        adj[a][b]++ , adj[b][a]++;
        oadj[a][b]++ , oadj[b][a]++;
    }
    
    ll v , u;
    ll maxflow = 0;
    while(reach()){
        ll flow = 1e18;
        for(v = n; v != 1; v = path[v]){
           u = path[v];
           flow = min(flow , adj[u][v]);
        }
         
        maxflow += flow; 

        for(v = n; v != 1; v = path[v]){
            u = path[v];
            adj[u][v] -= flow;
            adj[v][u] += flow;
        }
    }

    reach();
    
    loop(1 , n + 1){
        for(ll j = 1; j <= n; j++){
           if(vis[i] && !vis[j] && oadj[i][j]){
             ans.pb({i , j});
           }
        }
    }

    cout<<ans.size()<<endl;
    for(auto t : ans){
        cout<<t.first<<" "<<t.second<<endl;
    }
}