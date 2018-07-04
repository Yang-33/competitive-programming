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

/* -----  2018/07/05  Problem: AOJ 3002 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/3002  ----- */
/* ------問題------

ukuku1333さんはおっちょこちょいなので、 x の一次式の積を展開したら、元の一次式がわからなくなってしまった。
x の n 次多項式が与えられるので、因数分解して元のxの一次式の積の形にせよ。

x の n 次多項式は以下のBNFによって与えられる。

-----問題ここまで----- */
/* -----解説等-----

xを全探索すれば良い

----解説ここまで---- */

using ll = LL;
vector<ll> Ans;
vector<ll> C;
ll baseSum;
ll baseMul;
ll baseDim;

void solve() {
	string S; cin >> S;
	ll n = S[2] - '0';

	C.resize(n);
	for (int idx = 0; idx < (int)S.length();) {
		if (S[idx] == '+' || S[idx] == '-') {
			bool minus = S[idx] == '-';
			int T = 0;
			idx++;
			while (isdigit(S[idx])) {
				T = 10 * T + S[idx] - '0';
				idx++;
			}
			if (T == 0) T = 1;
			if (minus) T = -T;
			if (idx == (int)S.length()) {
				C[0] = T;
			}
			else {
				idx++; // x
				if (S[idx] == '^') {
					idx++; // ^
					int dim = S[idx] - '0';
					C[dim] = T;
					idx++;
				}
				else {
					int dim = 1;
					C[dim] = T;
				}
			}
		}
		else {
			idx++;
		}
	}

	baseDim = n;
	baseSum = *C.rbegin();
	baseMul = *C.begin();

	vector<ll> V;

	set<ll> s;
	for (ll i = -abs(baseMul); i <= abs(baseMul); i++) {
		if (i == 0) continue;
		ll T = pow(i, baseDim);
		for (ll j = baseDim - 1; j >= 0; j--) {
			T += C[j] * (ll)pow(i, j);
		}
		if (T == 0) s.insert(-i);
	}

	for (auto v : s) {
		cout << "(x";
		if (v < 0) cout << "-";
		else cout << "+";
		cout << abs(v) << ")";
	}
	cout << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();

	return 0;

}