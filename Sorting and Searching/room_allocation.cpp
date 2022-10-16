#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct range{
    ll l , r , index;
    bool operator < (const range &other) const{
        if(l == other.l)
          return r > other.r;
        return l < other.l;
    }
};

int main(){
    ll n;
    cin>>n;

    vector<range>ranges(n);
    for(ll i = 0; i < n; i++){
        cin>>ranges[i].l;
        cin>>ranges[i].r;
        ranges[i].index = i;
    }
    sort(ranges.begin() , ranges.end());
    vector<ll>ans(n + 1);
    priority_queue<pair<ll , ll>> pq;
    ll last;
    last  = 0;
    
    for(ll i = 0; i < n; i++){
        if(pq.empty()){
            last++;
            ans[ranges[i].index] = last;
            pq.push({-ranges[i].r , last});
        }
        else{
            pair<ll , ll> p = pq.top();
            if(-p.first < ranges[i].l){
                pq.pop();
                pq.push({-ranges[i].r , p.second});
                ans[ranges[i].index] = p.second;
            }
            else{
                last++;
                pq.push({-ranges[i].r , last});
                ans[ranges[i].index] = last;
            }
        }
    }
    cout<<last<<endl;
    for(ll i = 0; i < n; i++){
        cout<<ans[i]<<" ";
    }
}
