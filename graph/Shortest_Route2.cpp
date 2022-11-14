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


ll node , edge , q;
ll graph[505][505];

int main(){
    cin>>node>>edge>>q;
    ll inf = 1000000000000;
    loop(1 , node + 1){
        for(ll j = 1; j < node + 1; j++){
            graph[i][j] = inf;
        }
    }
    loop(0 , edge){
        ll x , y , w;
        cin>>x>>y>>w;
        graph[x][x] = 0 , graph[y][y] = 0;

        graph[x][y] = min(graph[x][y] , w);
        graph[y][x] = min(graph[x][y] , w);
    }

    for(ll k = 1; k < node + 1; k++){
        for(ll i = 1; i < node + 1; i++){
            for(ll j = 1; j < node + 1; j++){
                graph[i][j] = min(graph[i][j] , graph[i][k] + graph[k][j]);
            }
        }
    }

    loop(0 , q){
       ll a , b; 
       cin>>a>>b;
       if(graph[a][b] < inf) cout<<graph[a][b]<<endl;
       else cout<<"-1"<<endl;
    }
   
}