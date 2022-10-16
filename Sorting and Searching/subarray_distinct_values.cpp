#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n , k;
    cin>>n>>k;
    vector<ll>v(n);
    for(ll i = 0; i < n; i++){
        cin>>v[i];
    }
   map<ll , ll>seen;
   ll ans = 0;
   ll j = 0;
   for(ll i = 0; i < n; i++){
      while(j < n && ((ll)seen.size() < k || seen.count(v[j]) > 0)){
        seen[v[j]]++;
        j++;
      }
      ans += j - i;
      seen[v[i]]--;
      if(seen[v[i]] == 0)
        seen.erase(v[i]);
   }
   cout<<ans;
}