#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define mod 1000000007
#define pb push_back
#define pii pair<ll , ll>
#define vc vector
#define vi vector<ll>
#define vii vector<vector<<ll>>
#define loop(a , b) for(ll i = a; i < b; i++)
#define rep(a , b) for(ll i = a; i <= b; i++)
#define all(x) x.begin() , x.end()
#define triplet pair<ll , pair<ll , ll>>
#define goog(tno) cout<<"Case #"<<tno<<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll par[200005] , len[200005];

ll find(ll a){
    while(a != par[a]) a = par[a];
    return a;
}

int main(){
    fast_io;
    ll n , m;
    cin>>n>>m;
    loop(1 , n + 1){
        par[i] = i;
        len[i] = 1;
    }
    ll maxi = 1;
    ll com = n;

    loop(1 , m + 1){
        ll a , b;
        cin>>a>>b;
        if(find(a) != find(b)){
          ll x = find(a);
          ll y = find(b);

         if(len[x] > len[y]) swap(x , y);
          len[y] += len[x];
          par[x] = y;
          com--;
          maxi = max(maxi , len[y]);
        }
        cout<<com<<" "<<maxi<<endl;

    } 
}