#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define mod 1000000007
#define nax 1e6 + 10

using namespace std;

int main(){
    string str1 , str2;
    cin>>str1>>str2;
    
    ll len1 , len2;
    len1 = str1.length();
    len2 = str2.length();
    
    vector<vector<ll>> dp(len1 + 1, vector<ll>(len2 + 1, 0));

    for(ll j = 0; j <= len2; j++) dp[0][j] = j;
    for(ll i = 0; i <= len1; i++) dp[i][0] = i; 

    for(ll i = 1; i <= len1; i++){
        for(ll j = 1; j <= len2; j++){
            if(str1[i - 1] == str2[j - 1]) dp[i][j] =  dp[i - 1][j - 1];
            else{
                dp[i][j] = 1 + min(dp[i][j - 1] , min(dp[i - 1][j - 1] , dp[i - 1][j]));
            }
        }
    }
    cout<<dp[len1][len2];
}