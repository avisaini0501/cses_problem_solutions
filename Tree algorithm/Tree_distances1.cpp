#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define endl '\n'
#define mod 1000000007
#define pb push_back
#define pii pair<int , int>
#define vc vector
#define vp vector<pair<int , int>>
#define vi vector<int>
#define vii vector<vector<<int>>
#define loop(a , b) for(int i = a; i < b; i++)
#define rep(a , b) for(int i = a; i <= b; i++)
#define all(x) x.begin() , x.end()
#define triplet pair<int , pair<int , int>>
#define goog(tno) cout<<"Case #"<<tno<<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T> , rb_tree_tag, tree_order_statistics_node_update>;

int dep[200005];
vi adj[200005];
int ans[200005];
int n;

void dfs(int s , int p){
    for(auto c : adj[s]){
        if(c != p){
            dfs(c , s);
            dep[s] = max(dep[s] , dep[c] + 1);
        }
    }
}

void dfs2(int s , int p , int par_ans){
    vi prefMax , suffMax;

    for(auto c : adj[s]){
        if(c != p){
         prefMax.pb(dep[c]);
         suffMax.pb(dep[c]);
        } 
    }

    for(int i = 1; i < prefMax.size(); i++){
        prefMax[i] = max(prefMax[i] , prefMax[i - 1]);
    }

    for(int i = (int)suffMax.size() - 2; i >= 0; i--){
        suffMax[i] = max(suffMax[i] , suffMax[i + 1]);
    }

    int c_no = 0;
    for(int c : adj[s]){
        if(c != p){
            int op1 = (c_no == 0) ? -1e9 : prefMax[c_no - 1];
            int op2 = (c_no == (int)suffMax.size() - 1) ? -1e9 : suffMax[c_no + 1];
            int parti_ans = 1 + max(par_ans , max(op1 , op2));

            dfs2(c , s , parti_ans);
            c_no++;
        }
    }
    ans[s] = 1 + max(par_ans , (prefMax.empty() ? -1 : prefMax.back()));
}

int32_t main(){
  fast_io;
  cin>>n;
  loop(0 , n - 1){
    int a , b;
    cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  
  dfs(1 , 0);
  dfs2(1 , 0 , -1);
  
  loop(1 , n + 1){
    cout<<ans[i]<<" ";
  }
}