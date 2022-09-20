#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    cin>>n;
    
    ll total = n * (n + 1)/2;
    ll sum = 0;
    for(int i = 0; i < n-1; i++){
        ll curr;
        cin>>curr;
        sum += curr;
    }
    ll res = total - sum;
    cout<<res;
    
}