#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

void solve(){
    int N, X; cin>>N>>X; 
    vector<int> C(N+1);
    for(int i = 1; i<=N; i++){
        cin>>C[i]; 
    }
    vector<int> dp(1000005, 0);
    dp[0] = 1; //number of ways to make 0 is 1 i.e. do not take any coin
    for(int i = 1; i<=X; i++){
        for(int j = 1; j<=N; j++){
            if(C[j] > i) continue;
            dp[i] = (dp[i] + dp[i-C[j]]) % MOD;
        } 
    }

cout<<dp[X];

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
