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

/* -----  2018/12/15  Problem: ARC 003 D / Link: http://arc003.contest.atcoder.jp/tasks/arc003_d  ----- */
/* ------問題------

高橋君が働くAtCoder社では、いつも 1 つの円形のテーブルの周囲に社員全員で座ってミーティングを行います。
それぞれお気に入りの席があるのでいつも席は同じなのですが、今日は席替えをすることにしました。
高橋君がランダムに 2 人を選び場所を入れ替える動作を決められた回数行った後の席配置が新しい席配置になります。
しかし、残念なことにAtCoder社には隣り合わせにしてしまうとミーティング中におしゃべりをしてミーティングを邪魔してしまう 2 人組が存在します。
高橋君は真面目なので、ミーティングが滞りなく行われるようにそのような 2 人組は 1 組も隣り合わせにしたくないと思っています。
席替えを行った後に、隣り合わせにしてはいけない 2 人組が 1 組も隣り合わない確率を求めなさい。


-----問題ここまで----- */
/* -----解説等-----

要求誤差が小さいときは乱択なんですよね(yukicoderを解いたので)

----解説ここまで---- */

const int SIZE = 1e5;
int xor128() {
	static int x = 123456789;
	static int y = 362436069;
	static int z = 521288629;
	static int w = 88675123;
	int t;

	t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, K; cin >> N >> M >> K;
	VI a(M), b(M); {
		FOR(i, 0, M) {
			cin >> a[i] >> b[i];
		}
	}

	double ans = 0;
	VI seed(N); {
		iota(ALL(seed), 0);
	}

	FOR(_, 0, SIZE) {
		VI p = seed;
		FOR(z, 0, K) {
			int c = xor128() % N, d = xor128() % N;
			while (c == d)c = xor128() % N, d = xor128() % N;
			swap(p[c], p[d]);
		}
		bool f = 1; {
			VI rev(N); {
				FOR(i, 0, N) {
					rev[p[i]] = i;
				}
			}
			FOR(i, 0, M) {
				int di = abs(rev[a[i]] - rev[b[i]]);
				if (di <= 1 || di == N - 1)f = 0;
			}
		}
		ans += f;
	}
	ans /= SIZE;
	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}
