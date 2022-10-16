#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
    
    
    bool solve(ll mid , ll k, vector<ll>v, ll n){
        ll sum = 0;
        ll group = 1;
        for(ll i = 0; i < n; i++){
            if(v[i] > mid) return false;
              
              if(sum + v[i] > mid){
                group++;
                sum = v[i];
                if(group > k) return false;
              }
              else sum += v[i];
            }
    return true;  
}
int main(){
    ll n , k;
    cin>>n>>k;
    vector<ll>v(n);
    ll max_sum = 0;
    for(ll i = 0; i < n; i++){
        cin>>v[i];
        max_sum += v[i];
    }
    ll l = 0;
    ll h = max_sum;
    ll ans = INT_MAX;
    while(l <= h){
        ll mid = (l + h) / 2;
        if(solve(mid , k , v , n)){
            h = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    cout<<ans;
}