#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define mod 1000000007
#define nax 1e6 + 10

using namespace std;

int main(){
        vector<vector<ll>> dp(nax , vector<ll>(2 , 0));
        dp[1][0] = dp[1][1] = 1;

        for(ll i = 2; i < 1e6 + 10; i++){
            ll op1 = (dp[i - 1][0] + dp[i - 1][1]) % mod;     //extent none
            ll op2 = dp[i - 1][0] % mod;                      //extend both for 0
            ll op3 = (2 * dp[i - 1][0]) % mod;                //extend one of them
            ll op4 = dp[i - 1][1] % mod;                      //extend both for 1

            dp[i][0] = (op1 + op2 + op3) % mod;
            dp[i][1] = (op1 + op4) % mod;
        }
        ll t;
        cin>>t;
        while(t--){
            ll n;
            cin>>n;
            cout<<(dp[n][0] + dp[n][1]) % mod<<endl;
        }
        
    }
