#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define mod 1000000007
#define pb push_back
#define pii pair<ll , ll>
#define loop(a , b) for(ll i = a; i < b; i++)
#define rep(a , b) for(ll i = a; i <= b; i++)
#define all(x) x.begin() , x.end()
#define triplet pair<ll , pair<ll , ll>>
#define goog(tno) cout<<"Case #"<<tno<<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll node , q , n , k;

ll dp[200005][31];

int main(){
    fast_io;
    cin>>n>>q;
    loop(1 , n+1){
        cin>>dp[i][0];
    }
    for(ll j = 1; j < 30; j++){
        for(ll i = 1; i < n+1; i++){
           ll par = dp[i][j - 1];
           dp[i][j] = dp[par][j - 1];
        }
    }
    

    while(q--){
        ll x , k;
        cin>>x>>k;
        ll i = 0;
        while(k){
            if(k & 1) x = dp[x][i];
             i++;
             k = k>>1;
        }
        cout<<x<<endl;
    }
}