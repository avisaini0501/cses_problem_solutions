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

ll node , edge , k;
vector<ll>vis(100005 , 0);
vector<pii>graph[100005];
priority_queue<pii , vector<pii> , greater<pii>>pq;

void djk(ll src){
    pq.push({0 , src});
    while(!pq.empty() && vis[node] < k){
        auto p = pq.top();
        pq.pop();
        ll a = p.second , b = p.first;
        vis[a]++;
        if(a == node) cout<<b<<" ";
        if(vis[a] <= k)
         for(auto adj : graph[a]){
            pq.push({adj.second + b , adj.first});
        }
    }
}

int main(){
    cin>>node>>edge>>k;
    loop(0 , edge){
        ll a , b , c;
        cin>>a>>b>>c;
        graph[a].pb({b , c});
    }
    djk(1);
}