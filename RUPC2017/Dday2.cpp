#include<iostream>
#include<algorithm>
#define ll long long
#define FOR(i,s,t) for(int (i)=(s);(i)<(t);(i)++)
using namespace std;


ll x[100], y[100];
ll table[110][110];
ll dp[110][110][100];

int main() {
    ll N,P;
    cin >> N >> P;
    FOR(i, 0, N) {
        cin >> x[i] >> y[i];
    }
    FOR(i, 0, N) {
        table[i][0] = x[i] - y[i];
    }
    FOR(j, 0, N)FOR(i, 0, N) {
        if (table[i][j] >= 0 || table[i + 1][0] >= 0)table[i + 1][j + 1] = (table[i][j] < 0 ? table[i][j] : 0) + (table[i][j] < 0 ? table[i][j] : 0);
        else if(table[i][j] + table[i + 1][0]>=-x[i])
        table[i + 1][j + 1] = table[i][j] + table[i + 1][0];
        else table[i + 1][j + 1] = -x[i];
    }

    FOR(i, 0, N)FOR(j, 0, N)FOR(k, 0, N) {
        dp[i][j][k] = -1e18;
    }
    dp[0][0][0] = 0;
    FOR(i, 0, N)FOR(j, 0, N)FOR(k, 0, N) {
        dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][k]);
        dp[i + 1][j+1][k+1] = max(dp[i+1][j+1][k+1], dp[i][j][k]+table[i+1][k]);
    }
    ll ans = -1e9;
    FOR(j, 0, N)FOR(k, 0, N) {
        if (dp[N][j][k] + P >= 0)ans = max(ans, (ll)j);
    }
    cout << ans << endl;
    return 0;
}