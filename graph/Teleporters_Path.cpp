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

vi graph[100005];
stack<ll> st;

void dfs(ll src){
    while(graph[src].size()){
        ll x = graph[src].back();
        graph[src].pop_back();
        dfs(x);
    }
    st.push(src);
}

int main(){
    fast_io;
    ll n , m;
    cin>>n>>m;

    ll in[n + 1] = {0} , out[n + 1] = {0};
    loop(0 , m){
        ll a , b;
        cin>>a>>b;
        graph[a].pb(b);
        in[b]++ , out[a]++;
    }
    ll a = 0, b = 0, c = 0, s1 = 0 , s2 = 0;

    loop(1 , n + 1){
        if(in[i] == out[i]) c++;
        if(in[i] - out[i] == 1){
            b++;
            s2 = i;
        }
        if(in[i] - out[i] == -1){
            a++;
            s1 = i;
        }
    }    
        if(s1 != 1 || s2 != n){
            cout<<"IMPOSSIBLE";
            return 0;
        }
        if(!(c == n - 2 && a == 1 && b == 1)){
            cout<<"IMPOSSIBLE";
            return 0;
        }
     
       dfs(1);
    
    if(st.size() != m + 1){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    while(0 , st.size()){
        cout<<st.top()<<" ";
        st.pop();
    }

}