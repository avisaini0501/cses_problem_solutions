#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    ll sum = 0;

    for(ll i = 0; i < n; i++){
        cin>>v[i];
        sum += v[i];
    }
    sort(v.begin() , v.end());
    cout<<max(sum , (ll)2 * v[n - 1]);
}