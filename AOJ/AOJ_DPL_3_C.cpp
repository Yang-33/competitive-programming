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

/* -----  2018/07/26  Problem: aoj_dpl_3_c / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

スタックの単調性をいかす。
久しぶりに書いたけどバグらなかった。でもむずいよ

----解説ここまで---- */

template<class T> using V = vector <T>; template <class T> using VV = V<V<T>>;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	V<int>h(N);
	FOR(i, 0, N) {
		cin >> h[i];
	}
	// iに対するl,rを決定する
	V<int>st(N + 1);
	int tpos = 0;
	V<LL>R(N + 1), L(N + 1);
	FOR(i, 0, N) {
		while (tpos && h[st[tpos - 1]] >= h[i]) {
			tpos--;
		}
		if (tpos) {
			L[i] = st[tpos - 1] + 1;
		}
		else {
			L[i] = 0;
		}
		st[tpos++] = i;
	}
	tpos = 0;
	for (int i = N - 1; i >= 0; i--) {
		while (tpos && h[st[tpos - 1]] >= h[i]) {
			tpos--;
		}
		if (tpos) {
			R[i] = st[tpos - 1];
		}
		else {
			R[i] = N;
		}
		st[tpos++] = i;
	}
	LL ans = 0;
	FOR(i, 0, N) {
		ans = max(ans, h[i] * (R[i] - L[i]));
	}
	cout << ans << endl;


	return 0;
}