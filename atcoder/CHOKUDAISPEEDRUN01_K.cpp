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

/* -----  2017/12/20  Problem: chokudaispeedrun01_k / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

.

----解説ここまで---- */

LL N;

LL ans = 0LL;


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

	/*	BIT 上で二分探索
	二分木の分かれ方に従って二分探索する
	左の子に進むか右の子に進むかを知るためには，左の子の範囲の和がわかればよい
	ちょうど BIT がもっている情報，O(1) 時間で得られる	*/
	int lower_bound(type w) {//  w≦[1,x]以上となる最小のindex,x
		if (w <= 0) return 0;
		int x = 0;
		for (int k = nn; k > 0; k /= 2) {
			if (x + k <= N && data[x + k] < w) {
				w -= data[x + k];
				x += k;
			}
		}
		return x; // 0 index
		//return x + 1 ; // 1 index
	}
};


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;

	VL fact(N + 1, 0);
	fact[0] = fact[1] = 1;

	FOR(i, 2, N + 1) {
		fact[i] = (i%MOD *fact[i - 1]) % MOD;
		//	debug(fact[i]);
	}

	VI a(N);
	BIT<int> bit(N);
	FOR(i, 0, N) {
		cin >> a[i];
		bit.add(a[i], 1);
	}


	FOR(i, 0, N) {
		int hi = bit.sum(a[i]);
		debug(hi);
		hi--;
		LL ret = hi*fact[N - i - 1];
		ans += ret%MOD;
		ans %= MOD;
		bit.add(a[i], -1);
		//int hi = lower_bound(ALL(h), a[i]) - h.begin();
		//LL ret = hi*fact[N - i - 1];
		//debug(ret);
		//cout << hi << " "; debug(fact[hi]);
		//ans += ret;
		//ans %= MOD;
	}



	ans++;
	cout << ans << "\n";

	return 0;
}
