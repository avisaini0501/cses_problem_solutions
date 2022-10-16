#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define mod 1000000007
#define nax 500 + 1

using namespace std;

int main(){
    ll a , b;
    cin>>a>>b;
    vector<vector<ll>> dp(a + 1 , vector<ll>(b + 1 , 0));
    
    for(ll height = 1; height <= a; height++){
        for(ll width = 1; width <= b; width++){
            if(height == width) continue;

            else{
                ll ans = 1e9;
                for(ll i = 1; i < width; i++)
                ans = min(ans , 1 + dp[height][width - i] + dp[height][i]);
                for(ll i = 1; i < height; i++)
                ans = min(ans ,  1 + dp[height - i][width] + dp[i][width]);

                dp[height][width] = ans;
            }
        }
    }
    cout<<dp[a][b];
}