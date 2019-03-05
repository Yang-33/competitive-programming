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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2019/02/28  Problem: ABC 107 D / Link: http://abc107.contest.atcoder.jp/tasks/abc107_d  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */


template<typename type>
struct BIT0 { // 0-index
	int N;
	int nn;
	vector<type> data;
	BIT0(int n) {
		N = n + 1;
		data = vector<type>(n + 1, 0);
		nn = 1;
		while (nn * 2 <= N)nn *= 2;
	}
	void add(int i, type w) { // a[i] += w
		i++;
		for (int x = i; x < N; x += x & -x) {
			data[x] += w;
		}
	}
	type sum(int i) { // iまでの和 [0,i)
		type ret = 0;
		for (int x = i; x > 0; x -= x & -x) {
			ret += data[x];
		}
		return ret;
	}
	// [l, r)
	type sum(int l, int r) {
		return sum(r) - sum(l);
	}
};

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}

	auto b = a;
	SORT(b);

	auto f = [](const VL& a, LL x) { // x以上の値が過半数を占める連続部分列の総数
		int N = SZ(a);
		LL cnt = 0;
		BIT0<LL> bit(2 * N + 10);
		int cur = N + 5;
		FOR(i, 0, N) {
			bit.add(cur, 1);
			if (a[i] < x)cur--;
			else cur++;
			cnt += bit.sum(cur + 1); // 上側からなので良い

		}
		return cnt;
	};
	int L = 0;
	int R = N;
	while (R - L > 1) {
		int mid = (L + R) / 2;
		if (f(a, b[mid]) * 4 >= N * (N + 1)) {
			L = mid;
		}
		else {
			R = mid;
		}
	}
	ans = b[L];
	cout << ans << "\n";

	return 0;
}
