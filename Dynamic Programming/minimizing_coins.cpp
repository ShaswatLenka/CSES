#include<bits/stdc++.h>
using namespace std;
const int INF = 1000000000;

void solve(){
    int n, x; cin>>n>>x;
    vector<int> c(n+1);
    for(int i = 1; i <= n; i++){
        cin>>c[i];
    }
    sort(c.begin(), c.end());

    vector<int> dp(1000005, INF);

    //dp[x] = min no of ways to make ci + dp[x-ci] if we are including the the coin ci
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        dp[c[i]] = 1;
        for(int j = 1; j<=x; j++){
            if(c[i] > j) continue;
            dp[j] = min(dp[j], dp[c[i]] + dp[j-c[i]]);
        } 
    } 
    int ans = dp[x] >= INF ? -1 : dp[x];
    cout<<ans<<"\n";
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
