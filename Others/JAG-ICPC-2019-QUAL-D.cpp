#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ll = LL;
#define FOR(i,s,t) for(int i= s ; i < t; i++)
int main() {

	while (1) {
		string s, t; cin >> s;
		if (s == "#")break;
		cin >> t;
		LL add, del, rep, rot;
		cin >> add >> del >> rep >> rot;
		rep = min(rep, add + del);
		rot = min(rot, add + del);
		const LL LINF = 1e16;
		LL ans = LINF;
		int SN = (int)s.size();
		int TN = (int)t.size();
		FOR(k, 0, SN) {
			LL basecost = k * rot;
			vector<vector<LL>>dp(SN + 1, vector<LL>(TN + 1, LINF));
			dp[0][0] = 0;
			for (ll i = 1; i <= SN; i++) {
				dp[i][0] = i * del;
			}
			for (ll j = 1; j <= TN; j++) {
				dp[0][j] = j * add;
			}
			for (ll i = 1; i <= SN; i++) {
				for (ll j = 1; j <= TN; j++) {
					dp[i][j] = min({
						dp[i][j - 1] + add,
						dp[i - 1][j] + del,
						dp[i - 1][j - 1] + rep * (s[i - 1] != t[j - 1])
						});

					// rule: if u remove one of the rot components , u dont count rot cost.
					if (i - 1 >= SN - k) {
						dp[i][j] = min(dp[i][j], dp[i - 1][j] + del - rot);
						if (i&&j) {
							dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + min(rep, del - rot + add));
						}
					}
				}
			}




			LL ret = basecost + dp[SN][TN];
			ans = min(ans, ret);
			s = s.substr(1) + string(1, s[0]);
		}
		cout << ans << endl;
	}
}