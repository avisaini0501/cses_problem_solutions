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


int cur = 1, n, q;
vector<int> ver;
const int mxN = 2e5;
struct node {
    int left, right, sum;
} seg[mxN*40];

void update(int &root, int idx, int val, int l = 0, int h = n-1) {
    seg[cur].left = seg[root].left;
    seg[cur].right = seg[root].right;
    seg[cur].sum = seg[root].sum + val;
    root = cur; 
    cur++;
    int mid = (l+h)/2;
    if (l == h)
        return;
    if (idx <= mid)
        update(seg[root].left, idx, val, l, mid);
    else
        update(seg[root].right, idx, val, mid+1, h);
}

int query(int root, int a, int b, int l = 0, int h = n-1) {
    if (a<=l && h<=b)
        return seg[root].sum;
    int mid = (l+h)/2;
    return (a<=mid?query(seg[root].left, a, b, l, mid):0) +
           (mid<b?query(seg[root].right, a, b, mid+1, h):0);
}
int32_t main(){
    fast_io;
    cin>>n>>q;
    ver.push_back(0);
    for (int i = 0; i < n; i++) {
        int x; cin>>x;
        update(ver[0], i, x);
    }
    while(q--) {
        int ch; cin>>ch;
        if (ch == 1) {
            int k, a, x; cin>>k>>a>>x;
            k--, a--;
            update(ver[k], a, x - query(ver[k], a, a));
        }
        else if (ch == 2) {
            int k, a, b; cin>>k>>a>>b;
            k--, a--, b--;
            cout<<query(ver[k], a, b)<<endl;
        }
        else {
            int k; cin>>k;
            ver.push_back(ver[k-1]);
        }
    }

}