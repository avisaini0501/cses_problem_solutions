#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define mod 1000000007
#define pb push_back
#define loop(a , b) for(ll i = a; i < b; i++)
#define rep(a , b) for(ll i = a; i <= b; i++)
#define all(x) x.begin() , x.end()
#define triplet pair<ll , pair<ll , ll>>

using namespace std;

int main(){
    ll n , x;
    cin>>n>>x;
    vector<ll>v(n);
    loop(0 , n) cin>>v[i];
    
   ll limit = (1 << n);
   vector<pair<ll,ll>>dp(limit);
   dp[0] = {1 , 0};

   for(ll mask = 1; mask < limit; mask++){
      pair<ll ,ll> best = {INT_MAX , INT_MAX};
        for(ll i = 0; i < n; i++){
        if(((1 << i) & mask) == 0) continue;
        auto  res = dp[((1 << i) ^ mask)];

        if(res.second + v[i] <= x){
            res.second += v[i];
        }
        else{
            res.first +=1;
            res.second = v[i];
        }
        best = min(best , res);
     }
     dp[mask] = best;
   }

   cout<<dp[limit - 1].first;

   return 0;
}