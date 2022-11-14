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

vp graph[100005];
bool vis[200005];

int main(){
    fast_io;
    ll n , m;
    cin>>n>>m;
    
    loop(0 , m){
        ll a , b;
        cin>>a>>b;
        graph[a].pb({b , i});
        graph[b].pb({a , i});
    }
    

    loop(1 , n + 1){
        if(graph[i].size() % 2 == 1){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }

    stack<ll>st;
    st.push(1);
    vi path;
    
    while(!st.empty()){
        ll x = st.top();
        ll f = 0;
        
        while(!graph[x].empty()){
            auto p = graph[x].back();
            ll i = p.second;
            ll y = p.first;
            graph[x].pop_back();
            
            if(!vis[i]){
                st.push(y);
                vis[i] = 1;
                f = 1;
                break;
            }        
        }
        if(f == 0){
            path.pb(x);
            st.pop(); 
        }
    }

    if(path.size() != m + 1) {
        cout<<"IMPOSSIBLE";
        return 0;
    }

    loop(0 , path.size()) cout<<path[i]<<" ";
}