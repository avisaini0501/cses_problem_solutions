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
vector<ll>graph[100005];
vector<ll>team(100005);
bool cycle;

void dfs(ll src ,ll t){
    vis[src] = 1;
    for(auto adj : graph[src]){
        if(!vis[adj]){
            team[adj] = t;
            dfs(adj , 3 -  team[adj]);
        }
        else if(vis[adj] && team[adj] == team[src]){
            cycle = true;
            return;
        }
    }
}
int main(){
    cin>>node>>edge;
    loop(0 , edge){
        ll a , b;
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    ll count = 0;
    loop(1 , node + 1){
        if(!vis[i]){
            team[i] = 1;
            count++;
            dfs(i , 3 - team[i]);
        }
    }

    if(cycle == true){
        cout<<"IMPOSSIBLE";
        return 0;
    }
        rep(1 , node)
        cout<<team[i]<<" ";
    
}