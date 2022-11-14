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

vi adj1[100005] , adj2[100005];
ll vis[100005];
stack<ll> st;

void dfs1(ll src){
    vis[src] = 1;
    for(auto i : adj1[src]){
        if(!vis[i]) dfs1(i);
    }
     st.push(src);
}

void dfs2(ll src , ll k){
    vis[src] = k;
    for(auto i : adj2[src]){
        if(!vis[i]) dfs2(i , k);
    }
}

int main(){
    fast_io;
    ll n , m;
    cin>>n>>m;
    
    loop(1 , m + 1){
        ll a , b;
        cin>>a>>b;
        adj1[a].pb(b);
        adj2[b].pb(a);
    }

    loop(1 , n + 1){
        if(!vis[i]){
            dfs1(i);
        }
    }

    memset(vis , 0 , sizeof(vis));
    ll k = 0;
    while(!st.empty()){
        ll x = st.top();
        st.pop();
        if(!vis[x]){
            k++;
            dfs2(x , k);
        }
    }

    cout<<k<<endl;
    loop(1 , n + 1){
        cout<<vis[i]<<" ";
    }
}