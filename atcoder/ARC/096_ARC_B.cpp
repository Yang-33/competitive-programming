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

/* -----  2018/04/21  Problem: ARC 096 B / Link: http://arc096.contest.atcoder.jp/tasks/arc096_b  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

上手に考えなくても最小値partを小さくすれば解ける。

----解説ここまで---- */

template<typename type>
struct SegTree {
	type INIT_VAL = 0; // 影響のない値すなわち単位元
	inline type merge(type a, type b) { //台数構造

		return max(a, b); //merge部分

	}
	//-----setting-----//
	int N;	vector<type> dat;

	SegTree(int _N) {
		N = 1;
		while (N < _N)N *= 2;
		dat = vector<type>(N * 2 - 1, INIT_VAL);
		//dat.resize(N * 2 - 1, INT_MAX);
		// max値を入れておく、書き換えupdasteはいいが加算addに注意
	}
	SegTree(vector<type> &a, int _N) {//なにかしらで初期化できるならする。(クエリが後でも処理できるときなど)
		N = 1;
		while (N < _N)N *= 2;
		dat = vector<type>(N * 2 - 1, INIT_VAL);
		for (int i = 0; i < _N; ++i)dat[i + N - 1] = a[i];
		build();
	}
	~SegTree() { vector<type>().swap(dat); }

	void build() { for (int i = N - 2; i >= 0; i--) dat[i] = merge(dat[2 * i + 1], dat[2 * i + 2]); }

	void add(int k, type val) {
		k += N - 1;
		dat[k] += val;
		while (k) { // 根まで再帰的に上る
			k = (k - 1) / 2;
			dat[k] = merge(dat[k * 2 + 1], dat[k * 2 + 2]); // 結果をmerge
		}
	}

	void update(int k, type val) {
		k += N - 1;
		dat[k] = val;
		while (k) { // 根まで再帰的に上る
			k = (k - 1) / 2;
			dat[k] = merge(dat[k * 2 + 1], dat[k * 2 + 2]); // merge
		}
	}
	// 区間[a,b)の評価
	type query(int a, int b, int k, int l, int r) {
		//if (r == -1)r = N;
		if (r <= a || b <= l)return INIT_VAL; // 区間が被らない 
		if (a <= l&&b >= r)return dat[k]; // 値を返す
		type v1 = query(a, b, k * 2 + 1, l, (l + r) / 2);
		type v2 = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return merge(v1, v2); //merge
	}

	inline type query(int a, int b) {
		return query(a, b, 0, 0, N);
	}
};
LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL C; cin >> N >> C;
	VL x(2 * N), v(2 * N);
	FOR(i, 0, N) {
		cin >> x[i] >> v[i];
		x[N + i] = x[i] + C;
		v[N + i] = v[i];
	}
	SegTree<LL> seg(3 * N);
	SegTree<LL> segr(3 * N);

	VL d(2 * N);
	VL rd(2 * N);
	VL val(2 * N);
	FOR(i, 0, N) {
		if (i == 0) {
			d[i] = x[i];
		}
		else {
			d[i] = x[i] - x[i - 1];
		}
	}
	FOR(i, 0, N) {
		if (i == N - 1) {
			rd[i] = C - x[i];
		}
		else {
			rd[i] = x[i + 1] - x[i];
		}
	}

	{
		LL ret = 0; // <-
		FORR(i, N - 1, 0 - 1) {
			ret += v[i] - rd[i];
			segr.update(i, ret);
		}
	}
	{
		LL ret = 0; // ->
		FOR(i, 0, N) {
			ret += v[i] - d[i];
			seg.update(i, ret);
		}
	}

	{
		LL ret = 0;
		LL dsum = 0;
		FOR(i, 0, N) {
			ret += v[i] - d[i];
			ans = max(ans, ret);

			dsum += d[i];
			LL s = segr.query(i + 1, N+1);
			ans = max(ans, ret - dsum + s);

		}
	}
	{
		LL ret = 0;
		LL dsum = 0;
		FORR(i, N - 1, 0 - 1) {
			ret += v[i] - rd[i];
			ans = max(ans, ret);

			dsum += rd[i];
			LL s = seg.query(0,i);
			ans = max(ans, ret - dsum + max(0LL,s));

		}
	}


	cout << ans << "\n";

	return 0;
}
