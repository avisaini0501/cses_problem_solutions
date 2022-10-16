#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n , x;
    cin>>x>>n;

    set<ll>pos;
    multiset<ll>len;
    
    pos.insert(0);
    pos.insert(x);
    len.insert(x);

    for(ll i = 0; i < n; i++){
        ll curr;
        cin>>curr;
        pos.insert(curr);
        auto it = pos.find(curr);
        ll prevval = *prev(it);
        ll nextval = *next(it);
        len.erase(len.find(nextval - prevval));
        len.insert(curr - prevval);
        len.insert(nextval - curr);
        cout<<*len.rbegin()<<endl;    
    }
}
