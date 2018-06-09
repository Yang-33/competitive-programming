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

/* -----  2018/06/07  Problem: AOJ DSL_2_C / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C  ----- */
/* ------問題------

いくつかの属性を持つレコードの集合（データベース）から、特定の属性の値が指定された領域に入るものを見つける問題を領域探索と呼びます。

２次元の平面上の点の集合に対し、与えられた領域に含まれる点を列挙してください。ただし、与えられた点の集合に対して、点の追加・削除は行われません。

出力
各クエリについて、点集合の中で sxi ≤ x ≤ txi かつ syi ≤ y ≤ tyi を満たす点の番号を、番号の昇順に出力してください。１つの点の番号を１行に出力し、各クエリに対する出力の最後に１つの空行を出力してください（条件を満たす点がない場合は１つの空行になります）。

-----問題ここまで----- */
/* -----解説等-----

kdTree解(これsegtreeでできませんか)

----解説ここまで---- */




class Node {
public:
	int location;
	int p, l, r;
	Node() {}
};
class Point {
public:
	int id, x, y;
	Point() {}
	Point(int id, int x, int y) :id(id), x(x), y(y) {}
	bool operator < (const Point &p)const {
		return id < p.id;
	}
	void print() {
		printf("%d\n", id);
	}
};
static const int MAX = 1000006;
static const int NIL = -1;
int N;
Point P[MAX];
Node T[MAX];
int np;

bool lessX(const Point &p1, const Point &p2) { return p1.x < p2.x; }
bool lessY(const Point &p1, const Point &p2) { return p1.y < p2.y; }

int makeKDTree(int l, int r, int depth) { // !! [l,r]
	if (!(l < r))return NIL;
	int mid = (l + r) / 2;
	int t = np++;
	if (depth % 2 == 0) {
		sort(P + l, P + r, lessX);
	}
	else {
		sort(P + l, P + r, lessY);
	}
	T[t].location = mid;
	T[t].l = makeKDTree(l, mid, depth + 1);
	T[t].r = makeKDTree(mid + 1, r, depth + 1);

	return t;
}

void find(int v, int sx, int tx, int sy, int ty, int depth, vector<Point>& ans) {
	int x = P[T[v].location].x;
	int y = P[T[v].location].y;
	if (sx <= x && x <= tx && sy <= y && y <= ty) {
		ans.push_back(P[T[v].location]);
	}
	if (depth % 2 == 0) {
		if (T[v].l != NIL) {
			if (sx <= x)find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
		}
		if (T[v].r != NIL) {
			if (x <= tx)find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
		}
	}
	else {
		if (T[v].l != NIL) {
			if (sy <= y)find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
		}
		if (T[v].r != NIL) {
			if (y <= ty)find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
		}
	}
}

int main() {
	int x, y;
	scanf("%d", &N);
	FOR(i, 0, N) {
		scanf("%d%d", &x, &y);
		P[i] = Point(i, x, y);
		T[i].l = T[i].r = T[i].p = NIL;
	}
	np = 0;
	int root = makeKDTree(0, N, 0);

	int Q;
	scanf("%d", &Q);
	int sx, sy, tx, ty;
	vector<Point> ans;
	FOR(i, 0, Q) {
		scanf("%d%d%d%d", &sx, &tx, &sy, &ty);
		ans.clear();
		find(root, sx, tx, sy, ty, 0, ans);
		SORT(ans);
		for (auto ob : ans) {
			ob.print();
		}
		printf("\n");
	}



	return 0;
}
