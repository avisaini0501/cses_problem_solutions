#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define mod 1000000007
#define pb push_back
#define pii pair<ll , ll>
#define vc vector
#define vp vector<pair<ll , ll>>
#define vi vector<ll>
#define vii vector<vector<<ll>>
#define loop(a , b) for(ll i = a; i < b; i++)
#define rep(a , b) for(ll i = a; i <= b; i++)
#define all(x) x.begin() , x.end()
#define triplet pair<ll , pair<ll , ll>>
#define goog(tno) cout<<"Case #"<<tno<<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
ll n , q;
ll dp[1005][1005];

int main(){
    fast_io;
    cin>>n>>q;

    loop(1 , n + 1){
        for(ll j = 1; j <= n; j++){
            char x; cin>>x;
            dp[i][j] = (dp[i-1][j] - dp[i - 1][j - 1]) + dp[i][j - 1] + (x == '*');
        }
    }

    while(q--){
        ll x1 , y1 , x2 , y2;
        cin>>y1>>x1>>y2>>x2;
        cout<<(dp[y2][x2] + dp[y1-1][x1-1] - dp[y2][x1-1] - dp[y1 - 1][x2])<<endl;
    }
}