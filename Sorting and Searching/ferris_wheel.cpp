#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n , w;
    cin>>n>>w;
    vector<ll>v(n);
    for(ll i = 0; i < n; i++){
        cin>>v[i];
    }
    sort(v.begin() , v.end());
    ll i = 0;
    ll j = n - 1;
    ll ans = 0;
    while(i <= j){
        if(v[i] + v[j] > w) j--;
        else {
            i++;
            j--;
        }
        ans++;

    }
    cout<<ans;
}