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
vector<ll>dis(100005 , 0);
vector<ll>par(100005, 0);
vector<ll>ans , v;
vector<bool>vis(100005);
priority_queue<pii , vector<pii> , greater<pii>>pq;

void dfs(ll s){
    vis[s] = 1;
    for(auto adj : graph[s]){
        if(!vis[adj]) dfs(adj);
    }
    v.pb(s);
}

int main(){
    cin>>node>>edge;
    loop(0 , edge){
        ll a , b;
        cin>>a>>b;
        graph[b].pb(a);
   }
    
    loop(1 , node + 1) {
        if(!vis[i])
        dfs(i);
    }

    dis[1] = 1;
    par[1] = 0;

    for(auto i : v){
        for(auto j : graph[i]){
            if(dis[i] < dis[j] + 1 && dis[j]){
                dis[i] = dis[j] + 1;
                par[i] = j;
            }
        }
    }

    ll trace = node;
    while(trace != 0){
      ans.pb(trace);
      trace = par[trace];       
    }
    reverse(all(ans));
    if(ans.size() < 2)cout<<"IMPOSSIBLE"<<endl;
    else{
      cout<<ans.size()<<endl;
      loop(0 , ans.size()) cout<<ans[i]<<" ";
    }
}