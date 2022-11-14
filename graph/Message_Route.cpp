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
vector<bool>vis(100005);
vector<ll> dist(100005);
vector<ll>graph[100005];
vector<ll>path(100005);
queue<ll> q;

int main(){
    cin>>node>>edge;
    loop(0 , edge){
        ll a , b;
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    
    q.push(1);
    vis[1] = 1;

    while(!q.empty()){
        ll v = q.front();
        q.pop();

        for(auto adj : graph[v]){
            if(!vis[adj]){
                dist[adj] = dist[v]  + 1;
                vis[adj] = 1;
                path[adj] = v;
                q.push(adj);
            }
        }
    }
    if(!vis[node]){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    ll u = node;
    ll k = dist[node];
    vector<ll>ans(k + 1);
    for(ll i = k; i >= 0; i--){
        ans[i] = u;
        u = path[u];
    }

    cout<<k + 1<<endl;
    for(ll i = 0; i <= k; i++) cout<<ans[i]<<" ";
}