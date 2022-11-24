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

int n , q;
vi adj[200005];
int in[200005];
int out[200005];
int value[200005];
int visit[2 * 200005];
int timer = 1;

void dfs(int s , int p){
    visit[timer] = value[s];
    in[s] = timer;
    timer++;

    for(auto c : adj[s]){
        if(c != p){
            dfs(c , s);
        }
    }
    visit[timer] = value[s];
    out[s] = timer;
    timer++;
}

void build(int ind , int low , int high , int seg[]){
    if(low == high){
        seg[ind] = visit[low];
        return;
    }

    int mid = (low + high) >> 1;
    build(2 * ind , low , mid , seg);
    build(2 * ind + 1 , mid+1 , high , seg);
    seg[ind] = (seg[2 * ind] + seg[2 * ind + 1]);
}

void update(int ind , int low , int high, int i, int val, int seg[]){
    if(low == high){
        seg[ind] = val;
        return;
    }
    
    int mid = (low + high) >> 1;
    if(i <= mid) update(2*ind, low , mid , i , val,  seg);
    else update(2*ind+1, mid+1, high, i , val , seg);
    seg[ind] = (seg[2*ind] + seg[2*ind+1]);
}

int query(int ind , int low, int high, int l , int r, int seg[]){
    //no overlap
    if(l > high || r < low) return 0;

    //complete overlap 
    if(low >= l && high <= r) return seg[ind];

    //partial overlap
    int mid = (low + high) >> 1;
    int left = query(2*ind , low , mid , l , r , seg);
    int right = query(2*ind+1 , mid + 1 , high, l , r, seg);
    return (left+right);
}

int32_t main(){
    fast_io;
    cin>>n>>q;
    
    loop(1 , n + 1){
        cin>>value[i];
    }

    loop(2 , n + 1){
        int a , b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1 , 0);

    int seg[200005 * 8];
    build(1 , 1 , 2 * n, seg);

    while(q--){
        int t;
        cin>>t;

        if(t == 1){
            int s , val;
            cin>>s>>val;
            int ind1 = in[s];
            int ind2 = out[s];
            visit[ind1] = val;
            visit[ind2] = val;
            update(1 , 1 , 2 * n, ind1 , val, seg);
            update(1 , 1 , 2 * n, ind2 , val , seg);
        }

        else{
            int s;
            cin>>s;
            int l = in[s];
            int r = out[s];
            int ans = query(1 , 1 , 2 * n, l , r, seg);
            cout<<ans / 2<<endl;
        }
    }   
}