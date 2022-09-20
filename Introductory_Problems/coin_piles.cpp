#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll t, a, b;
    cin>>t;
    for(ll i = 0; i < t; i++){
         cin>>a>>b;
         if(b > a)
         swap(a, b);

         if(a > 2 * b || (a + b)% 3 != 0)
         cout<<"NO"<<endl;

         else
         cout<<"YES"<<endl;
    }

}