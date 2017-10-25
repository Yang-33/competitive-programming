#include "bits/stdc++.h"
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

/* -----  2017/10/25  Problem: AOJ 0563  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0563  ----- */
/* ------問題------

昨年末，サンタクロースはJOI 村の子供たちにクリスマスプレゼントを渡すのを忘れてしまった．
そこで，お詫びの気持ちとして子供たちにチョコレートケーキを届けることにした．届けるべき日は明日に迫っているので，そろそろ移動計画を考えなければならない．
JOI 村は，南北方向にまっすぐに伸びるW 本の道路と，東西方向にまっすぐに伸びるH 本の道路により，碁盤の目の形に区分けされている.
南北方向のW 本の道路には，西から順に1, 2, ... , W の番号が付けられており，東西方向のH 本の道路には，南から順に1, 2, ... , H の番号が付けられている.
西からx 番目の南北方向の道路と，南からy 番目の東西方向の道路が交わる交差点を(x, y) で表す. JOI 村にはN 軒の家があり，それらはいずれかの交差点に位置している. 
サンタクロースは道路に沿ってのみ移動することができる. 隣り合う交差点の間を移動するのにかかる時間を1 とする.
JOI 村のすべての家には子供がいるので，サンタクロースはJOI 村のすべての家に1 個ずつチョコレートケーキを届けてまわらなければならない. 
大切なチョコレートケーキを持ってトナカイと空を飛びまわるのはやや危険であるので，サンタクロースとトナカイはJOI 村のいずれかの交差点に降り立ち，
サンタクロースがそこから歩いてチョコレートケーキを届けることにした. サンタクロースは同時に2 個以上のチョコレートケーキを運んで歩くことはしない．
つまり，サンタクロースはチョコレートケーキを1 軒の家に届けるたびに降り立った交差点に戻る．
サンタクロースは，JOI 村に降り立ってからすべての家にチョコレートケーキを届けるまでの所要時間が最小になるような移動計画を選ぶことにした．
ここで，最後の家にチョコレートケーキを届けてから降り立った交差点に戻るまでの時間は所要時間に含めないことに注意せよ．また，移動にかかる時間以外は考えない．

-----問題ここまで----- */
/* -----解説等-----

マンハッタンチャンス!(?)
一次元上では真ん中の点が一番良いという事実がある。
したがって列の真ん中あるいは中央値で点は決定される。
マンハッタン距離の式から二次元の場合でも次元がそれぞれ独立しているのでバラバラにやってもよい。
真ん中を選ぶのはどうとでもなるが、Nが偶数のときは真ん中を選ぶのが最適ではないことがある。
というのは問題文で往復をサボれるところがあるからである。
これを考えるためには、中央値の候補の2^2通りを調べる必要がある。
これはx,yが独立であるから、必ずしも点が最小側によっていればいいとは限らないからである。(4点の軸上はずらすことを考えると端が最適であることはすぐわかる)


----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL W, H;
	cin >> W >> H;
	LL N; cin >> N;
	VL x(N), y(N);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
	}
	VL cx = x;
	VL cy = y;
	SORT(cx);
	SORT(cy);
	int midx, midy;
	LL ans = 0;

	if (N % 2 == 1) {
		midx = cx[N / 2];
		midy = cy[N / 2];
		LL maxx = -1;
		FOR(i, 0, N) {
			ans += 2 * abs(x[i] - midx) + 2 * abs(y[i] - midy);
			maxx = max(maxx, abs(x[i] - midx) + abs(y[i] - midy));
		}
		ans -= maxx;
	}

	else {
		//四点をみる
		//移動しない分を考えると、最適な点は二次元空間にあるがこれは独立しているので
		//全部調べないといけない
		ans = LLONG_MAX;
		FOR(kx, -1, 1) {
			FOR(ky, -1, 1) {
				LL ret = 0;
				LL maxx = -1;
				int Tmidx = cx[(N + kx) / 2];
				int Tmidy = cy[(N + ky) / 2];
				FOR(i, 0, N) {
					ret += 2 * abs(x[i] - Tmidx) + 2 * abs(y[i] - Tmidy);
					maxx = max(maxx, abs(x[i] - Tmidx) + abs(y[i] - Tmidy));
				}
				ret -= maxx;
				if (ans > ret) {
					midx = cx[(N + kx) / 2];
					midy = cy[(N + ky) / 2];
					ans = ret;
				}
			}
		}
	}
	cout << ans << "\n";
	cout << midx << " " << midy << endl;

	return 0;
}
