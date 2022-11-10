#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define mod 1000000007
#define pb push_back
#define pii pair<ll , ll>
#define vc vector
#define vi vector<ll>
#define vii vector<vector<<ll>>
#define loop(a , b) for(ll i = a; i < b; i++)
#define rep(a , b) for(ll i = a; i <= b; i++)
#define all(x) x.begin() , x.end()
#define triplet pair<ll , pair<ll , ll>>
#define goog(tno) cout<<"Case #"<<tno<<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll ans[200005];
vi graph1[200005] , graph2[200005];
bool vis[200005];
stack<ll>order;
ll comp[200005];
ll k;

void dfs1(ll src){
    vis[src] = 1;
    for(auto adj : graph1[src]){
        if(!vis[adj]) dfs1(adj);
    }
    order.push(src);
}

void dfs2(ll src){
    vis[src] = 1;
    comp[src] = k;
    for(auto adj : graph2[src]){
        if(!vis[adj])
         dfs2(adj);
    }
}

int main(){
    fast_io;
    ll n , m;
    cin>>n>>m;
    //2-SAT
    loop(0 , n){
        ll a , b;
        char x , y;
        cin>>x>>a>>y>>b;
        if (x=='-') a=2*m-a+1;
        if (y=='-') b=2*m-b+1;
        graph1[2*m-a+1].pb(b), graph1[2*m-b+1].pb(a);
        graph2[a].pb(2*m-b+1), graph2[b].pb(2*m-a+1);
    }

    loop(1 , 2*m+1){
        if(!vis[i]) dfs1(i);
    }

    k = 0;
    memset(vis, 0 , sizeof(vis));
    while(!order.empty()){
        ll x = order.top();
        order.pop();
        if(!vis[x]){
            k++;
            dfs2(x);
        }
    }

    loop(1 , m + 1){
        if(comp[i] == comp[2*m-i+1]){
            cout<<"IMPOSSIBLE";
            return 0;
        }
        if(comp[i] > comp[2*m-i+1])
        ans[i] = 1;
        else ans[i] = 0;
    }

    loop(1 , m + 1){
        if(ans[i]) cout<<'+'<<" ";
        else cout<<'-'<<" ";
    }
}