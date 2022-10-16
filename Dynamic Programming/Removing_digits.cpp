#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define mod 1000000007

using namespace std;

int main(){
    ll n;
    cin>>n;

    vector<ll> dp(n + 1 , 1e9);
    dp[0] = 0;

    for(ll i = 1; i <= n; i++){
        ll temp = i;
        ll mini = 1e9;
        while (temp != 0)
        {
            ll di = temp % 10;
            temp = temp / 10;
            if(di == 0) continue;
            mini = min(mini , dp[i - di] + 1);
        }
        dp[i] = mini;
    }
    cout<<dp[n];
}