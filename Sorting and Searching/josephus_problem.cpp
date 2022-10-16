#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n , k;
    cin>>n>>k;
     
    vector<ll>child(n);
    for(ll i = 0; i < n; i++){
        child[i] = i+1;
    }

    while(child.size() > 1){
        
        vector<ll>survive;
        for(ll i = 0; i < child.size(); i++){
            if(i % 2 == 1) 
            cout<<child[i]<<" ";
            else
              survive.push_back(child[i]);
        }
        if(child.size() % 2 == 0)
          child = survive;
        else{
            ll start = survive.back();
            survive.pop_back();
            child.clear();
            child.push_back(start);
            for(auto z : survive)
               child.push_back(z);
        }
    }
    cout<<child[0];
}