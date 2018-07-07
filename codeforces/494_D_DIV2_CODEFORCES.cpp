#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/07/03  Problem: CodeForces494 D div2 / Link: http://codeforces.com/contest/1003/problem/D  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */
#include <unordered_map>
LL a[200005];
LL cnt[40];

int f(LL x) {
	int cnt = 0;
	while (x!=1LL){
		x /= 2;
		cnt++;
	}
	return cnt;
}

int g(int b) {
	// 上から貪欲
	int left = b;
	int ret = 0;
	for (int i = 35 - 1; i >= 0; i--){
		if (left / (1LL << i)) {
			LL num = left / (1LL << i);
			
			ret += min(num, cnt[i]);
			left -= min(num, cnt[i])*(1LL << i);
		}
	}
	if (left > 0)return -1;
	else return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, Q;
	scanf("%d%d", &N, &Q);
	FOR(i, 0, N) {
		scanf("%lld", &a[i]);
		cnt[f(a[i])]++;
	}
	
	int ans = 0;
	FOR(q, 0, Q) {
		int b; scanf("%d", &b);
		ans = g(b);
		printf("%d\n", ans);
	}
	//unordered_map<LL, int>dp;
	//dp[0] = 0;
	//FOR(i, 0, N) {
	//	unordered_map<LL, int>nx = dp;
	//	for (auto it : dp) {
	//		if (nx.find(it.first + a[i]) != nx.end())
	//			nx[it.first + a[i]] = min(nx[it.first + a[i]], it.second + 1);
	//		else nx[it.first + a[i]] = it.second + 1;
	//	}
	//	nx.swap(dp);
	//}

	//int ans = 0;
	//FOR(q, 0, Q) {
	//	int b; scanf("%d", &b);
	//	if (dp.find(b) == dp.end())ans = -1;
	//	else ans = dp[b];
	//	printf("%d\n", ans);
	//}


	return 0;
}
