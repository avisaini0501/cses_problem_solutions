#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    string s;
    cin>>s;
    ll count = 1;
    ll maxi = 1;

    for(int i = 1; i < s.length(); i++){
       if(s[i - 1] == s[i]){
         count++;
       }
       else count = 1;

       maxi = max(maxi , count);
    }
    cout<<maxi;
}