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

ll sx , sy , ex , ey;
ll n , m;
char par[1001][1001];
bool vis[1001][1001];
char ans[1000000];
ll dist[1001][1001];
queue<pair<ll , ll>> q;
ll h[] = {1 , -1 , 0 , 0};
ll v[] = {0 , 0 , 1 , -1};

int main(){
    fast_io;
    cin>>n>>m;

    loop(0 , n){
        for(ll j = 0; j < m; j++){
            char ch;
            cin>>ch;
            if(ch == '#') vis[i][j] = 1;
            else if(ch == 'A'){
                vis[i][j] = 1;
                sx = i;
                sy = j;
            }          
            else if(ch == 'B'){
                ex = i;
                ey = j; 
            } 
        }
    }

    q.push({sx , sy});
    dist[sx][sy] = 0;

    while(!q.empty()){
        auto p = q.front();
        q.pop();

        loop(0 , 4){
            ll dx = p.first + h[i];
            ll dy = p.second + v[i];
            if(dx >= 0 && dx < n && dy >= 0 && dy < m && !vis[dx][dy]){
                if(i == 0) par[dx][dy] = 'D';
                else if(i == 1) par[dx][dy] = 'U';
                else if(i == 2) par[dx][dy] = 'R';
                else par[dx][dy] = 'L';
                dist[dx][dy] = dist[p.first][p.second] + 1;
                vis[dx][dy] = 1;
                q.push({dx , dy});
            }
        }
    }
    if(!vis[ex][ey]){
        cout<<"NO";
        return 0;
    }
    
    cout<<"YES"<<endl;
    cout<<dist[ex][ey]<<endl;

    pair<ll , ll> p = {ex , ey};
    for(ll i = dist[ex][ey]; i > 0; i--){
        ans[i] = par[p.first][p.second];
        if(ans[i] == 'D') p = {p.first - 1 , p.second};
        else if(ans[i] == 'U') p = {p.first + 1 , p.second};
        else if(ans[i] == 'R') p = {p.first, p.second - 1};
        else if(ans[i] == 'L') p = {p.first , p.second + 1};
    }
    rep(1 , dist[ex][ey]) cout<<ans[i];

}    