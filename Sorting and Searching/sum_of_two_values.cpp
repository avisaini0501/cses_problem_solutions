#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n , x;
    cin>>n>>x;
    vector<pair<ll,ll>>v;
    for(ll i = 0; i < n; i++){
        ll a;
        cin>>a;
        v.push_back({a , i + 1});
    }
    sort(v.begin() , v.end());

    ll i = 0;
    ll j = n - 1;
    while(i < j){
        ll sum = v[i].first + v[j].first;
        if(sum == x){
         cout<<v[i].second<<" "<<v[j].second;
         break;
        }
        else if(sum > x)
        j--;
        else
        i++;
    }
    if(i >= j)
    cout<<"IMPOSSIBLE";
}