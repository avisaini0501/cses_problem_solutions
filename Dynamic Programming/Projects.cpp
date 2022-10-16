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

struct project{
    ll s , e , rew;
};

bool cmp(project& p1 ,project& p2){
   return p1.e < p2.e;  
}   

ll findbest(vector<ll>& endpts , ll s){
  auto it = lower_bound(all(endpts) , s) - endpts.begin();
  if(it == 0) return -1;

  else{
    it--;
    return it;
  }
}

int main(){
    ll n;
    cin>>n;
    vector<project> v(n);

    loop(0 , n)
       cin>>v[i].s >> v[i].e >> v[i].rew;
    
    sort(all(v) , cmp);

    vector<ll> dp(n+1 , 0);
    dp[0] = v[0].rew;
    
    vector<ll>endpts;
    
    loop(0 , n)
     endpts.pb(v[i].e);

    for(ll i = 1; i < n; i++){
       ll nottake = dp[i - 1];
       ll take = v[i].rew;
       ll j = findbest(endpts , v[i].s);
       if(j != -1) take += dp[j];
       
       dp[i] = max(take , nottake);
    }    
    cout<<dp[n - 1];
}