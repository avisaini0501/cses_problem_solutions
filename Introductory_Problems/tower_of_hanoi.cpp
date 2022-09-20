#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

void solve(ll a, ll b, ll c, ll n){
    if(n == 0) return;

    solve(a, c, b, n - 1);
    cout<<a<<" "<<c<<endl;
    solve(b , a, c, n - 1);
}

int main(){
    ll n;
    cin>>n;
    cout<<(1<<n) - 1<<endl;
    
    solve(1 , 2 , 3 , n);
}