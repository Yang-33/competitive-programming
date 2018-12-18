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

/* -----  2018/10/11  Problem: EDU052 C / Link: __CONTEST_URL__  ----- */
/* ------問題------

あるxについて、h[x]となるような建造物がある。今、N<=KをみたすKについて、
ある高さHで切った時、それより上のブロックの数がK以下になるように切断する。
全ての高さが一緒になるまで繰り返す。
回数を最小化したときの回数は?

-----問題ここまで----- */
/* -----解説等-----

ある高さhについて、和がNである場所の位置をつかめば、そこまで最小化すれば良いことになる。
あとはパッキングを上からやれば良い。
面倒なのである高さの和に対してBITを使った。imosでも良い。

----解説ここまで---- */

// 半開区間 0index
template<class T>
struct RaBIT {
	int n; vector<T> bit0, bit1;
	RaBIT(int sz) :n(sz), bit0(n + 1, 0), bit1(n + 1, 0) {}

	T subsum(vector<T>& bit, int i) {
		T s = 0;
		while (i > 0) {
			(s += bit[i]);
			i -= i & -i;
		}
		return s;
	}
	void add(vector<T>& bit, int i, T x) {
		while (i <= n) {
			(bit[i] += x);
			i += i & -i;
		}
	}
	void rangeadd(int a, int b, T x) {
		a++;
		add(bit0, a, -(x * (a - 1)));
		add(bit1, a, x);
		add(bit0, b + 1, x * b);
		add(bit1, b + 1, -x);
	}
	T query(int a, int b) {
		a++;
		return ((subsum(bit1, b) * b + subsum(bit0, b))
			- (subsum(bit1, a - 1) * (a - 1) + subsum(bit0, a - 1)));
	}
};

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, K; cin >> N >> K;
	VL h(N);
	FOR(i, 0, N) {
		cin >> h[i];
	}
	SORT(h);
	LL Tops = h.back();
	ans = 0;

	RaBIT<LL> bit(200005);
	FOR(i, 0, N) {
		bit.rangeadd(1, h[i]+1,1);
	}
	int okpos = 0;
	FOR(i, 1, Tops+1) {
		if (bit.query(i, i + 1) == N)okpos = i;
	}
	VL a;
	FOR(i, okpos + 1, Tops + 1) {
		a.push_back(bit.query(i, i + 1));
	}

	reverse(ALL(a));
	LL sum = 0;
	FOR(i, 0, SZ(a)) {
		if (sum + a[i] > K) {
			ans++;
			sum = a[i];
		}
		else {
			sum += a[i];
		}
	}
	if (sum)ans++;
	cout << ans << "\n";

	return 0;
}
