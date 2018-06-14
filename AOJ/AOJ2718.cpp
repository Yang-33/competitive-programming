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

/* -----  2018/06/15  Problem: AOJ 2718 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2718  ----- */
/* ------問題------

一度乗ると消える矢印の板がある。
最大で何回乗れるか

-----問題ここまで----- */
/* -----解説等-----

消えてしまうのでシュミレーションしたい。
したがって探索O(N^2)
さらにこれに検索時間がかかる。
setで挿入削除をすればlogNなのであとはやっていけばよい
setが重いときはBITでもできる。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int N;  cin >> N;
	VI x(N), y(N);
	VS vs(N);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i] >> vs[i];
	}
	VI xc = x, yc = y;
	SORT(xc), UNIQ(xc);
	SORT(yc), UNIQ(yc);

	VVI masu(SZ(yc), VI(SZ(xc), 0));
	FOR(i, 0, N) {
		y[i] = lower_bound(ALL(yc), y[i]) - yc.begin();
		x[i] = lower_bound(ALL(xc), x[i]) - xc.begin();
		masu[y[i]][x[i]] = vs[i][0];
	}

	int ans = 1;
	FOR(i, 0, N) {
		// ith start simulation
		vector<set<int>>Yset(SZ(yc));
		vector<set<int>>Xset(SZ(xc));
		FOR(j, 0, N) {
			if (i == j)continue;
			Yset[y[j]].insert(x[j]);
			Xset[x[j]].insert(y[j]);
		}
		int posy = y[i], posx = x[i];
		int ret = 1;
		char c = masu[posy][posx];
		while (1) {// erase simulation

			if (c == '<' || c == '>') {// xで遷移 Yset
				auto it = Yset[posy].lower_bound(posx);
				if (c == '<') {
					if (it == Yset[posy].begin())break;
					it--;
				}
				else {
					if (it == Yset[posy].end())break;
				}
				posx = *it;
				c = masu[posy][posx];
			}
			else { // yで遷移 Xset
				auto it = Xset[posx].lower_bound(posy);
				if (c == '^') {
					if (it == Xset[posx].begin())break;
					it--;
				}
				else {
					if (it == Xset[posx].end())break;
				}
				posy = *it;
				c = masu[posy][posx];
			}
			ret++;
			Yset[posy].erase(posx);
			Xset[posx].erase(posy);
			ans = max(ans, ret);
		}
	}



	cout << ans << "\n";


	return 0;
}