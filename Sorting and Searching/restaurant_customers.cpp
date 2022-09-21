#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n;
    cin>>n;

    vector<pair<ll , ll>>v;
    for(ll i = 0; i < n; i++){
        ll start , end;
        cin>>start>>end;

        v.push_back({start , 1});
        v.push_back({end , -1});
    }

    sort(v.begin() , v.end());
    ll maxi = INT_MIN;
    ll sum = 0;
    for(ll i = 0; i < v.size(); i++){
        sum += v[i].second;
        maxi  =  max(maxi , sum);
    }
    cout<<maxi;
}