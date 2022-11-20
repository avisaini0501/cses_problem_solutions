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

int32_t main(){
    fast_io;
    cin>>n>>q;

  
  loop(2 , n + 1){
     cin>>dp[i][0];
  }

   for(int j = 1; j < 30; j++){
     for(int i = 1; i <= n; i++){
         int par = dp[i][j - 1];
         dp[i][j] = dp[par][j - 1];
     }
   }


   while(q--){
     int x , k;
     cin>>x>>k;
      int i = 0;
      while(k){
        if(k & 1)  x = dp[x][i];
         i++;
         k = k>>1;
      }
      (x != 0) ? cout<<x<<endl : cout<<"-1"<<endl;
   }
}
