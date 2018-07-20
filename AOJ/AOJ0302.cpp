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

/* -----  2018/07/23  Problem: AOJ 0302 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0302  ----- */
/* ------問題------

ある晴れた夜の帰り道、空を見上げるとそこには無数の星。強く輝く星々、かすかに見える星々、いろ いろな明るさの星々が夜空を彩っています。
あなたはふと思いました。この星空に自分の星座があったらどんなに素敵だろうと。そこであなたはひとつの基準を決め、部屋の窓から見える星々を適当につなげて自分の星座を作ることにしました。その基準とは、「どの２つの星を選んでも、それらの明るさの差がある定数 d 以下になるような星のグループを作り、その中で一番大きいものを自分の星座にしよう！」というものです。例えば、図のような窓から見える夜空を考えてみましょう（外側の長方形は窓枠です）。
この夜空には、明るさがそれぞれ 1，12, 2，4，1，8, 3，5，4 の９つの星がありますが、d = 2 とすると例えば以下のような３つの星座 A, B, C ができます。
大きさが 12 の星座 A	大きさが 10 の星座 B	大きさが 16 の星座 C
星座の大きさを次のように決めることにしました。ある星座の星をすべて含むような、窓枠に平行な辺からなる長方形のうち、面積が最も小さいものを選びます。この長方形の面積をその星座の大きさとします。例えば、上の夜空では星座 A, B, Cの大きさはそれぞれ12, 10, 16になるので、星座Cが最も大きい星座となります。
N 個の星の位置と明るさ、および整数 d が与えられたとき、一番大きい星座の面積を求めるプログラムを作成してください。星の位置は窓枠の左下隅を原点とした座標で与えられ、軸は図のような向きとします。星座を構成する星が１つの場合や、星々が軸に平行な直線上にある場合は、その星座の面積は 0 となることに注意してください。

-----問題ここまで----- */
/* -----解説等-----

まず平方分割ができないかを考える。あるdに対して、d+=Dぐらいの範囲を持ってこれば良いので、
輝度順に並べてやれば、集合をO(sqrt(D))で持ってくることができる。
次にこれらの最小包含長方形的なものを考える。一回の計算量が最悪O(N)になって間に合わなさそう。
ところが輝度順でならんだものに対して、横の情報をmergeする際には点の座標のみあればよく、
更にこれはモノイドであることがわかる。このまま平方分割でもよいが、輝度で座標圧縮すればセグ木でできる。
バチャではクエリも座標圧縮したのでメモリが足りなかったが適当にindexをずらせばクエリの分は必要ない。

- 追記
しゃくとりできるので、何もいらない(悲しい)
追っかけてくれるしゃくとりをするとする。
このとき空のmultisetに星を追加し、差がdとなる小さいものを削除していく。
(これは正しい)


----解説ここまで---- */

template<class T> using V = vector<T>; template<class T> using VV = V<V<T>>;
struct nd {
	long long x1, y1, x2, y2;

	nd(LL x1 = LINF, LL x2 = -LINF, LL y1 = LINF, LL y2 = -LINF) :x1(x1), x2(x2), y1(y1), y2(y2) {} // ! e
};
struct SegmentTreeFastAry {
	nd merge(nd& l, nd& r) {
		nd ret;
		ret.x1 = min(l.x1, r.x1);
		ret.x2 = max(l.x2, r.x2);
		ret.y1 = min(l.y1, r.y1);
		ret.y2 = max(l.y2, r.y2);
		return ret;
	}
	void updatepoint(nd& node, nd& nx) { // point update 
		node = merge(node, nx);
	}
	// -- setting -- // 
	int ARY_SIZE; nd node[1 << 20]; // 131072
	void init(int n) { ARY_SIZE = 1; while (ARY_SIZE < n) ARY_SIZE <<= 1; }
	SegmentTreeFastAry(int n) : ARY_SIZE(1) { init(n); }
	inline void update(int i, nd& val) {
		i += ARY_SIZE; updatepoint(node[i], val);
		while (i > 1) { i >>= 1;	node[i] = merge(node[i << 1], node[(i << 1) + 1]); }
	}
	inline nd query(int l, int r) {
		if (l >= r) return nd(); nd vl = nd(), vr = nd();
		for (l += ARY_SIZE, r += ARY_SIZE; l != r; l >>= 1, r >>= 1) {
			if (l & 1) vl = merge(vl, node[l++]); if (r & 1) vr = merge(node[--r], vr);
		}	return merge(vl, vr);
	}
	nd operator[](int i) { return node[i + ARY_SIZE]; }
	//	void debugShow() { for (int i = ARY_SIZE; i < ARY_SIZE << 1; ++i) cerr << node[i].v << " "; cerr << "\n"; }
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, D;
	cin >> N >> D;
	V<int>x(N), y(N), b(N);

	FOR(i, 0, N) {
		cin >> x[i] >> y[i] >> b[i];
	}
	V<int>bc = b;
	bc.push_back(-1e9);
	SORT(bc); UNIQ(bc);
	V<int>bindex(N);
	FOR(i, 0, N) {
		bindex[i] = lower_bound(ALL(bc), b[i]) - bc.begin();
	}

	SegmentTreeFastAry seg(SZ(bc));
	FOR(i, 0, N) {
		nd renew(x[i], x[i], y[i], y[i]);
		seg.update(bindex[i], renew);
	}
	LL ans = 0;
	FOR(i, 0, N) {
		{
			int lowidx = lower_bound(ALL(bc), b[i] - D) - bc.begin();

			nd getnd = seg.query(lowidx, bindex[i] + 1);
			LL square = (getnd.x2 - getnd.x1)*(getnd.y2 - getnd.y1);
			ans = max(ans, square);
		}
		{
			int hiidx = lower_bound(ALL(bc), b[i] + D) - bc.begin();
			if (hiidx != SZ(bc) && bc[hiidx] == b[i] + D)hiidx++;
			nd getnd = seg.query(bindex[i], hiidx);
			LL square = (getnd.x2 - getnd.x1)*(getnd.y2 - getnd.y1);
			ans = max(ans, square);
		}
	}
	cout << ans << endl;

	return 0;
}