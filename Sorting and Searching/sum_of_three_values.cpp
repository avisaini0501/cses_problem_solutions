#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n , x;
    cin>>n>>x;

    vector<pair<ll , ll>>v(n);
    for(ll i = 0; i < n; i++){
        cin>>v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin() , v.end());

    bool flag = false;
    for(ll i = 0; i < n - 2; i++){
        if(flag == true) break;
        ll j = i + 1;
        ll k = n - 1;
        while(j < k){
            ll sum = v[i].first + v[j].first + v[k].first;
            if(sum == x){
                cout<<v[i].second<<" "<<v[j].second<<" "<<v[k].second;
                flag = true;
                break;
            }
            else if(sum < x) j++;
            
            else k--;
        }
    }
    if(flag == false) cout<<"IMPOSSIBLE";
}