#include<bits/stdc++.h>
#define ll long long //
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
    vector<bool>contains(n);
    vector<bool>contained(n);

    for(ll i = 0; i < n; i++){
        cin>>ranges[i].l;
        cin>>ranges[i].r;
        ranges[i].index = i;
    }

    sort(ranges.begin() , ranges.end());

    ll maxi = 0;

    for(ll i = 0; i < n; i++){
        if(ranges[i].r > maxi)
        maxi = ranges[i].r;
        else
        contained[ranges[i].index] = true;
    }
    ll mini = INT_MAX;

    for(ll i = n - 1; i >= 0; i--){
        if(ranges[i].r < mini)
        mini = ranges[i].r;
        else 
        contains[ranges[i].index] = true;
    }
    for(ll i = 0; i < n; i++){
        cout<<contains[i]<<" ";
    }
    cout<<endl;
    for(ll i = 0; i < n; i++){
        cout<<contained[i]<<" ";
    }
    
}
