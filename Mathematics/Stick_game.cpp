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

int result[10000005] = {0};

int32_t main(){
    fast_io;
    int n , k;
    cin>>n>>k;

    int move[k + 1];
    loop(1 , k + 1) 
        cin>>move[i];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
           if(i - move[j] >= 0){
              if(result[i - move[j]] == 0) result[i] = 1;
           }
        } 
        if(result[i]) cout<<"W";
        else cout<<"L";
    }
}