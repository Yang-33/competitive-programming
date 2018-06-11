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

/* -----  2018/06/10  Problem: AOJ 2754 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2754  ----- */
/* ------問題------

ここに N 個の不思議な形の壺がある． 
i 番目の壺は Ki 個の直円柱を下から順に鉛直に繋げた形状である． 
繋がっている順番は変えることができない． A 氏は体積 M の水を持っている． 
この水をそれぞれの壺に好きな量ずつに分けて注ぐ． 水が全く入っていない壺が存在しても構わない． 
また，全ての壺が水で満たされたとき，それ以上水を注ぐ事はできない．
それぞれの壺の水面の高さの総和の最大値を求めよ．

-----問題ここまで----- */
/* -----解説等-----

最後まで適切な入れ方がわからないので、DPする
dp[ith][水の量]:=max

----解説ここまで---- */

double f(int k, int m, VI &S, VI &T) {
	// kth Sに,m L いれるときの高さ
	int left = m;
	double ret = 0;
	FOR(i, 0, SZ(S)) {
		double Cap = S[i] * T[i];
		if (left > Cap) {
			ret += T[i];
			left -= Cap;
		}
		else {
			ret += left*1.0 / S[i];
			left = 0;
			break;
		}
	}
	return ret;
}


void solve() {
	int N, M; cin >> N >> M;

	VI K(N);
	VVI S(N), T(N);
	FOR(i, 0, N) {
		cin >> K[i];
		S[i] = vector<int>(K[i]);
		T[i] = vector<int>(K[i]);
		FOR(j, 0, K[i]) {
			cin >> S[i][j] >> T[i][j];
		}
	}
	double dp[202][202];
	fill(*dp, *dp + 102 * 102, 0);

	FOR(i, 0, N) {
		FOR(base, 0, M + 1) {
			FOR(add, 0, M + 1) {
				if (base + add <= M)
					dp[i + 1][base + add] = max(dp[i + 1][base + add], dp[i][base] + f(i, add, S[i], T[i]));
				//cout << i << ",add=" << add<<", "; debug(f(i, add, S[i], T[i])) << endl;
			}
		}
	}
	cout << fixed << setprecision(10) << dp[N][M] << endl;

}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();

	return 0;
}