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

ll dp[20][20][2][2];
ll solve(string &num , ll n , ll x , bool lead_zero , bool tight){
    //base case
    if(n == 0) return 1;
    ll low = 0;
    ll high = tight ? (num[num.length() - n] - '0') : 9;
    
    if(x != -1 && dp[n][x][lead_zero][tight] != -1) return dp[n][x][lead_zero][tight];

    ll ans = 0;
    for(ll dig = low; dig <= high; dig++){
        if(dig == x && lead_zero == 0) continue;
        ans += solve(num , n - 1, dig , (lead_zero & dig == 0) , (tight & (dig == high)));
    }
    return dp[n][x][lead_zero][tight] = ans;
}

int main(){
    ll a , b;
    cin>>a>>b;
    
   string A = to_string(a - 1);
   string B = to_string(b);
   
   memset(dp , -1 , sizeof(dp));
   ll ans1 = solve(B , B.length() , -1 , 1 , 1);
   
   memset(dp , -1 , sizeof(dp));
   ll ans2 = solve(A , A.length() , -1 , 1 , 1);
   
   cout<<ans1 - ans2;

   return 0;
}