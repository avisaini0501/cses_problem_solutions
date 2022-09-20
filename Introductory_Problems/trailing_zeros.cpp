#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll n;
    cin>>n;
    ll ans = 0;
    while(true){
      if(n >= 5)
      ans += n / 5;
      else 
       break;

      n = n / 5;                                                                                                                                                       
    }
    cout<<ans;
}