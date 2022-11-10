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
vector<ll> dis(100005 , 1e18) , dp(100005 , 0) , mini(100005 , 0) , maxi(100005 , 0);
vector<pii>graph[100005];
priority_queue<pii , vector<pii> , greater<pii>>pq;

void dkj(ll src){
    pq.push({0 , 1});
    dis[1] = 0;
    dp[1] = 1;

    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        ll a = p.second , d = p.first;

        if(vis[a]) continue;
        vis[a] = 1;
        for(auto adj : graph[a]){
            if(dis[adj.first] > d + adj.second){
                dis[adj.first] = d + adj.second;
                dp[adj.first] = dp[a];
                mini[adj.first] = mini[a] + 1;
                maxi[adj.first] = maxi[a] + 1;
                pq.push({dis[adj.first] , adj.first});
            }
            else if(dis[adj.first] == d + adj.second){
                dp[adj.first] = (dp[a] + dp[adj.first]) % mod;
                mini[adj.first] = min(mini[adj.first] , mini[a] + 1);
                maxi[adj.first] = max(maxi[adj.first] , maxi[a] + 1);
            }
        }
    }
}

int main(){
  cin>>node>>edge;
  loop(0 , edge){
    ll a , b , c;
    cin>>a>>b>>c;
    graph[a].pb({b , c});
  }

  dkj(1);

  cout<<dis[node]<<" "<<dp[node] % mod<<" "<<mini[node]<<" "<<maxi[node];
}