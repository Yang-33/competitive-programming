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

/* -----  2018/08/02  Problem: yukicoder 209  / Link: http://yukicoder.me/problems/no/209  ----- */
/* ------問題------

Find the maximum length of the subsequence {Bi}ki=1 of the given sequence {Ai}Ni=1 such that
1≤∃j≤k,B1<B2<⋯<Bj>⋯>Bk−1>Bk∧|B1−B2|<|B2−B3|<⋯<|Bj−1−Bj|∧|Bj−Bj+1|>|Bj+1−Bj+2|>⋯>|Bk−1−Bk|.

-----問題ここまで----- */
/* -----解説等-----

繰り返す部分が多そうにみえる。
点を決めていく作業をする途中に、前の2点の情報を保存すればO(N^3)

----解説ここまで---- */

int L[102][102], R[102][102];

// [l,rend]はOKだった
int Lf(int l, int rend, const VI&a) {
	if (L[l][rend] != -1) {
		return L[l][rend];
	}
	int ret = 0;
	FOR(k, 0, l) {
		if ( a[k] < a[l]
			&& abs(a[k]-a[l]) < abs(a[l]-a[rend]) ) {
			ret = max(ret, Lf(k, l, a) + 1);
		}
	}

	return L[l][rend] = ret;

}
// [lbegin,r]はOKだった
int Rf(int lbegin, int r, const VI&a) {
	if (R[lbegin][r] != -1) {
		return R[lbegin][r];
	}
	int ret = 0;
	FOR(k, r + 1, SZ(a)) {
		if (a[r] > a[k]
			&& abs(a[lbegin] - a[r]) > abs(a[r] - a[k])) {
			ret = max(ret, Rf(r,k, a) + 1);
		}
	}

	return R[lbegin][r] = ret;
}


int f(int Top, const VI &a) {
	int Lval = 0, Rval = 0;
	FOR(i, 0, Top) {
		if (a[i] < a[Top])
			Lval = max(Lval, Lf(i, Top, a) + 1);
	}

	FOR(i, Top + 1, SZ(a)) {
		if (a[Top] > a[i])
			Rval = max(Rval, Rf(Top, i, a) + 1);
	}


	return Lval + Rval + 1;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(_, 0, T) {
		int N; cin >> N;
		VI a(N);
		FOR(i, 0, N) {
			cin >> a[i];
		}
		fill(*L, *L + 102 * 102, -1);
		fill(*R, *R + 102 * 102, -1);

		int ans = 0;
		FOR(top, 0, N) {
			ans = max(ans, f(top, a));
		}
		cout << ans << "\n";
	}

	return 0;
}
