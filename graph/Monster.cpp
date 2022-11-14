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

ll fx[] = {-1 , 1 , 0 , 0};
ll fy[] = {0 , 0 , 1 , -1};
char go[] = {'U' , 'D' , 'R' , 'L'};
ll nex[1005][1005];

int main(){
 ll n , m;
 cin>>n>>m;
 vector<string> grid(n);
 
 for(auto &i : grid)
  cin>>i;

  queue<pii> q;
  ll sx , sy;

  loop(0 , n){
    for(ll j = 0; j < m; j++){
        if(grid[i][j] == 'M')
          q.push({i , j});
        else if(grid[i][j] == 'A'){
            sx = i , sy = j;
        }
    }
  }
  q.push({sx , sy});
  nex[sx][sy] = -1;

  while(!q.empty()){
    pii p = q.front();
    ll x = p.first;
    ll y = p.second;
    q.pop();
    if(grid[x][y] == 'A' && (x == 0 || x == n - 1 || y == 0 || y == m - 1)){
        cout<<"YES"<<endl;
        string ans;
        ll d = nex[x][y];
        while(d != -1){
            ans += go[d];
            x -= fx[d];
            y -= fy[d];
            d = nex[x][y];
        }
        reverse(all(ans));
        cout<<ans.size()<<endl;
        cout<<ans;
        return 0;
    }
    for(ll i = 0; i < 4; i++){
        ll xx = x + fx[i];
        ll yy = y + fy[i];
        if(xx < 0 || xx >= n || yy < 0 || y >= m || grid[xx][yy] != '.') continue;
        else{
            grid[xx][yy] = grid[x][y];
            if(grid[xx][yy] == 'A') nex[xx][yy] = i;
            q.push({xx , yy});
        }
    }
  }
  cout<<"NO";
}