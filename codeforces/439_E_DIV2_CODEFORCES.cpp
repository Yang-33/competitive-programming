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

/* -----  2017/10/06  Problem: CodeForces439 E div2 / Link: http://codeforces.com/contest/869/problem/E  ----- */
/* ------問題------

H*Wの領域に短形を囲う、削除する、2点は短形をまたがずに到達可能かのクエリがくる。
これを判定せよ
クエリ≦10^5
短形≦2500*2500の長方形領域

-----問題ここまで----- */
/* -----解説等-----

これは2次元BITで二次元累積和を実現すればよいことがすぐにわかる。
あとは短形ごとに別々の扱いをしたいが、これができなかった
乱数を適当にかぶらないように生成できれば勝ち。
XORや何をしても可換でかつ重複しないようにし、あとは祈りをささげる
Eにしては簡単

----解説ここまで---- */

template<typename T>
struct BIT2D {
	int H, W;
	vector<vector<T>>data; 
	BIT2D(int h, int w) {
		H = h; W = w;
		int MAX = max(H, W);
		data = vector<vector<T>>(MAX + 1, vector<T>(MAX + 1, 0));
	}

	void add(int a, int b, T val) { 
		for (int x = a; x <= W; x += x & -x) {
			for (int y = b; y <= H; y += y & -y) {
				data[x][y] += val;
			}
		}
	}

	T _sum(int a, int b) { 
		T ret = 0;
		for (int x = a; x > 0; x -= x & -x) {
			for (int y = b; y > 0; y -= y & -y) {
				ret += data[x][y];
			}
		}
		return ret;
	}
	T sum(int lx, int ly, int rx, int ry) {
		return _sum(rx, ry) - _sum(lx - 1, ry) - _sum(rx, ly - 1) + _sum(lx - 1, ly - 1);
	}
};

LL N, M, Q;

LL ans = 0LL;

map<pair<PII, PII>,LL> memo;
long long myrand() {
	return abs(rand() * rand() + 2311 * rand() + rand());
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> Q;
	BIT2D<LL>bit(2600, 2600);
	srand(time(NULL));

	FOR(i, 0, Q) {
		int t; cin >> t;
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		if (t == 1) {
			LL rn = myrand()*myrand();
			memo[make_pair(PII(y1, x1), PII(y2, x2))] = rn;
			bit.add(y1, x1, rn);
			bit.add(y1, x2 + 1, -rn);
			bit.add(y2 + 1, x1, -rn);
			bit.add(y2 + 1, x2 + 1, rn);
		}
		else if (t == 2) {
			LL rn = memo[make_pair(PII(y1, x1), PII(y2, x2))];
			bit.add(y1, x1, -rn);
			bit.add(y1, x2 + 1, rn);
			bit.add(y2 + 1, x1, rn);
			bit.add(y2 + 1, x2 + 1, -rn);
		}
		else {
			if (bit._sum(y1, x1) == bit._sum(y2, x2)) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}

		}
	}

	return 0;
}