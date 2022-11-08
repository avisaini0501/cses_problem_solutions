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
bool vis[200005];
vector<ll>graph[200005];
vector<bool>order(200005);
stack<ll>ans;
bool cyc;

//toposort
void dfs(ll src){
    vis[src] = 1;
    for(auto adj : graph[src]){
        if(!vis[adj]){
            dfs(adj);
        }
    }
    ans.push(src);
}

void cycle(ll src){
    vis[src] = 1;
    order[src] = 1;
    for(auto adj : graph[src]){
        if(!vis[adj]){
           cycle(adj);
        }
        else if(order[adj]){
            if(cyc) return;
            cyc = true;
            return;
        }
    }
    order[src] = 0;
}

int main(){
    cin>>node>>edge;
    loop(0 , edge){
        ll a , b;
        cin>>a>>b;
        graph[a].push_back(b);
    }

    rep(1 , node){
        if(!vis[i]){        
            cycle(i);
        }
    }
    if(cyc == true){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    memset(vis , 0 , sizeof(vis));
    loop(1 , node + 1){
        if(!vis[i]){
            dfs(i);
        }
    }
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    
}