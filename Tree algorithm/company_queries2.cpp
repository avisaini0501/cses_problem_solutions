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

int n , q;
int dp[200005][31];
int level[200005];
vi adj[200005];

void dfs(int s , int p , int t){
    level[s] = t;

    for(auto c : adj[s]){
        if(c != p){
            dfs(c , s , t + 1);
        }
    }
}

int32_t main(){
    fast_io;
    cin>>n>>q;

  
  loop(2 , n + 1){
    int a;
    cin>>a;
    adj[a].pb(i);
    dp[i][0] = a;
  }

   for(int j = 1; j < 30; j++){
     for(int i = 1; i <= n; i++){
         int par = dp[i][j - 1];
         dp[i][j] = dp[par][j - 1];
     }
   }

   for(int i = 1; i <= n; i++){
     for(int j = 0; j < 21; j++){
        cout<<dp[i][j]<<" ";
     }
     cout<<endl;
   }

   dfs(1 , 0 , 0);


   while(q--){
     int x , y,  k;
     cin>>x>>y;

     if(level[x] > level[y]) swap(x , y);
       
       k = level[y] - level[x];
       
       int i = 0;
       while(k){
          if(k & 1) y = dp[y][i];

          i++;
          k = k>>1;
       }
       
       if(x == y) cout<<x<<endl;

       else{
          for(int i = 20; i >= 0; i--){
             if(dp[x][i] != dp[y][i]){
                x = dp[x][i];
                y = dp[y][i];
             }
          }

          cout<<dp[x][0]<<endl;
       }
    }
}