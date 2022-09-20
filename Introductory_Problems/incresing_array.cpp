#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<ll>vec;
    ll i = 0;
    ll ans = 0;
    while(i != n){
        ll inp;
        cin>>inp;
        vec.push_back(inp);
        if(i == 0){
            i++;
            continue;
        }
        if(vec[i] < vec[i - 1]){
            ans += vec[i - 1] - vec[i];
            vec[i] = vec[i - 1];
        }
        i++;
    }
    cout<<ans;
}