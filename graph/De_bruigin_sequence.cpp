#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define mod 1000000007
#define pb push_back
#define pii pair<ll , ll>
#define vc vector
#define vp vector<pair<ll , ll>>
#define vi vector<ll>
#define vii vector<vector<<ll>>
#define loop(a , b) for(ll i = a; i < b; i++)
#define rep(a , b) for(ll i = a; i <= b; i++)
#define all(x) x.begin() , x.end()
#define triplet pair<ll , pair<ll , ll>>
#define goog(tno) cout<<"Case #"<<tno<<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

unordered_map<string , ll>mp;
string mp2[100005];
vc<pair<ll , char>> graph[100005];
ll k = 0 , n;

void rec(string s){
    if(s.size() == n - 1){
        mp[s] = ++k;
        mp2[k] = s;
        return;
    }
    rec(s + '0');
    rec(s + '1');
}

int main(){
    fast_io;
    cin>>n;
    if(n == 1){
        cout<<"01";
        return 0;
    }

    rec("");

    ll t = (1<<(n -1));

    loop(1 , t + 1){
        string x = mp2[i].substr(1 , n - 2);
        graph[i].pb({mp[x + "0"] , '0'}); 
        graph[i].pb({mp[x + "1"] , '1'});
    }

    string path;
    stack<pair<ll , char>> st;
    st.push({1 , '#'});

    while(!st.empty()){
        auto p = st.top();
        ll i = p.first;
        char c = p.second;
        if(graph[i].size() == 0){
            if(c != '#')
             path += c;

             st.pop();
        }
        else{
            auto p2 = graph[i].back();
            graph[i].pop_back();
            ll j = p2.first;
            char c2 = p2.second;
            st.push({j , c2});
        }
    }
    path += mp2[1];

    cout<<path;
}

