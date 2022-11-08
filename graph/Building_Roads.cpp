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
vector<bool>vis(100005 , 0);
vector<ll>graph[100005];
vector<ll>ans;

void dfs(ll src){
   vis[src] = 1;
   for(auto adj: graph[src]){
     if(!vis[adj])
      dfs(adj);
   }
   return;
}

int main(){
  cin>>node>>edge;
  for(ll i = 0; i < edge; i++){
    ll a , b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  
  for(ll i = 1; i <= node; i++){
    if(!vis[i]){
      ans.pb(i);
       dfs(i);
    }
  }
   
 cout<<ans.size() - 1<<endl;
 loop(1 , ans.size())
  cout<<ans[i]<<" "<<ans[i - 1]<<endl;

  return 0; 
}