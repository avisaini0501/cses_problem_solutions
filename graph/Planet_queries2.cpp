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

ll dp[200005][21];
ll len[200005];
bool vis[200005];

void dfs(ll src){
    vis[src] = 1;
    
      if(!vis[dp[src][0]])
      dfs(dp[src][0]);
    
    len[src] = len[dp[src][0]] + 1;
}

ll lift(ll x , ll k){
    if(k <= 0) return x;
    ll i = 0;
    
    while(k){
       if(k & 1) x = dp[x][i];
       i++;
       k = k>>1;
    }
    
    return x;
}

int main(){
    fast_io;
    ll n , q;
    cin>>n>>q;
    loop(1 , n + 1){
        cin>>dp[i][0];
    }
    for(ll j = 1; j <= 20; j++){
        for(ll i = 1; i < n + 1; i++){
            ll adj = dp[i][j - 1];
            dp[i][j] = dp[adj][j - 1];
        }
    }

    loop(1 , n + 1){
        if(!vis[i])
          dfs(i);
    }

    while(q--){
        ll x , y;
        cin>>x>>y;

        ll xx = lift(x , len[x]);

        if(lift(x , len[x] - len[y]) == y)
          cout<<len[x] - len[y]<<endl;
        else if(lift(xx , len[xx] - len[y]) == y)
           cout<<len[x] + len[xx] - len[y]<<endl;
        else 
           cout<<"-1"<<endl;     
    }
}