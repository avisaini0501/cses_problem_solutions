#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define endl '\n'
#define mod 1000000007
#define pb push_back
#define pii pair<int , int>
#define vc vector
#define vp vector<pair<int , int>>
#define vi vector<int>
#define vii vector<vector<<int>>
#define loop(a , b) for(int i = a; i < b; i++)
#define rep(a , b) for(int i = a; i <= b; i++)
#define all(x) x.begin() , x.end()
#define triplet pair<int , pair<int , int>>
#define goog(tno) cout<<"Case #"<<tno<<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T> , rb_tree_tag, tree_order_statistics_node_update>;

int n;
vi adj[200005];
int dp[200005] , ans[200005];

void dfs1(int s , int p , int dep){
    ans[1] += dep;
    dp[s]  = 1;

    for(auto c : adj[s]){
        if(c != p){
            dfs1(c , s , dep+1);
             dp[s] += dp[c];
        }
    }
}

void dfs2(int s , int p){
    for(auto c : adj[s]){
        if(c != p){
            ans[c] = ans[s] - dp[c] + n - dp[c]; // or ans[s] + n * 2*dp[c]
            dfs2(c , s);
        }
    }
}

int32_t main(){
    fast_io;
    cin>>n;
    
    loop(0 , n - 1){
        int a , b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs1(1 , 0 , 0);
    dfs2(1 , 0);

    loop(1 , n +1){
        cout<<ans[i]<<" ";
    }
}