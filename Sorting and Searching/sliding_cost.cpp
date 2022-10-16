#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n , k;
    cin>>n>>k;

    set<pair<ll , ll>>left;
    set<pair<ll ,ll>>right;
    vector<ll>v(n);
    for(ll i = 0; i < n; i++)
    cin>>v[i];

    if(k == 1){
        for(ll i = 0; i < n; i++)
        cout<<"0"<<" ";
       return 0; 
    }
    if(k == 2){
        for(ll i = 1; i < n; i++){
            cout<<abs(v[i - 1] - v[i])<<" ";
        }
      return 0;
    }
    vector<pair<ll ,ll>>st;
    for(ll i = 0; i < k; i++)
       st.push_back({v[i] , i});

    sort(st.begin() , st.end());

    ll leftsum = 0;
    ll rightsum = 0;
    for(ll i = 0; i < k / 2 + (k % 2); i++){
        leftsum += st[i].first;
        left.insert(st[i]);
    }   
    for(ll i = k / 2 + (k % 2); i < k; i++){
        rightsum += st[i].first;
        right.insert(st[i]);
    }
    ll median = left.rbegin()->first;
    cout<<median * left.size() - leftsum + rightsum - median * right.size()<<" ";

    for(ll j = 1; j < n - k + 1; j++){
        if(left.count({v[j - 1] , j - 1})){
            leftsum -= v[j - 1];
            left.erase({v[j - 1] , j - 1});
        }
        else{
            rightsum -= v[j - 1];
            right.erase({v[j - 1] , j - 1});
        }
        if(*(left.rbegin()) < make_pair(v[k + j - 1] , k + j - 1)){
            rightsum += v[k + j - 1];
            right.insert({v[k + j - 1] , k + j - 1});
        }
        else{
            leftsum += v[k + j - 1];
            left.insert({v[k + j - 1] , k + j - 1});
        }
        while(left.size() < k / 2 + (k % 2)){
            pair<ll , ll> z = (*right.begin());
            left.insert(z);
            leftsum += z.first;
            right.erase(z);
            rightsum -= z.first;
        }
        while(left.size() > k / 2 + (k % 2)){
            pair<ll , ll> z = (*left.rbegin());
            right.insert(z);
            rightsum += z.first;
            left.erase(z);
            leftsum -= z.first;
        }
        median = left.rbegin()->first;
        cout<<median * left.size() - leftsum + rightsum - median * right.size()<<" ";
    }
}