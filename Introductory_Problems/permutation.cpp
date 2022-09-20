#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<int>v;
    if(n <= 3 and n != 1)
    cout<<"NO SOLUTION";
    else if(n == 1)
    cout<<1;
    else{
        for(int i = 2; i <= n; i+=2){
           v.push_back(i);
        }
        for(int j = 1; j <= n; j+=2){
            v.push_back(j);
        }
        for(int i = 0; i < v.size(); i++){
            cout<<v[i]<<" ";
        }
    }    
}