#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int unsigned long long 
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
const int INF = 1e19;

void expon(int a[101][101] , int b[101][101]){
    int c[101][101];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            c[i][j] = INF;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(a[i][k] != INF && b[k][j] != INF)
                c[i][j] = min(a[i][k] + b[k][j] , c[i][j]);
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

     for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            x[i][j] = y[i][j] = INF;
            y[i][i] = 0;
    }

    loop(0 , m){
        int a , b , c;
        cin>>a>>b>>c;
        a-- , b--;
        x[a][b] = min(x[a][b] , c);
   }

    while(k){
        if(k & 1) expon(y , x);

        expon(x , x);
        k = k >> 1;
    }
    
    if(y[0][n - 1] >= INF) cout<<"-1";
    else cout<<y[0][n - 1];
}