#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    string s;
    cin>>s;
    vector<ll>map(27 , 0);
    ll charcount = 0;
    
    for(ll i = 0; i < s.length();i++){
        if(map[s[i] - 'A'] == 0)
          charcount++;
        map[s[i] - 'A']++;

    }
    
    ll charodd = 0;
    ll oddchar = -1;
    
    for(ll i = 0; i < map.size(); i++){
        if(map[i] != 0 && map[i] % 2 != 0){
          charodd++;
          oddchar = i;
        }
    }
    
    if(charodd > 1) cout<<"NO SOLUTION";
    
    else if(s.length() % 2 == 0 && charodd >= 1) cout<<"NO SOLUTION";
    
    else{
        vector<char>firsthalf;
        for(ll i = 0; i < map.size();i++){
            if(map[i] != 0 and map[i] % 2 == 0){
                ll half = map[i] / 2;
                while(half--)
                firsthalf.push_back(i + 'A');
            }
        }
        if(oddchar != -1){
        ll x = map[oddchar];
        while(x--)
        firsthalf.push_back(oddchar + 'A');
        }
       
       for(ll i = 0; i < firsthalf.size(); i++)
       cout<<firsthalf[i];

       if(oddchar == -1)
       for(ll i = firsthalf.size() - 1; i >= 0; i--)
       cout<<firsthalf[i];

       if(oddchar != -1)
       for(ll i = firsthalf.size() - map[oddchar] - 1; i >= 0; i--)
       cout<<firsthalf[i];
    }
}