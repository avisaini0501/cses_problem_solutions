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

int n , m , k;
int x[101][101] , y[101][101];

void expon(int a[101][101] , int b[101][101]){
    int c[n][n];
    memset(c , 0 , sizeof(c));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = c[i][j];
        }
    }
}

int32_t main(){
    fast_io;
    cin>>n>>m>>k;

    loop(0 , m){
        int a , b;
        cin>>a>>b;
        a-- , b--;
        x[a][b]++;
   }

   for(int i = 0; i < n; i++){
      y[i][i] = 1;
   }

    while(k){
        if(k & 1) expon(y , x);

        expon(x , x);
        k = k >> 1;
    }

    cout<<y[0][n - 1];
}