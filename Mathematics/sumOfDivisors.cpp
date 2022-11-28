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

const int mod_inv = 500000004;

int total_sum(int start , int end){
    return ((((end - start + 1) % mod) * ((start + end) % mod) % mod) * mod_inv % mod);
}

int32_t main(){
    fast_io;
    int n;
    cin>>n;

    int total = 0;
    int i = 1;

    while(i <= n){
        int add = n / i;

        int last = n / add;

        total = (total + add * total_sum(i , last)) % mod;
        i = last + 1;
    }
    cout<<total<<endl;
}