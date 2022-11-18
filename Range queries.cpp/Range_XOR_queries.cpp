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

ll arr[200005];
int main(){
    fast_io;
    ll n , q;
    cin>>n>>q;
    arr[0] = 0;
    loop(1 , n + 1){
        ll a;
        cin>>a;
        arr[i] = a ^ arr[i - 1];
    }

    while(q--){
        ll a , b;
        cin>>a>>b;
        cout<<(arr[a - 1]^arr[b])<<endl;
    }
}