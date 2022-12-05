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

long double dp[65][65][101] = {0};

int dir(int x , int y){
    int c = 0;
    if(x + 1 < 8) c++;
    if(y + 1 < 8) c++;
    if(x - 1 >= 0) c++;
    if(y - 1 >= 0) c++;
    return c;
}

int32_t main(){
    fast_io;
   loop(0 , 64) dp[i][i][0] = 1;
   int k;
   cin>>k;

   for(int i = 1; i <= k; i++){
      for(int x = 0; x < 64; x++){
        for(int y = 0; y < 64; y++){
            int a = x/8 , b = x%8;
            long double p = 0;
             if(a+1 < 8)  p += 1.0 / dir(a+1 , b) * dp[a * 8 + 8 + b][y][i - 1];

            if(b + 1 < 8) p += 1.0 / dir(a , b + 1) * dp[a*8 + b + 1][y][i - 1];
            
            if(a - 1 >= 0) p += 1.0 / dir(a - 1 , b) * dp[a*8 - 8 + b][y][i - 1];

            if(b - 1 >= 0) p += 1.0 / dir(a , b - 1) * dp[a*8 + b - 1][y][i - 1];

            dp[x][y][i] = p;
        }
      }
   }

   long double ans = 0;

   for(int x = 0; x < 64; x++){
      long double t = 1;
       for(int y = 0; y < 64; y++){
          t *= (1 - dp[x][y][k]);
       }

       ans += t;
   }
   cout<<setprecision(6)<<fixed;
   cout<<ans;
}