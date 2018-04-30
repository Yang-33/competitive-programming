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

/* -----  2018/04/27  Problem: AOJ 1373 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1373  ----- */
/* ------問題------

完全二分木の深さに対応する頂点に石を置く。石を置いた下の頂点には石を置くことはできない。
Q<=10^5回判定せよ。

-----問題ここまで----- */
/* -----解説等-----

一点にしか置かないようにしていくと、できる。
具体的には2個目の点は上のちょっと下に置くようにしておく。
ただし限界ギリギリまで点が置かれているときに注意。

----解説ここまで---- */



template<typename type>
struct BIT { // 1-index
	int N;
	int nn;
	map<int, type> data;
	BIT(int n) {
		N = n + 1;
	}
	void add(int i, type w) { // a[i] += w
		for (int x = i; x <= N; x += x & -x) {
			data[x] += w;
		}
	}
	type sum(int i) { // iまでの和 [1,i]
		type ret = 0;
		for (int x = i; x > 0; x -= x & -x) {
			ret += data[x];
		}
		return ret;
	}
	// [l, r]
	type sum(int l, int r) {
		if (l > r) return 0;
		return sum(r) - sum(l - 1);
	}
};


LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	BIT<int>bit(1e9 + 10);

	bool canplace = 0;
	FOR(i, 0, N) {
		int x; cin >> x;
		canplace = 0;
		/*debug(bit.sum(x));
		debug(bit.sum(x + 1));
		debug(bit.sum(x+2,1e9));*/
		if (bit.sum(1) == 1) {// もうだめ
			canplace = 0;
		}
		else if (bit.sum(x + 1) == x &&  bit.sum(x + 2, 1e9 + 5)) {
			canplace = 0;
		}
		else { 
			canplace = 1;
			int p = x;
			while (bit.sum(p + 1, p + 1) > 0) {
				bit.add(p + 1, -1);
				p--;
				// merge
			}
			
			//debug(p);
			bit.add(p + 1, 1);

		}

		cout << (canplace ? "Yes" : "No") << endl;

	}
}

