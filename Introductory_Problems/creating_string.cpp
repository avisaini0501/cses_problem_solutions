#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    string s;
    cin>>s;
    
    sort(s.begin() , s.end());
    vector<string> v;

    do{
        v.push_back(s);
    }while(next_permutation(s.begin(),s.end()));

    cout<<v.size()<<endl;
     
     for(ll i = 0; i < v.size();i++)
     cout<<v[i]<<endl;

}