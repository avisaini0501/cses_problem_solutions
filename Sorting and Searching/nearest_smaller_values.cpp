#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i = 0; i < n; i++){
        cin>>v[i];
    }
    stack<pair<ll , ll>>st;
    for(ll i = 0; i < n; i++){
        if(st.empty()){
            cout<<"0"<<" ";
            st.push({v[i] , i + 1});
        }
        else if(st.top().first < v[i]){
            cout<<st.top().second<<" ";
            st.push({v[i] , i + 1});
        }
        else if(st.top().first >= v[i]){
            while(!st.empty() && st.top().first >= v[i]){
                 st.pop();
            }
            if(st.empty()){
              cout<<"0"<<" ";
              st.push({v[i] , i + 1});
            }
            else{
                cout<<st.top().second<<" ";
                st.push({v[i] , i + 1});
            }
        }
    }
}