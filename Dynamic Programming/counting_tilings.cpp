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

void generate_next(int curr , int i , int next_mask , int n , vector<int>& next){
    if(i == n + 1){
        next.pb(next_mask);
        return;
    }

    if((curr & (1 << i)) != 0)
      generate_next(curr , i+1 , next_mask , n , next);

    if(i != n)
        if((curr & (1 << i)) == 0 && (curr & (1 << i + 1)) == 0)
           generate_next(curr , i + 2 , next_mask , n , next);
        if((curr & (1 << i)) == 0)
           generate_next(curr , i + 1 , next_mask + (1 << i) , n , next);
}

int dp[1001][1<<11];
int solve(int col , int mask , const int m , const int n){
    if(col == m + 1){
        if(mask == 0)
          return 1;
        return 0;
    }

    if(dp[col][mask] != -1) return dp[col][mask];

    int ans = 0;
    vector<int>next;
    generate_next(mask , 1 , 0 , n , next); 

    for(int next_mask : next){
         ans = (ans + solve(col + 1 , next_mask , m , n)) % mod;
    }
    return dp[col][mask] = ans;
}

int main(){
    int n , m;
    cin>>n>>m;
    memset(dp , -1 , sizeof(dp));

    cout<<solve(1 , 0 , m , n);
    return 0;
}