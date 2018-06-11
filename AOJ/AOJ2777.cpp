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

/* -----  2018/06/10  Problem: AOJ 2777 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2777  ----- */
/* ------問題------

若ヶ松高校二年へ組の合津千里（あつちり）さんは数列が「きっちり」していなければ気がすまない。
合津さんによると、「きっちり」した数列とは、長さが偶数で左右対称である数列のことである。 すなわち、長さN(Nは偶数)の数列Sについて、次の条件を満たせば数列Sは「きっちり」している。
S1=SN,S2=SN−1, ... ,SN⁄2=SN−N⁄2+1
二年へ組の数学担当の先生は、合津さんから「きっちりしてください。」と要望され、授業で用いる数列を作り直さなければならない。
先生は、数列のl番目からr番目までのそれぞれの要素に数字xを足すクエリをいくつも適用することで、数列を「きっちり」させようと奮闘しているが、うまくいかないようだ。
二年へ組に所属する凄腕プログラマーのあなたの仕事は、先生が絶望してしまう前に、先生が作り直している数列が「きっちり」しているかを調べるプログラムを作ることだ。

-----問題ここまで----- */
/* -----解説等-----

まず判定を考える。これは対象との差分が0であればよい。
区間足し込みしか無いので、列を半分で切って折り返したものを一つの数列とみなす。
点変更のときはabsでmergeして、sumを取ればよいが区間足しこみは+-どちらもあるので厳しい気持ちになる。
sum=0であることは、区間内の点でmin=max=0であることに気がつく。
したがって区間min,maxのとれる区間足しこみが可能なsegtreeを書けば良い。

足しこみクエリは半分で切って、+-を反転させれば良い。

----解説ここまで---- */

using ll = LL;
using pll = PLL;

const ll INIT = 0;
struct SegTree {
	int N;
	ll init_v;
	vector<pll> node;
	VL lazy;
	SegTree(int _N) :init_v(INIT) {
		init_v = 0;
		N = 1;
		while (N < _N) N *= 2;
		node.resize(2 * N - 1, pll(0, 0));
		lazy.resize(2 * N - 1, 0);
	}

	pll merge(pll a, pll b) {
		pll ret = pll(-1e9, 1e9);
		ret.first = max(a.first, b.first);
		ret.second = min(a.second, b.second);
		return ret;
	}
	void lazy_e(int l, int r, int k) {
		node[k].first += lazy[k];
		node[k].second += lazy[k];
		if (r - l > 1) {
			lazy[2 * k + 1] += lazy[k];
			lazy[2 * k + 2] += lazy[k];
		}
		lazy[k] = 0;
	}

	void update(int a, int b, ll x) {
		update(a, b, 0, 0, N, x);
	}
	void update(int a, int b, int k, int l, int r, ll x) {
		lazy_e(l, r, k);
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			lazy[k] += x;
			lazy_e(l, r, k);
		}
		else {
			update(a, b, 2 * k + 1, l, (l + r) / 2, x);
			update(a, b, 2 * k + 2, (l + r) / 2, r, x);
			node[k] = merge(node[2 * k + 1], node[2 * k + 2]);
		}
	}

	pll query(int a, int b) { return query(a, b, 0, 0, N); }
	pll query(int a, int b, int k, int l, int r) {
		lazy_e(l, r, k);
		if (r <= a || b <= l) return pll(-1e9, 1e9);
		if (a <= l && r <= b) {
			return node[k];
		}
		else {
			return merge(
				query(a, b, 2 * k + 1, l, (l + r) / 2),
				query(a, b, 2 * k + 2, (l + r) / 2, r)
			);
		}
	}
};

void solve() {
	ll N; cin >> N;
	vector<ll> kassa(N); for (auto& in : kassa) cin >> in;
	ll Q; cin >> Q;
	ll  S = N / 2;
	SegTree ST(S);
	for (int i = 0; i < S; i++) {

		ST.update(i, i + 1, kassa[i]);
	}
	for (int i = S; i < N; i++) {
		ST.update(N - i - 1, N - i, -kassa[i]);
	}

	while (Q--) {
		ll l, r, x; cin >> l >> r >> x;
		l--; r--;
		if (r < S) {
			ST.update(l, r + 1, x);
		}
		else if (l >= S) {
			ST.update(N - r - 1, N - l, -x);
		}
		else {
			ST.update(l, S, x);
			ST.update(N - r - 1, S, -x);
		}
		pll a = ST.query(0, S);
		if (a.first == a.second && a.first == 0) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}