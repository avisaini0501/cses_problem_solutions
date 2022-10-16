#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define mod 1000000007
#define nax 500 + 1

using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    ll total = 0;
    for(ll i = 0; i<n; i++){
      cin>>v[i];
      total += v[i];
    }

    vector<ll> prev(total+1 , 0) , curr(total + 1, 0);
     
   prev[v[0]] = 1;
   set<ll>ans;
   ans.insert(v[0]);

   for(ll i = 1; i < n; i++){
     for(ll j = 1; j <= total; j++){
        if(v[i] == j){
            curr[j] = 1;
            ans.insert(j);
        }
        else if(prev[j] == 1) curr[j] = 1;
        else{
            if(j > v[i]){
               curr[j] = prev[j - v[i]];
               if(curr[j] == 1)
               ans.insert(j);
            }
            else curr[j] = prev[j];
        }
     }
     prev = curr;
   }
   cout<<ans.size()<<endl;
   for(ll i = 0; i <= total; i++){
      if(prev[i] == 1)
      cout<<i<<" ";
   }
   
}