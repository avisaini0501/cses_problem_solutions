#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
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
/*using namespace __gnu_pbds; */ 
/*template <typename T> using ordered_set = tree<T, null_type, less<T> , rb_tree_tag, tree_order_statistics_node_update>;*/

ll n , q;
char f[1001][1001];
ll bit[1001][1001];

void update(ll x , ll y , ll val){
    for(ll i = x; i <= n; i += i&-i){
        for(ll j = y; j <= n; j += j&-j){
            bit[i][j] += val;
        }
    }
}

ll query(ll x , ll y){
   ll sum = 0;
   for(ll i = x; i > 0; i -= i&-i){
      for(ll j = y; j > 0; j -= j&-j){
         sum += bit[i][j];
      }
   }
   return sum;
}

int main(){
    fast_io;
    cin>>n>>q;

    loop(1 , n + 1){
        for(ll j = 1; j <= n; j++){
            char c;
            cin>>c;
            f[i][j] = c;
            if(f[i][j] == '*')
            update(i , j , 1);
        }
    }

    while(q--){
        ll t;
        cin>>t;
        if(t == 1){
            ll x , y;
            cin>>x>>y;
            if(f[x][y] == '*'){
                update(x , y , -1);
                f[x][y] = '.';
            }
            else{
                update(x , y , 1);
                f[x][y] = '*';
            }
        }
        else{
            ll x1 , y1 , x2 , y2;
            cin>>x1>>y1>>x2>>y2;
            cout<<query(x2 , y2) - query(x2 , y1 - 1) - query(x1 - 1 , y2) + query(x1-1 , y1-1)<<endl;
        }
    }
}