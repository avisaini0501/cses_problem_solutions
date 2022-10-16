#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n , x;
    cin>>n>>x;
    vector<ll>v(n);
    for(ll i = 0; i < n; i++){
        cin>>v[i];
    }
    ll count = 0;
    ll i = 0, j = 0;
    ll sum = 0;
    
    while(j < n){
       sum += v[j];
        j++;
       while(sum >= x){
         if(sum == x) count++;
         sum -= v[i];
         i++;
       }
    }
    cout<<count;
}