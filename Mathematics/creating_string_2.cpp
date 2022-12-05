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

int fact[1000001];
int inv_fact[1000001];
int a[26];

int inverse(int x ,int m){
    if(m == 0) return 1;

    int res = inverse(x , m / 2);
    if(m % 2){
        return (((res * res) % mod) * x) % mod;
    }
    else{
        return (res * res) % mod;
    }
}


void find_fact(){
    for(int i = 1; i < 1000001; i++){
        fact[i] = (i * fact[i - 1]) % mod;
        inv_fact[i] = inverse(fact[i] , mod - 2);
    }
}

int32_t main(){
    fast_io;
    string s;
    cin>>s;

    loop(0 , s.length()){
        a[s[i] - 'a']++;
    }


    fact[0] = inv_fact[0] = 1;
    find_fact();

    int ans = fact[s.length()];
    loop(0 , 26){
        ans *= inv_fact[a[i]];
        ans %= mod;
    }
    cout<<ans;

}