#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define mod 1000000007
#define pb push_back
#define pii pair<ll , ll>
#define loop(a , b) for(ll i = a; i < b; i++)
#define rep(a , b) for(ll i = a; i <= b; i++)
#define all(x) x.begin() , x.end()
#define triplet pair<ll , pair<ll , ll>>
#define goog(tno) cout<<"Case #"<<tno<<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;


ll node , edge;

int main(){
    cin>>node>>edge;
    vector<tuple<ll ,ll, ll>>e;
    loop(0 , edge){
        ll a , b , c;
        cin>>a>>b>>c;
        e.pb({a , b, c});
    }

    ll dist[node + 1] , par[node + 1] = {0};
    loop(1 , node + 1) dist[i] = 1e18;
    dist[1] = 0;
    ll f;
    loop(1 , node + 1){
        f = 0;
        for(auto t : e){
            ll x = get<0>(t);
            ll y = get<1>(t);
            ll z = get<2>(t);
       
            if(dist[x] + z < dist[y]){
                dist[y] = dist[x] + z;
                    par[y] = x;
                    f = y;
            }
        }
    }
        if(f == 0){
            cout<<"NO";
            return 0;
        }
        else{
            cout<<"YES"<<endl;
            vector<ll>cyc;
            loop(0 , node) f = par[f];

            for(ll x = f; ; x = par[x]){
                cyc.pb(x);
                if(x == f && cyc.size() > 1) break;
            }
            reverse(all(cyc));
            for(auto i : cyc) cout<<i<<" ";
        }
}
