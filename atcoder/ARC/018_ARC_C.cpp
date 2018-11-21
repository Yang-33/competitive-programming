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

/* -----  2018/11/21  Problem: ARC 018 C / Link: http://arc018.contest.atcoder.jp/tasks/arc018_c  ----- */
/* ------問題------

僕の学校は各クラスの人数が非常に多い。 1,000,000 人で編成されるクラスもあるくらいだ。
僕のクラスも例外ではない。縦に N 行、横に M 列の長方形状に机が並んでいて、 N×M 人の生徒が一人一つずつ、自分の机を持っている。
僕の学校は防災意識が高く、もしものときは教室の後ろの壁がはがれてそこから人が避難することができるようになっている。
このたび、避難時には成績のいい人から逃げることができるようにした方がいいという方針になった。というわけで、僕のクラスでは成績の良い人ほど教室の後ろの壁に近いところに座るように席替えをすることになった。 具体的に言うと、教室の一番前の行を第 0 行、 一番左の列を第 0 列として、第 i 行第 j 列の場所にある席のことを (i,j) 、そこに席替え後に座っている人の成績を G[i][j] とすると、ある 2 つの席 (a,b),(c,d) に対して a>c ならば b,d の値によらず G[a][b]≥G[c][d] が常に成り立つように席替えをするということである。
生徒は任意の席へ移動することが可能だが、席替え後に 2 人以上の人が同じ席にいたり、誰も座らない席があってはならない。もちろん、新しく机を増設したり、なくしたりして、 N 行 M 列の形を崩すことも許されない。
席替えをするのは良いが、あいにく人数が非常に大きいので席替えによる各生徒の移動距離の総和を最小限に抑えたい。このとき、生徒の移動距離というのは、移動前後の席の位置のマンハッタン距離である。つまり (a,b) から (c,d) に移動したのならば移動距離は |a−c|+|b−d| である。
席替え前の各席に座っている生徒の成績を与えるので、生徒の総移動距離の最小値を求めてほしい。

-----問題ここまで----- */
/* -----解説等-----

頭が回ってなさすぎる
これは簡単で、まずsortする。ある列iへの移動を考えた時、縦の移動は必ずコストが掛かり、よこのコストを最小化したい。
当然、移動量が少ないほうがいいのでこれもsortすれば求まる。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W; cin >> H >> W;
	LL x0, ina, p; cin >> x0 >> ina >> p;
	VL m(H*W, 0);
	m[0] = x0;
	FOR(i, 1, H*W) {
		m[i] = (m[i - 1] + ina) % p;
	}

	using tp = tuple<LL, LL, LL>;
	vector<vector<tp>>A(H, vector<tp>(W));
	vector<tp> BB;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			BB.push_back(tp(m[i*W + j], i, j));
		}
	}
	SORT(BB);
	// ほぼおなじになったりしない
	// sortしてアレするとき、各列への分配の最適値
	// 縦はやる、横は揃えれば最小
	// a[i]は何行目へ行くべきか
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			A[i][j] = BB[i*W + j];
		}
	}
	LL ans = 0;
	FOR(i, 0, H) {
		VL c(W);
		FOR(j, 0, W) {
			c[j] = get<2>(A[i][j]);
			ans += abs(i - get<1>(A[i][j]));// 縦
		}
		SORT(c);
		FOR(j, 0, W) {
			ans += abs(c[j] - j); // 横
		}
	}
	cout << ans << endl;

	return 0;
}