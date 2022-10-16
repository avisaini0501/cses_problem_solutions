#include<bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n , p;
    cin>>n>>p;

    vector<ll>v(n);
    for(ll i = 0; i < n; i++){
        cin>>v[i];
    }

    ll low = 0;
    ll high = 1e18;
    ll ans = 1e18;
    while(low <= high){
        ll mid = (low + high) / 2;
        ll pro = 0;
        for(ll i = 0; i < n; i++){
            pro += min(mid / v[i] , (ll)1e9);
        }
        if(pro >= p){
            if(mid < ans)
               ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout<<ans;
}