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

int n;
int x[2][2] , y[2][2];

void solve(int a[2][2] , int b[2][2]){
    int c[2][2];
    memset(c , 0 , sizeof(c));

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            a[i][j] = c[i][j];
        }
    }
}

int32_t main(){
   fast_io;
   cin>>n;

   x[0][1] = x[1][0] = x[1][1] = y[0][0] = 1;

   while(n){
    if(n & 1) solve(y , x);

    solve(x , x);
    n >>= 1;                                      
   }

   cout<<y[0][1];
}