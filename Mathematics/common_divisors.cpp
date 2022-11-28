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
int pres[1000001];

int32_t main(){
    fast_io;
    cin>>n;

    loop(0 , n){
        int x;
        cin>>x;
        pres[x]++;
    }

    for(int gcd = 1e6; gcd > 0; gcd--){
        int c = 0;
        for(int j = gcd; j <= 1e6; j += gcd){
             c += pres[j];
        }
        if(c >= 2){
            cout<<gcd;
            break;
        }
    }
}