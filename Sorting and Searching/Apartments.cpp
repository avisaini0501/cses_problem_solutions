#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n , m , k;
    cin>>n>>m>>k;
    vector<ll>peep(n);
    vector<ll>apps(m);
    for(ll i = 0; i < n; i++)
    cin>>peep[i];

    for(ll i = 0; i < m; i++)
    cin>>apps[i];

    sort(peep.begin() , peep.end());
    sort(apps.begin() , apps.end());
    
    ll ans = 0;
    ll i = 0 , j = 0;
    while(i < n && j < m){
        if(abs(peep[i] - apps[j]) <= k){
            ans++;
            i++;
            j++;
        }
        else if(peep[i] < apps[j])
        i++;
        
        else
        j++;
    }
    cout<<ans;
    return 0;
}