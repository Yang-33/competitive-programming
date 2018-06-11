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

/* -----  2018/06/10  Problem: AOJ 2774 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2774  ----- */
/* ------問題------

粘菌コンピュータというものがある。 ある種の粘菌には「餌を求め、餌と餌の最短距離をつなぐ形に変形する」 という性質がある。 これを利用し、餌を「入力」、形を「出力」とみなして コンピュータとして利用することができる。
今、二次元平面上に1つの粘菌の拠点とN個の餌が存在する。それぞれの餌には1からNまでの異なる番号が与えられ、拠点には番号0が与えられている。 この粘菌はある餌を食べるために、その餌と最も近い拠点の最短距離を結ぶ管状に 成長し、食べた位置に新たに拠点を形成する。 新たに形成した拠点は拠点を形成する直前に食べた餌と同じ番号を持つ。 粘菌は拠点以外の場所から成長することはできない。 以降では、拠点と餌を二次元平面上の点、管状に成長した粘菌を複数の線分として考える。
すべての拠点と線分からなる構造を粘菌網と呼ぶ。 粘菌は1つの餌を食べるために次のような操作を繰り返す。
まだ食べていない餌の中で粘菌網に最も近い餌を選ぶ。そのような餌が複数存在する場合は番号が最も小さい餌を選ぶ。
選んだ餌と最も近い拠点を選ぶ。そのような拠点が複数存在する場合は、最も拠点の番号が小さいものから取る。
選んだ拠点と餌を結ぶ線分を引く。以降ではこのとき選んだ餌も拠点として扱う。
この粘菌は生きるために必要な栄養を取るのにM個の餌を食べる必要がある。 粘菌がM個の餌を食べるまでに引いたすべての線分の長さの合計を求めよ。 また、出力する値は0.0001以下の誤差を含んでいても良い。

-----問題ここまで----- */
/* -----解説等-----

えーこれ解けなかったのダメだけど
最短路の更新を考える。
更新範囲は1点につながる部分しか更新されないので、普通に全探索すれば良い。

----解説ここまで---- */

typedef double ld;
typedef complex<ld> Point;
const ld eps = 1e-9, pi = acos(-1.0);
namespace std {
	bool operator < (const Point& lhs, const Point& rhs) {
		if (lhs.real() < rhs.real() - eps) return true;
		if (lhs.real() < rhs.real() + eps) return false;
		return lhs.imag() < rhs.imag();
	}
}

class Line {
public:
	Point a, b;
	Line() :a(Point(0, 0)), b(Point(0, 0)) {}
	Line(Point a, Point b) :a(a), b(b) {}
	Point operator[](const int _num) {
		if (_num == 0) return a;
		else if (_num == 1) return b;
	}
};

ld dot(Point a, Point b) { return real(conj(a)*b); }
Point proj(Line l, Point p) {
	ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + t * (l.a - l.b);
}
bool isis_sp(Line s, Point p) {
	return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps);
}

ld dist_sp(Line s, Point p) {
	Point r = proj(s, p);
	return isis_sp(s, r) ? abs(r - p) : min(abs(s.a - p), abs(s.b - p));
}

void solve() {
	int N, M, X, Y; cin >> N >> M >> X >> Y;
	vector<int> flag(N + 1, 0);
	vector<Point> ps(N + 1);
	ps[0] = Point(X, Y); flag[0] = 1;
	for (int i = 1; i <= N; i++) {
		int a, b; cin >> a >> b;
		ps[i] = Point(a, b);
	}

	ld ans = 0;
	vector<double> dist(N + 1, LINF);
	for (int i = 0; i <= N; i++) {
		dist[i] = abs(ps[i] - ps[0]);
	}
	for (int i = 0; i < M; i++) {
		ld len = LINF;
		int idx = -1;
		for (int i = 0; i <= N; i++) {
			if (flag[i] == 1) continue;
			if (len > dist[i]) {
				len = dist[i];
				idx = i;
			}
		}

		len = LINF;
		int pidx = -1;
		for (int i = 0; i <= N; i++) {
			if (flag[i] == 1) {
				ld d = abs(ps[i] - ps[idx]);
				if (len > d) {
					len = d;
					pidx = i;
				}
			}
		}
		ans += abs(ps[idx] - ps[pidx]);
		flag[idx] = 1;
		Line L(ps[idx], ps[pidx]);
		for (int i = 0; i <= N; i++) {
			if (flag[i] == 1) continue;
			dist[i] = min(dist[i], dist_sp(L, ps[i]));
		}

	}
	cout << fixed << setprecision(12) << ans << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}