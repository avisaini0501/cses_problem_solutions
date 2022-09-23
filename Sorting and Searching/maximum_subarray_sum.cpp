#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i = 0; i < n; i++){
        cin>>v[i];
    }

    ll maxi = INT_MIN;
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        sum += v[i];
        maxi = max(maxi , sum);
        if(sum < 0) sum = 0;
    }
    cout<<maxi;
}