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
vector<ll>dist(100005 , 1e9 * 100005 + 1);
vector<pii>graph[100005];
vector<bool> vis(100005);
priority_queue<pii , vector<pii> , greater<pii>> pq;

int main(){
    cin>>node>>edge;
    loop(0 , edge){
        ll a , b , c;
        cin>>a>>b>>c;
        graph[a].pb({b , c});
    }

    pq.push({0 , 1});
    dist[1] = 0;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        ll b = p.second , dis = p.first;
        if(vis[b]) continue;
        vis[b] = 1;
        
        for(pii adj : graph[b]){
           if(dis + adj.second < dist[adj.first]){
            dist[adj.first] = dis + adj.second;
            pq.push({dist[adj.first] , adj.first});
           }
        }
    }
   loop(1 , node + 1) cout<<dist[i]<<" ";
}