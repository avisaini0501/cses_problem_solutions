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
vector<bool>vis(200005);
vector<ll>graph[200005];
vector<bool>order(200005);
vector<ll>res;
bool cycle;

void dfs(ll src , vector<ll>&ans){
    vis[src] = 1;
    order[src] = 1;
    ans.pb(src);
    for(auto adj : graph[src]){
        if(!vis[adj]){
           dfs(adj , ans);
        }
        else if(order[adj]){
            if(cycle) return;
            ans.pb(adj);
            res = ans;
            cycle = true;
            return;
        }
    }
    ans.pop_back();
    order[src] = 0;
}

int main(){
    cin>>node>>edge;
    loop(0 , edge){
        ll a , b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    vector<ll>ans;

    rep(1 , node){
        if(!vis[i]){        
            dfs(i , ans);
        }
    }

    if(cycle == false){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    ll j = 0;
    while(true){
        if(res[j] != res[res.size() - 1])
        j++;
        else break;
    }
    cout<<res.size() - j<<endl;
    loop(j , res.size())
    cout<<res[i]<<" ";
}