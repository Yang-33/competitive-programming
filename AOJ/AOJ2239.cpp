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

/* -----  2017/11/29  Problem: AOJ 2239 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2239  ----- */
/* ------問題------

うさぎがある電車のチケットをn 枚持っている. チケットにはそれぞれ0 からn − 1 までの番号がついていて, k 番のチケットを使うと, p⋅ak + q⋅bk 駅進むことができる.
うさぎは今いる駅からm 駅進んだ駅にあるニンジン食べ放題の店に行きたいが, なるべく歩く距離を短くしたい. 駅は等間隔に並んでいる. チケットを電車の上り線で進むことのみに用いるとき, うさぎは最小何駅分の徒歩で店に着けるか.
1 ≤ n, m, a, b, p, q ≤ 1 000 000 000 000 (整数)

-----問題ここまで----- */
/* -----解説等-----

制約がとてもでかくて辛いが、ぐっと制約を睨むと M = 10^12 ≒ 2^40 がみえる。
チケットでの移動距離は指数の底が2以上のときは40番目以降のチケットを使うのは無駄なので、
1で場合分けと、そうでない場合は半分全列挙をすればよい。
結構すぐ解けた。

----解説ここまで---- */
// 繰り返し二乗法
long long  powmod(long long  x, long long  n) {
	long long  res = 1;
	while (n > 0) {
		if (n & 1) {
			res = (res*x);
		}
		x = (x*x);
		n >>= 1;
	}
	return res;
}
LL N, M, A, B, P, Q;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> A >> B >> P >> Q;
	// N枚ある M駅に行きたい ticket(k):p⋅a^k + q⋅b^k  (k=0...N-1)

	if (A == 1 && B == 1) {
		LL E = P + Q;
		LL div = M / E;
		if (div > N) { ans = abs(M - N*E); }
		else {
			ans = abs(M - div*E);
			if (M%E != 0 && div + 1 <= N) {
				ans = min(ans, abs(M - (div + 1)*E));
			}
		}
	}// ok
	else { //40枚ぐらいしか使わないので全探索可能 戻れる可能性も忘れない
		ans = numeric_limits<LL>::max();
		VL dist;
		FOR(i, 0, min(N, 41LL)) {
			LL d = P*powmod(A, i) + Q*powmod(B, i);
			if (d > 2 * M)break; // 歩くのは沼
			dist.push_back(d);
		}

		int n1 = SZ(dist) / 2;
		int n2 = SZ(dist) - n1;

		VL distset;
		FOR(i, 0, 1 << n1) {
			LL ret = 0;
			FOR(j, 0, n1) {
				if (i&(1 << j)) {
					ret += dist[j];
				}
			}
			if (!(ret > 2 * M)) {
				distset.push_back(ret);
				ans = min(ans, abs(M - ret));
			}
		}
		SORT(distset);

		FOR(i, 0, 1 << n2) {
			LL ret = 0;
			FOR(j, 0, n2) {
				if (i&(1 << j)) {
					ret += dist[n1 + j];
				}
			}
			if (ret > 2 * M)continue;
			ans = min(ans, abs(M - ret));
			int id = lower_bound(ALL(distset), M - ret) - distset.begin();
			ans = min(ans, abs(M - (ret + distset[id])));
			if (id > 0) {
				id--;
				ans = min(ans, abs(M - (ret + distset[id])));
			}
		}

	}

	cout << ans << "\n";

	return 0;
}
