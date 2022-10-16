#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define mod 1000000007

using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<ll>v(n);

   for(ll i = 0; i < n; i++)
     cin>>v[i];
    
    vector<ll>temp;
    temp.push_back(v[0]);

    for(ll i = 1; i < n; i++){
        if(v[i] > temp.back())
            temp.push_back(v[i]);
        else{
            ll ind = lower_bound(temp.begin() , temp.end() , v[i]) - temp.begin();
            temp[ind] = v[i];
        }
    }
    cout<<temp.size();
}