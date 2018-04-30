#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
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

/* -----  2018/04/25  Problem: AOJ 2326 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2326  ----- */
/* ------問題------

[A,B]の整数部分集合を辞書順sortしたときにこれが昇順である組み合わせ数

-----問題ここまで----- */
/* -----解説等-----

辞書順ソートして、DP
dp[i]:=iを最後にするときの組合せ数

hadroriさんの解説のDPはよく考えられている。
連続区間に足し込むことが確定していればimos法っぽくDPができる。

----解説ここまで---- */
int mod;
template<typename type>
struct BIT { // 1-index
	int N;
	int nn;
	vector<type> data;
	BIT(int n) {
		N = n + 1;
		data = vector<type>(n + 1, 0);
		nn = 1;
		while (nn * 2 <= N)nn *= 2;
	}
	void add(int i, type w) { // a[i] += w
		for (int x = i; x <= N; x += x & -x) {
			data[x] += w;
			data[x] %= mod;
		}
	}
	type sum(int i) { // iまでの和 [1,i]
		type ret = 0;
		for (int x = i; x > 0; x -= x & -x) {
			ret += data[x];
			ret %= mod;
		}
		return ret;
	}
	// [l, r]
	type sum(int l, int r) {
		if (l > r) return 0;
		return sum(r) - sum(l - 1);
	}

};


LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL a, b, p;
	while (cin >> a >> b >> p, a || b || p) {
		mod = p;
		vector<string>vs;
		FOR(i, a, b + 1) {
			vs.push_back(to_string(i));
		}
		BIT<int> bit(SZ(vs)+10);
		SORT(vs);

		VI tps(SZ(vs));
		FOR(i, 0, SZ(vs)) {
			//debug(stoll(vs[i]) - a);
			tps[stoll(vs[i])-a] = i;
		}
		FOR(i, 0, SZ(vs)) {
			LL val = bit.sum(tps[i]);
			bit.add(tps[i] + 1, (val + 1) % p);
		}
		ans = bit.sum(b - a + 1) % p;
		cout << ans << "\n";
	}

	return 0;
}
