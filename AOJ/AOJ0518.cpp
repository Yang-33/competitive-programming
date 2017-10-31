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

/* -----  2017/10/31  Problem: AOJ 0518 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0518  ----- */
/* ------問題------

昔, そこには集落があり, 多くの人が暮らしていた. 人々は形も大きさも様々な建物を建てた.
だが, それらの建造物は既に失われ, 文献と, 遺跡から見つかった柱だけが建造物の位置を知る手がかりだった.

文献には神殿の記述がある. 神殿は上から見ると正確に正方形になっており, その四隅には柱があった. 
神殿がどの向きを向いていたかはわからない. また, 辺上や内部に柱があったかどうかもわからない. 
考古学者たちは, 遺跡から見つかった柱の中で, 正方形になっているもののうち, 面積が最大のものが神殿に違いないと考えた.

柱の位置の座標が与えられるので, 4 本の柱でできる正方形のうち面積が最大のものを探し, その面積を出力するプログラムを書け.
なお, 正方形の辺は座標軸に平行とは限らないことに注意せよ.

-----問題ここまで----- */
/* -----解説等-----

N^4が無理なので考えると、N点を決め打ちすれば法線ベクトルがわかることで、この点が存在するかを確認すれば良い。
また整数点しか存在しないのでうれしい。

----解説ここまで---- */
LL N;

LL ans = 0LL;
int main() {

	while (scanf("%lld",&N), N) {
		ans = 0;
		vector<PII>p;
		set<PII>se;
		FOR(i, 0, N) {
			int a, b;
			scanf("%d%d",&a, &b);// cin >> a >> b;
			p.push_back(PII(a, b));
			se.insert(PII(a, b));
		}
		//O(N^2logN)
		FOR(i, 0, N) {
			PII s = p[i];
			FOR(j, 0, N) {
				if (i == j)continue;
				PII t = p[j];
				//double edge = dist(s, t);
				LL x, y;
				x = s.first - t.first;
				y = s.second - t.second;
				//debug(x*x + y*y);
				//debug(edge*edge);
				if ((se.count(PII(t.first - y, t.second + x)) &&
					se.count(PII(s.first - y, s.second + x))) ||
					(se.count(PII(t.first + y, t.second - x)) &&
						se.count(PII(s.first + y, s.second - x)))) {
					ans = max(ans, x*x + y*y);
				}
			}
		}


		printf("%lld\n", ans);
		//cout << ans << "\n";
	}

	return 0;
}
