#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long 
#define endl '\n'
#define mod 1000000007
#define pb push_back
#define pii pair<int , int>
#define vc vector
#define vp vector<pair<int , int>>
#define vi vector<int>
#define vii vector<vector<<int>>
#define loop(a , b) for(int i = a; i < b; i++)
#define rep(a , b) for(int i = a; i <= b; i++)
#define all(x) x.begin() , x.end()
#define triplet pair<int , pair<int , int>>
#define goog(tno) cout<<"Case #"<<tno<<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T> , rb_tree_tag, tree_order_statistics_node_update>;


int32_t main(){
    fast_io;
    int n , a , b;
    cin>>n>>a>>b;
    double dp[605][105] = {0};
    dp[0][0] = 1.0;
    
    for(int j = 1; j <= n; j++){
        for(int i = 1; i < 601; i++){
            for(int k = 1; k <= 6; k++){
                if(i - k >= 0) dp[i][j] += dp[i - k][j - 1] * (1.0 / 6);
            }
        }
    }                       

    double ans = 0;

    for(int i = a; i <= b; i++) ans += dp[i][n];
    cout<<setprecision(6)<<fixed;
    cout<<ans;
}