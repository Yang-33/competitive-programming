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

/* -----  2018/07/10  Problem: CodeForces496 E div2 / Link: http://codeforces.com/contest/1005/problem/E  ----- */
/* ------問題------

E1の制約に、Mがたくさん出てくるようになった問題。

-----問題ここまで----- */
/* -----解説等-----

E1の方針では重複するので厳しい。
そこで中央値がMでないものを数え上げる。

- 方針1 BITで過半数Xを数える
   - 方針2と一緒じゃない?

- 方針2 (Editorial)M以上になる中央値集合 - M+1以上になる中央値集合をやる
   - これは簡単で、累積和上でR-L>0を、あるRについて検索できるようにすれば良い。
   - add,cumChange,sumをすればよい。>0なのでcur-1で正しい。

方針2で解いた。

----解説ここまで---- */


template<typename type>
struct BIT { // 1-index
	int N;
	int nn;
	vector<type> data;
	//動的はmap<int?,type>data
	BIT(int n) {
		N = n + 1;
		data = vector<type>(n + 1, 0);
		nn = 1;
		while (nn * 2 <= N)nn *= 2;
	}
	void add(int i, type w) { // a[i] += w
		for (int x = i; x <= N; x += x & -x) {
			data[x] += w;
		}
	}
	type sum(int i) { // iまでの和 [1,i]
		type ret = 0;
		for (int x = i; x > 0; x -= x & -x) {
			ret += data[x];
		}
		return ret;
	}
	// [l, r]
	type sum(int l, int r) {
		if (l > r) return 0;
		return sum(r) - sum(l - 1);
	}
};


LL gre(const VI&a, int M) {
	int N = SZ(a);

	LL ret = 0;
	BIT<LL> bit(4e5 + 10);
	int cur = 2e5 + 5;
	FOR(i, 0, N) {
		bit.add(cur, 1);

		if (a[i] < M) {
			cur--;
		}
		else {
			cur++;
		}
		ret += bit.sum(cur-1);
	}
	return ret;
}

void solve2() {
	int N, M; cin >> N >> M;
	VI a(N);
	FOR(i, 0, N)cin >> a[i];

	cout << gre(a, M) - gre(a, M + 1) << endl;
}



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve2();

	return 0;
}
