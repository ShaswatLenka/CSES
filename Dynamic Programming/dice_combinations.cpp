//https://cses.fi/problemset/task/1633/
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

void solve(){
    int n; cin>>n;
    vector<long long>  dp(1000005, 0LL);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
    if(n > 6){
        for(int i=7; i <= n; i++){
             for(int j = i; j >= i-6; j--){
                dp[i] = (dp[i] + dp[j]) % MOD;  
             }
        } 
    }else{
        cout<<dp[n];
        return;
    }
    cout<<dp[n] % MOD;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
return 0;
}
