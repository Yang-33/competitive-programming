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

/* -----  2018/02/23  Problem: 005_agc_b / Link: https://agc005.contest.atcoder.jp/tasks/agc005_b?lang=en  ----- */
/* ------問題------

すぬけ君はある日友人から長さ N の順列 a1,a2,…,aN を貰いました。

ΣΣmin(A_l,...,A_r)

を求めてください。

-----問題ここまで----- */
/* -----解説等-----

値iが持ちうる区間を考える。
値iの右側と左側に小さいものがあるとき、どれだけ距離が離れているかがわかればよい。
これは簡易setがあればできる。
setでもできる…

----解説ここまで---- */


template<typename type>
struct BIT0 { // 0-index
	int N;
	int nn;
	vector<type> data;
	//動的はmap<int?,type>data
	BIT0(int n) {
		N = n + 1;
		data = vector<type>(n + 1, 0);
		nn = 1;
		while (nn * 2 <= N)nn *= 2;
	}
	void add(int i, type w) {
		// a[i] += w
		i++;
		for (int x = i; x < N; x += x & -x) {
			data[x] += w;
		}
	}
	type sum(int i) {
		// iまでの和 [0,i)
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

	int lower_bound(type w) {
		//  w≦[0,x]以上となる最小のindex,x
		if (w <= 0) return 0;
		int x = 0;
		for (int k = nn; k > 0; k /= 2) {
			if (x + k <= N && data[x + k] < w) {
				w -= data[x + k];
				x += k;
			}
		}
		return x + 1;
	}
};

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(N + 10);
	VI ra(N + 10);
	FOR(i, 0, N) {
		cin >> a[i];
		ra[a[i]] = i;
	}
	BIT0<int>bit(N + 10), rbit(N + 10);
	FOR(i, 1, N + 1) {
		int l = bit.lower_bound(bit.sum(ra[i]));
		int r = N-1  - rbit.lower_bound(rbit.sum(N - 1 - ra[i]));
		//cout << l << "," << r << endl;

		ans += i*(LL)(r - ra[i]+1)*(ra[i] - l+ 1 );
		bit.add(ra[i], 1);
		rbit.add(N - 1 - ra[i], 1);
	}
	cout << ans << "\n";

	return 0;
}
