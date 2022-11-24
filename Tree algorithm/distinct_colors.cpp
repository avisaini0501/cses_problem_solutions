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


vi adj[200005];
int col[200005];
int ans[200005];
int n;

set<int> dfs(int s , int p){
    set<int> uniq;
    uniq.insert(col[s]);

    for(auto c : adj[s]){
        if(c != p){
            set<int> child = dfs(c , s);
            if(child.size() > uniq.size()) swap(child , uniq);
            
            for(auto color : child){
                uniq.insert(color);
            }
        }
    }
    ans[s] = uniq.size();
    return uniq;
}

int32_t main(){
    fast_io;
    cin>>n;

    loop(1 , n + 1){
        cin>>col[i];
    }

    loop(2 , n + 1){
        int a , b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1 , 0);

    loop(1 , n + 1){
        cout<<ans[i]<<" ";
    }
}