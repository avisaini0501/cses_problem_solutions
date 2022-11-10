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

vi graph1[100005] , graph2[100005];
stack<ll> st;
bool vis[100005];

void dfs1(ll src){
    vis[src] = 1;
    for(auto adj : graph1[src]){
        if(!vis[adj]) dfs1(adj);
    }
    st.push(src);
}

void dfs2(ll src){
    vis[src] = 1;
    for(auto adj : graph2[src]){
        if(!vis[adj]) dfs2(adj);
    }
}

int main(){
    fast_io;
    ll n  , m;
    cin>>n>>m;
    loop(0 , m){
       ll a , b;
       cin>>a>>b;
       graph1[a].pb(b);
       graph2[b].pb(a);
    }

    loop(1 , n + 1){
        if(!vis[i]) dfs1(i);
    }

    ll x = st.top();
    memset(vis , 0 , sizeof(vis));
    dfs2(x);
    
    loop(1 , n + 1){
        if(i == x) continue;
        if(!vis[i]){
            cout<<"NO"<<endl;
            cout<<i<<" "<<x;
            return 0;
        }
    }
    cout<<"YES";
}