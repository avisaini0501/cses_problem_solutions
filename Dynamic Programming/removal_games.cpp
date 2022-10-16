#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define mod 1000000007
#define nax 500 + 1

using namespace std;

int main(){
    ll n;
    cin>>n;

    vector<ll>v(n);
    for(ll i = 0; i < n; i++)
    cin>>v[i];

    vector<vector<ll>> dp(n , vector<ll>(n , 0));

    for(ll len = 1; len <= n; len++){
        for(ll i = 0; i + len <= n; i++){
           ll j = i + len - 1;
           ll x = 0 , y = 0 , z = 0;

           if(i + 2 <= j)
           x = dp[i + 2][j];
           if(i + 1 <= j - 1)
           y = dp[i + 1][j - 1];
           if(i <= j - 2)
           z = dp[i][j - 2];

           dp[i][j] = max(v[i] + min(x , y) , v[j] + min(y , z));
        }
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[0][n - 1];
}