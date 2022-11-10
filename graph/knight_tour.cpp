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

ll fx[]={-2, -2, -1, -1,  1,  1,  2,  2};
ll fy[]={-1,  1, -2,  2, -2,  2, -1,  1};

ll grid[9][9];

ll deg(ll x1 , ll y1){
    ll s = 0;
    
    loop(0 , 8){
        ll x2 = x1 + fx[i] , y2 = y1 + fy[i];
        if(x2 >= 1 && y2 >= 1 && x2 <= 8 && y2 <= 8 && !grid[x2][y2]) s++;
    }
    return s;
}

bool solve(ll x , ll y , ll move){
    grid[x][y] = move;
   if(move == 64) return 1;
   
   vc<tuple<ll , ll, ll>>v;
   loop(0 , 8){
     ll x1 = x + fx[i] , y1 = y + fy[i];
     if(x1 >= 1 && y1 >= 1 && x1 <= 8 && y1 <= 8 && !grid[x1][y1]){
        ll d = deg(x1 , y1);
        v.pb({d , x1 , y1});
     }
   }
   sort(all(v));
   for(auto t : v){
    ll d = get<0>(t);
    ll x1 = get<1>(t);
    ll x2 = get<2>(t);
     if(solve(x1 , x2 , move + 1)) return 1;
   }
   
   grid[x][y] = 0;
   return 0;
}

int main(){
    fast_io;
    ll x , y;
    cin>>y>>x;

    solve(x , y , 1);

    loop(1 , 9){
        for(ll j = 1; j < 9; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
