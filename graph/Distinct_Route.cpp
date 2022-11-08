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
ll graph[501][501] , ograph[501][501];

bool reach(){
    memset(vis , 0 , sizeof(vis));
    queue<ll> q;
    q.push(1); vis[1] = 1;

    while(!q.empty()){
        ll i = q.front(); q.pop();

        for(ll j = 1; j <= n; j++){
            if(graph[i][j] && !vis[j]){
                vis[j] = 1; 
                path[j] = i;
                q.push(j); 
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
        graph[a][b] = 1;
        ograph[a][b] = 1;
    }  

    ll u , v;
    ll maxflow = 0;

    while(reach()){
      ll flow = 1e18;
      for(v = n; v != 1; v = path[v]){
          u = path[v];
        flow = min(flow , graph[u][v]);
      }

      maxflow += flow;

      for(v = n; v != 1; v = path[v]){
        u = path[v];
        graph[u][v] -= flow;
        graph[v][u] += flow;
      }
    }

    cout<<maxflow<<endl;
   
    vi ans;
    memset(vis , 0, sizeof(vis));
    while(maxflow--){
        ans.clear();
        vis[n] = 0;
      ll i = 1;
      vis[1] = 1;
      ans.pb(1);
      while(i != n){
        for(ll j = 1; j <= n; j++){
            if(graph[i][j] == 0 && ograph[i][j] == 1 && !vis[j]){
                ans.pb(j);
                i = j;
                vis[j] = 1;
                break;
            }
        }
      }

        cout<<ans.size()<<endl;
        loop(0 , ans.size())
          cout<<ans[i]<<" ";
      
        cout<<endl;
    }
    
}