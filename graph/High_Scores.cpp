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

ll dis[2505];
ll inf = 1e16;
vector<ll>graph1[2505] , graph2[2505];
bool vis1[2505] , vis2[2505];

void dfs1(ll src){
    vis1[src] = 1;
    for(auto adj : graph1[src]){
        if(!vis1[adj]) dfs1(adj);
    }
}

void dfs2(ll src){
    vis2[src] = 1;
    for(auto adj : graph2[src]){
        if(!vis2[adj]) dfs2(adj);
    }
}

int main(){
    ll n , m;
    cin>>n>>m;
    loop(1 , n + 1) dis[i] = inf;

    dis[1] = 0;
    vector<tuple<ll ,ll ,ll>> e;
    
    loop(0 , m){
        ll a , b , c;
        cin>>a>>b>>c;
        e.pb({a, b , -c});
        graph1[a].pb(b);
        graph2[b].pb(a);
    }

    dfs1(1);
    dfs2(n);

    loop(0 , n){
       for(auto t : e){
           ll a = get<0>(t);
           ll b = get<1>(t);
           ll w = get<2>(t);

           if(dis[a] + w < dis[b]){
             dis[b] = dis[a] + w;
             if(i == n - 1 && vis1[b] && vis2[b]){
                cout<<"-1";
                return 0;
             }
           }
       }        
    }

    cout<<-dis[n];
}