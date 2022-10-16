#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

bool cmp(pair<ll , ll> &a , pair<ll ,ll> &b){
    return a.second < b.second;
}

int main(){
    ll n , k;
    cin>>n>>k;
    vector<pair<ll , ll>> movie(n);
    for(ll i = 0; i < n; i++){
        cin>>movie[i].first >> movie[i].second;
    }
    sort(movie.begin() , movie.end() , cmp);
    set<pair<ll ,ll>>s;
    ll cnt = 0;
    for(ll i = 0; i < n; i++){
       if(s.size() == 0){
        s.insert({-movie[i].second , i});
       }
       else{
         auto t = s.lower_bound({-movie[i].first , -1});
         if(t != s.end()){
            s.erase(t);
            s.insert({-movie[i].second , i});
         }
         else if(t == s.end() && s.size() < k){
            s.insert({-movie[i].second , i});
         }
         else cnt++;
       }
    }
    cout<<n - cnt;
}