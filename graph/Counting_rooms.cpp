#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define mod 1000000007
#define pb push_back
#define loop(a , b) for(ll i = a; i < b; i++)
#define rep(a , b) for(ll i = a; i <= b; i++)
#define all(x) x.begin() , x.end()
#define triplet pair<ll , pair<ll , ll>>
#define goog(tno) cout<<"Case #"<<tno<<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll n , m;
ll vis[1001][1001];
ll h[] = {1 , -1 , 0 , 0};
ll v[] = {0 , 0 , 1 , -1};

void dfs(ll x , ll y){
    vis[x][y] = 1;
     loop(0 , 4){
        ll dx = x + h[i] , dy = y + v[i];
         if(dx >= 0 && dx < n && dy >= 0 && dy < m && !vis[dx][dy])
           dfs(dx , dy);
     }
}
int main(){
    cin>>n>>m;

    loop(0 , n){
       for(ll j = 0; j < m; j++){
            char ch;
            cin>>ch;
            if(ch == '.') vis[i][j] = 0;
            else vis[i][j] = 1;
        }
    }
    
    ll count = 0;
    loop(0 , n){
        for(ll j = 0; j < m; j++){
            if(!vis[i][j]){
               dfs(i , j);
                count++;
            }    
        }
    }
    cout<<count;    
}
