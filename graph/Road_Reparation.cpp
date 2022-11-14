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

void join(ll a , ll b){
    if(find(a) == find(b)) return;
    ll x = find(a);
    ll y = find(b);
    if(len[x] > len[y]) swap(x , y);
    len[y] += len[x];
    par[x] = y;
}

int main(){
    fast_io;
    ll n , m;
    cin>>n>>m;
    vc<tuple<ll, ll, ll>> e;
    loop(1 , m + 1){
        ll a , b , w;
        cin>>a>>b>>w;
        e.pb({w , a , b});
    }
    sort(all(e));

    loop(1 , n + 1){
        par[i] = i;
        len[i] = 1;
    }

    ll ans = 0;
    for(auto p : e){
        ll u , v , wt;
        wt = get<0>(p);
        u = get<1>(p);
        v = get<2>(p);

       if(find(u) == find(v)) continue;
       ans += wt;
       join(u , v);
    }

    ll c = 0;
    loop(1 , n + 1) if(par[i] == i) c++;

    if(c == 1) cout<<ans;
    else cout<<"IMPOSSIBLE";
}