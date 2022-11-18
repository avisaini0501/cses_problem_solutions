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

int n,q;
int maxn = 200005;
vector<int> seg(maxn<<2) , lz(maxn<<2) , type(maxn<<2 , 2) , arr(maxn);


void build(int ind , int low , int high){
    if(low == high){
        seg[ind] = arr[low];
        return;
    }

    int mid = (low + high) >> 1;
    build(2 * ind + 1 , low , mid);
    build(2 * ind + 2 , mid+1 , high);
    seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
}

void update(int ind , int low , int high , int t , int l , int r , int val){
   if(type[ind] < 2){
         if(type[ind] == 1){
             seg[ind] += (high - low + 1) * lz[ind];
         }
         else{
             seg[ind] = (high - low + 1) * lz[ind];
         }

        if(low != high){
            if(type[ind] == 1){
                lz[2*ind+1] += lz[ind];
                lz[2*ind+2] += lz[ind];
            }
            else{
                lz[2*ind+1] = lz[ind];
                lz[2*ind+2] = lz[ind];
            }
            type[2*ind+1] = min(type[ind] , type[2*ind+1]);
            type[2*ind+2] = min(type[ind] , type[2*ind+2]);
        }
        lz[ind] = 0;
        type[ind] = 2;
     }  
    //no overlap
    if(high < l || r < low) return;
    
    //complete overlap
    if(low >= l && high <= r){
        if(t == 1){
            seg[ind] += (high - low + 1) * val;
        }
        else if(t == 0){
            seg[ind] = (high - low + 1) * val;
        }

        if(high != low){
            if(t == 1){
                lz[2*ind+1] += val;
                lz[2*ind+2] += val;
            }
            else{
                lz[2*ind+1] = val;
                lz[2*ind+2] = val;
            }
            type[2*ind+1] = min(type[2*ind+1] , t);
            type[2*ind+2] = min(type[2*ind+2] , t);
        }
        return;
    } 

    int mid = (low + high) / 2;
    update(2*ind+1 , low , mid , t , l , r , val);
    update(2*ind+2 , mid+1 , high , t , l , r , val);
    seg[ind] = (seg[2*ind+1] + seg[2*ind+2]);
}

int query(int ind , int low , int high , int l , int r){
     if(type[ind] < 2){
         if(type[ind] == 1){
             seg[ind] += (high - low + 1) * lz[ind];
         }
         else{
             seg[ind] = (high - low + 1) * lz[ind];
         }

        if(low != high){
            if(type[ind] == 1){
                lz[2*ind+1] += lz[ind];
                lz[2*ind+2] += lz[ind];
            }
            else{
                lz[2*ind+1] = lz[ind];
                lz[2*ind+2] = lz[ind];
            }
            type[2*ind+1] = min(type[ind] , type[2*ind+1]);
            type[2*ind+2] = min(type[ind] , type[2*ind+2]);
        }
        lz[ind] = 0;
        type[ind] = 2;
     }

     if(high < l || r < low) return 0;

     if(low >= l && high <= r) return seg[ind];

     int mid = (low + high) / 2;
     int left = query(2*ind+1 , low, mid , l , r);
     int right = query(2*ind+2 , mid+1, high , l , r);
     return (left + right);
}

int32_t main(){
    fast_io;
    cin>>n>>q;
    
    loop(0 , n){
      cin>>arr[i];
    }
    
    build(0 , 0 , n - 1);
    
    while(q--){
        int qt;
        cin>>qt;
        if(qt == 1){
            int a , b , val;
            cin>>a>>b>>val;
            a-- , b--;
            update(0 , 0 , n - 1 , 1 , a , b , val);
        }
        else if(qt == 2){
            int a , b , val;
            cin>>a>>b>>val;
            a-- , b--;
            update(0 , 0 , n - 1 , 0 , a , b , val);
        }
        else{
            int a , b;
            cin>>a>>b;
            a-- , b--;
            cout<<query(0 , 0 , n - 1 , a , b)<<endl;
        }
    }

}