#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define mod 1000000007

using namespace std;

vector<ll>dp(10000000 , 0);

//memoization method


/*ll solve(ll tar){
    if(tar < 0) return 0;
    if(tar == 0) return 1;

    if(dp[tar] != -1) return dp[tar];
    
    ll res = 0;
    for(ll i = 6; i >= 1; i--){
      res += solve(tar - i);
    }
    return dp[tar] = res % mod;
}*/

int main(){
    ll target;
    cin>>target;
    
    ll ans = 0;
    dp[0] = dp[1] = 1;
    for(ll tar = 2; tar <= target; tar++){
         for(ll i = 1; i <= 6; i++){
             if(tar < i) break;
                dp[tar] += dp[tar - i];
            
         }
         dp[tar] = dp[tar] % mod;
    }
   cout<<dp[target] % mod;
}
