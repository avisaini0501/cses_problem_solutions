#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, q, arr[200002], a, b, c;
struct LAZY
{
    int d, a1;
} lazy[800000];
int tree[800000];
void propagate(int root, int s, int e)
{
    if (lazy[root].a1 != 0)
    {
        int width = (e - s + 1);
        tree[root] += (width * (width - 1) * lazy[root].d / 2);
        int rem = (width * lazy[root].a1);
        tree[root] += rem;
 
        int mid = (s + e) / 2;
        if (s != e)
        {
            lazy[2 * root + 1].a1 += lazy[root].a1;
            lazy[2 * root + 2].a1 += (lazy[root].a1 + (mid - s + 1) * lazy[root].d);
            lazy[2 * root + 1].d += lazy[root].d;
            lazy[2 * root + 2].d += lazy[root].d;
        }
        lazy[root] = {0, 0};
    }
}
void build(int ind, int l, int r)
{
    if(l == r)
    {
        tree[ind] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(ind * 2 + 1, l, mid);
    build(ind * 2 + 2, mid + 1, r);
    tree[ind] = (tree[ind * 2 + 1] + tree[ind * 2 + 2]);
    //cout<<l<<" "<<r<<" "<<tree[ind]<<endl;
}
int sum(int d, int a1, int n)
{
    return (2 * a1 + (n - 1) * d) * n / 2;
}
void update(int ind, int l, int r, int low, int high)
{
    propagate(ind, low, high);
    if(low > r || high < l) return;
    if(low >= l && high <= r)
    {
        //cout<<"Before ["<<curL<<" "<<curR<<"] = "<<tree[ind]<<endl;
        int mid = (low + high) / 2;
        int w = high - low + 1;
        int lft = low - l + 1;
        int rgt = high - l + 1;
        tree[ind] += (rgt * (rgt + 1) / 2);
        tree[ind] -= (lft * (lft - 1) / 2);
        int rgtStart = lft + (mid - low + 1);
        //cout<<"["<<curL<<" "<<curR<<"] = "<<tree[ind]<<endl;
        if(low != high)
        {
            lazy[ind * 2 + 1].a1 += lft;
            lazy[ind * 2 + 1].d ++;
            lazy[ind * 2 + 2].a1 += rgtStart;
            lazy[ind * 2 + 2].d ++;
        }
        return;
    }
    int mid = (low + high) / 2;
    update(ind * 2 + 1, l, r, low, mid);
    update(ind * 2 + 2, l, r, mid + 1, high);
    tree[ind] = (tree[ind * 2 + 1] + tree[ind * 2 + 2]);
}
int query(int ind, int l, int r, int low, int high)
{
    propagate(ind, low, high);
    if(low > r || high < l) return 0;
    if(low >= l && high <= r)
    {
        //cout<<curL<<" | "<<curR<<" "<<tree[ind]<<endl;
        return tree[ind];
    }
    int mid = (low + high) / 2;
    int lft = query(ind * 2 + 1, l, r, low, mid);
    int rgt = query(ind * 2 + 2, l, r, mid + 1, high);
    tree[ind] = (tree[ind * 2 + 1] + tree[ind * 2 + 2]);
    return lft + rgt;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>q;
    for(int i = 1; i <= n; i ++)
    {
        cin>>arr[i];
    }
    build(0, 1, n);
    for(int i = 0; i < q; i ++)
    {
        cin>>a>>b>>c;
        ///cout<<endl;
        if(a == 1)
        {
            update(0, b, c, 1, n);
        }
        else
        {
            cout<<query(0, b, c, 1, n)<<'\n';
        }
        //cout<<endl;
    }
    return 0;
}