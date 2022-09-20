#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll q;
    cin>>q;
    vector<ll> v(19,  1);
    for(ll i = 1; i < 19; i++){
        v[i] = v[i - 1] * 10;
    }
    while(q--){
        ll ind;
        cin>>ind;
        ll digitend = 0;
        ll beforedigit = 0;
        ll n_digit;
        for(ll i = 1; i <= 18;i++){
            digitend += (v[i] - v[i - 1]) * i;
            if(digitend >= ind){
                n_digit = i;
                break;
            }
            beforedigit += (v[i] - v[i - 1]) * i;
        }
        //binary search
        ll low = v[n_digit - 1];
        ll high = v[n_digit] - 1;
        ll best = 0;
        ll startposbest;
        while(low <= high){
            ll mid = (low + high) / 2;
            ll startposmid = beforedigit + 1 + (mid - v[n_digit - 1]) * n_digit;
            if(startposmid <= ind){
                if(mid > best){
                    best = mid;
                    startposbest = startposmid;
                }
                low = mid + 1;
            }
            else
            high = mid - 1;
        }
        string num = to_string(best);
        cout<<num[ind - startposbest]<<endl;
    }
}