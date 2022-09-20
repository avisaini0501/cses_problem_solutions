#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
ll ways = 0;
char mat[8][8];
bool d1[15] , d2[15], row[8];

void solve(ll r){
    if(r == 8){
        ways++;
        return;
    }

    for(ll c = 0; c < 8; c++){
        if(mat[r][c] == '.' && d1[r - c + 7] == 0 && d2[r+c] == 0 && row[c] == 0){
           d1[r - c + 7] = 1 , d2[r+c] = 1 , row[c] = 1;
           solve(r + 1);
           d1[r - c + 7] = 0 , d2[r+c] = 0 , row[c] = 0;
        }
    }

}

int main(){
    for(ll i = 0; i < 8; i++){
        for(ll j = 0; j < 8; j++){
            cin>>mat[i][j];
        }
    }
    solve(0);
    cout<<ways;
}