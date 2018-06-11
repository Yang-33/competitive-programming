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

/* -----  2018/06/10  Problem: AOJ 1320 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1320  ----- */
/* ------問題------

最も短いSを求めよ

-----問題ここまで----- */
/* -----解説等-----

まず部分列がどこかに含まれるのなら、必要ない。(必要ないので)
あとはどの順番でつなぐかだけ考えればいいので、bitDPをすればよい。
O(2^N*N^2)

----解説ここまで---- */

VS compression(VS vs) {
	SORT(vs);
	UNIQ(vs);

	int N = SZ(vs);
	VI need(N, 1);
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (i == j)continue;
			if (vs[i].find(vs[j])!=string::npos) {
				need[j] = 0;
			}
			
		}
	}
	VS ret;
	FOR(i, 0, N) {
		if (need[i])ret.push_back(vs[i]);
	}
	return ret;
}

map<PII, int>Mp;
int cost(int i, int k, VS &vs) {
	// vsのiにkをつなげたときにどれだけsuffixが増えるか、内包されることはない
	if (Mp.find(PII(i,k))!=Mp.end())return Mp[PII(i,k)];
	int len = min(vs[i].size(), vs[k].size());
	FORR(j, len, 0 - 1) {
		if (vs[i].substr(SZ(vs[i])-j)==vs[k].substr(0,j)) {
			return Mp[PII(i,k)] = SZ(vs[k])-j;
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int N;
	while (cin >> N, N) {
		Mp.clear();
		VS vs(N);
		FOR(i, 0, N) {
			cin >> vs[i];
		}

		vs = compression(vs);
		int N = SZ(vs);
		VVI dp(1 << N, VI(N, INF));
		FOR(i, 0, N) {
			dp[1 << i][i] = SZ(vs[i]);
		}
		FOR(bit, 0, 1 << N) {
			FOR(i, 0, N) {
				if (bit & 1 << i) {
					FOR(k, 0, N) {
						if (bit & 1 << k)continue;
						dp[bit|1<<k][k] = min(dp[bit|1<<k][k], dp[bit][i]+cost(i,k,vs));
					}
				}
			}
		}
		int ans =INF;
		FOR(i, 0, N) {
			ans = min(ans, dp[(1 << N) - 1][i]);
		}
		cout << ans << "\n";
	}

	return 0;
}
