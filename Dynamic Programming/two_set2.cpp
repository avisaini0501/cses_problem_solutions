#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define mod 1000000007
#define nax 500 + 1

using namespace std;

int main(){
    ll n;
    cin>>n;

    ll sum = (n * (n + 1)) / 2;
    
    if(sum % 2 == 1) cout<<"0";

    else{
        sum = sum / 2;
        vector<ll> prev(sum + 1 , 0) , curr(sum + 1, 0);
        prev[0] = 1;

        for(ll i = 1; i <= n; i++){
            for(ll tar = 0; tar <= sum; tar++){
                ll nottake = prev[tar];

                ll take = 0;
                if(tar >= i) take = prev[tar - i];

                curr[tar] = (take + nottake) % mod;
            }
            prev = curr;
        }
        cout<<(prev[sum] * 500000004) % mod;
    }
    
}