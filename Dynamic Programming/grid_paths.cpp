#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define mod 1000000007

using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<vector<ll>> mat(n , vector<ll>(n , 0));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            char c;
            cin>>c;
            if(c == '*')
              mat[i][j] = -1;
        }
    }
    if(mat[n -1][n - 1] == -1) cout<<"0";
    else{
    vector<vector<ll>> dp(n , vector<ll>(n , 0));
    dp[n - 1][n - 1] = 1;
    
    for(ll i = n - 1; i >= 0; i--){
        for(ll j = n - 1; j >= 0; j--){
            if(mat[i][j] == -1 || (i == n - 1 && j == n - 1))
               continue;

            ll right = 0;
            if(j + 1 <= n - 1)
                right = dp[i][j + 1];
            
            ll down = 0;
            if(i + 1 <= n - 1)
                down = dp[i + 1][j];
            
            dp[i][j] = (right + down) % mod;
        
        }
    }
    cout<<dp[0][0] % mod;
} 
}