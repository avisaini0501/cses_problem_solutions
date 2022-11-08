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

bool vis[100005];
ll node , edge;
priority_queue<pii , vector<pii> , greater<pii>> pq;

void dij(ll src , vector<ll>&dis ,vector<pii>graph[]){
    pq.push({0 , src});
    dis[src] = 0;
    memset(vis , 0 , sizeof(vis));
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        ll a = p.second , dist = p.first;
        if(vis[a]) continue;
        vis[a] = 1;
        for(auto e : graph[a]){
           if(dis[e.first] > dist + e.second){
               dis[e.first] = dist + e.second;
               pq.push({dis[e.first], e.first});
           }
        }
    }
}

int main(){
    cin>>node>>edge;
    vector<tuple<ll ,ll ,ll>> e;
    vector<pii>graph1[node + 1] , graph2[node + 1];
    vector<ll>dis1(node + 1 , 1e18) , dis2(node+1 , 1e18);
    loop(0 , edge){
        ll a , b , c;
        cin>>a>>b>>c;
        e.pb({a , b , c});
        graph1[a].pb({b , c});
        graph2[b].pb({a , c});
    }


    dij(1 , dis1 , graph1);
    dij(node , dis2, graph2);

    ll ans = 1e18;
    for(auto t : e){
        ll x = get<0>(t);
        ll y = get<1>(t);
        ll z = get<2>(t);

        ans = min(ans , dis1[x] + dis2[y] + z / 2);
    }
    cout<<ans;
}