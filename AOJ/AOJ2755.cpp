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

/* -----  2018/06/10  Problem: AOJ 2755 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2755  ----- */
/* ------問題------

縦横の長さが h,w の長方形があり， 内部には一辺の長さが 1 の正方形のマスが敷き詰められている． 最も左上のマスを (0,0) とし， (0,0) の i 個下で j 個右のマスを (i,j) のように表すことにすると， (i,j) は i+j が偶数なら赤色に，奇数なら青色に塗られている．
今，(0,0) の左上の頂点と (h−1,w−1) の右下の頂点を線分で結んだ． この線分が通る赤色の部分の長さを a, 青色の部分の長さを b とおいたとき， 比 a:b は整数比となる．a:b を最も簡単にして(互いに素な整数で)表せ．

-----問題ここまで----- */
/* -----解説等-----

公式解説がすごいことをしていた
1進めるときの長さと、比からなんか値が出るので足す。
それをまとめれば良い

----解説ここまで---- */

LL gcd(LL a, LL b) {
	return b ? gcd(b, a%b) : a;
}

void solve() {
	int T; cin >> T;
	FOR(juju, 0, T) {
		LL h, w;
		cin >> h >> w;
		if (h == w) {
			cout << 1 << " " << 0 << endl;
			continue;
		}
		LL g = gcd(h, w);
		LL nh = h / g, nw = w / g;
		LL Mx = max(nh, nw);
		if ((nh % 2) + (nw % 2) == 1) {
			cout << "1 1" << endl;
		}
		else {
			LL Min = min(nw, nh);
			LL Long = (Mx + 1) / 2;
			LL noLong = Mx / 2;
			// 長い方に合わせる
			LL ansR = 0, ansB = 0;
			ansR += noLong * ((Min) / 2);
			ansB += Long *((Min) / 2);
			ansR += Long * ((Min + 1) / 2);
			ansB += noLong * ((Min + 1) / 2);
			LL GG = gcd(ansB, ansR);

			cout << ansR / GG << " " << ansB / GG << endl;
		}
	}

}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();

	return 0;
}
