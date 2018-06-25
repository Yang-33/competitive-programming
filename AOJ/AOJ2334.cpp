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

/* -----  2018/06/25  Problem: AOJ 2334 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2334  ----- */
/* ------問題------

ネーヴァ王国には、トタタ族とツテテ族、２種類の民族が暮らしている。トタタ族の最大の特徴は、 酢豚にパイナップルを入れて食べることである。だがツテテ族は、パイナップルに酢豚を入れて食べ る。こんな２つの民族がお互いに仲良くやっていけるはずもなく、トタタ族とツテテ族は、何百年も の昔からずっといがみ合いを続けてきた。
そんなある日、ネーヴァ王のもとに、２つの民族から嘆願書が届いた。それによるとトタタ族は、自 分たちが暮らす街Ａと街Ｂのあいだを結ぶ道を建設してほしいらしい。一方でツテテ族も、自分たち が暮らす街Ｃと街Ｄのあいだを結ぶ道を建設してほしいらしい。
２つの民族が衝突するのを防ぐため、トタタ族が通る道とツテテ族が通る道を交差させることはでき ない。また、技術的な制約により、２つの街のあいだを一直線に結ぶような道しか建設することはで きない。つまり、必要ならば街Ａと街Ｂを直接道で結ばずに、いくつかのトタタ族の街を経由して街 Ａと街Ｂを間接的に結ぶことになるだろう（もちろん、ツテテ族の街を経由してはならない）。その 際、トタタ族の街を結ぶ道どうしは交差していてもよい。街Ｃと街Ｄについても同様である。
道を建設するには、その長さに比例したコストがかかる。なので、条件をみたしつつ、できるだけ建 設する道の長さの合計が短くなるようにしたい。さて、長さの最小値はいくつになるだろうか。

-----問題ここまで----- */
/* -----解説等-----

さすがに…
証明できればおわる。
まず交錯しないときはそのまま長さが答え。
次に交錯するときは、どちらかを保持したほうが良い。
あとは保持する方の線分に交錯しないようにグラフを作って最短路を求めれば良い。

----解説ここまで---- */
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-9, pi = acos(-1.0);
namespace std {
	bool operator<(const Point &lhs, const Point &rhs) {
		if (lhs.real() < rhs.real() - eps) return true;
		if (lhs.real() > rhs.real() + eps) return false;
		return lhs.imag() < rhs.imag();
	}
}
Point input_point() { ld x, y; cin >> x >> y; return Point(x, y); } // 点の入力
bool eq(ld a, ld b) { return (abs(a - b) < eps); } // 誤差つき等号判定
ld dot(Point a, Point b) { return real(conj(a) * b); } // 内積
ld cross(Point a, Point b) { return imag(conj(a) * b); } // 外積
														 // 直線の定義
class Line {
public:
	Point a, b;
	Line() : a(Point(0, 0)), b(Point(0, 0)) {}
	Line(Point a, Point b) : a(a), b(b) {}
	Point operator[](const int _num) {
		if (_num == 0)return a;
		else if (_num == 1)return b;
		else assert(false);
	}
};
int ccw(Point a, Point b, Point c) {
	b -= a; c -= a;
	if (cross(b, c) > eps) return 1;   // a,b,cが反時計周りの順に並ぶ
	if (cross(b, c) < -eps) return -1; // a,b,cが時計周りの順に並ぶ
	if (dot(b, c) < 0) return 2;       // c,a,bの順に直線に並ぶ
	if (norm(b) < norm(c)) return -2;  // a,b,cの順に直線に並ぶ
	return 0;                          // a,c,bの順に直線に並ぶ
}

// 線分と線分の交差判定
bool isis_ss(Line s, Line t) {
	return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
		ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}


ld Dijkstra(vector<vector<pair<int ,ld>>>& G, int s,int t) {
	vector<ld> dist(SZ(G), LINF);
	dist[s] = 0;
	using T = pair<ld, int>;
	priority_queue<T, vector<T>, greater<T>> que;
	que.push(T(0, s));

	while (!que.empty()) {
		PLL p = que.top(); que.pop();
		int v; /* 頂点*/ ld d; /* 頂点vまでの距離 */
		tie(d, v) = p;

		if (d > dist[v]) continue;

		FOR(i, 0, (int)G[v].size()) {
			int nv = G[v][i].first;
			if (dist[nv] > dist[v] + G[v][i].second) {
				dist[nv] = dist[v] + G[v][i].second;
				que.push(T(dist[nv], nv));
			}
		}
	}
	return dist[t];
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int NA, NB;
	cin >> NA >> NB;
	vector<Point>As(NA);
	vector<Point>Bs(NB);
	FOR(i, 0, NA) {
		As[i] = input_point();
	}
	FOR(i, 0, NB) {
		Bs[i] = input_point();
	}

	// no cross
	Line ALine = Line(As[0], As[1]);
	Line BLine = Line(Bs[0], Bs[1]);
	if (!isis_ss(ALine, BLine)) {
		ld dist = abs(As[0] - As[1]) + abs(Bs[0] - Bs[1]);
		cout << fixed << setprecision(10) << dist << endl;
	}
	else {

		auto makeGraph = [](int N, vector<Point>&points, const Line& mainline) {
			vector<vector<pair<int, ld>>>G(N);
			FOR(i, 0, N) {
				FOR(j, i + 1, N) {
					if (!isis_ss(mainline, Line(points[i], points[j]))) {
						G[i].emplace_back(j, abs(points[i] - points[j]));
						G[j].emplace_back(i, abs(points[i] - points[j]));
					}
				}
			}
			return G;
		};

		ld ans = LINF;
		// A arround B
		auto GB = makeGraph(NB, Bs, ALine);
		ans = min(ans, Dijkstra(GB, 0, 1)+ abs(As[0] - As[1]));

		// B arround A
		auto GA = makeGraph(NA, As, BLine);
		ans = min(ans, Dijkstra(GA, 0, 1) + abs(Bs[0] - Bs[1]));
		if (ans >= LINF) {
			cout << -1 << endl;
		}
		else {
			cout <<fixed<<setprecision(10)<< ans << endl;
		}


	}



	return 0;
}
