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

/* -----  2018/04/23  Problem: yukicoder 110  / Link: http://yukicoder.me/problems/no/110  ----- */
/* ------問題------

白と黒の長さが異なるブロックがいくつかある。
下からブロックを横に積んでピラミッドを作りたい。
ただし、次のような条件がある。

・上に積むブロックは下のブロックより長さが短い。
・積むブロックの色は白と黒で交互になる。

ブロックを1個積むごとに高さが1増える。
このような条件でできる最も高いピラミッドの高さはどれくらいか？

-----問題ここまで----- */
/* -----解説等-----

大きい順にソート、優先度は白、黒で別にやる。

----解説ここまで---- */

LL ans = 0LL;
LL f(vector<PII>& a) {

	int Base = INF;
	int color = -1;
	int ret = 0;
	FOR(i, 0, SZ(a)) {
		if (Base > a[i].first && color != a[i].second) {
			ret++;
			Base = a[i].first;
			color = a[i].second;
		}
	}
	return ret;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int A; cin >> A;
	vector<PII> v;

	FOR(i, 0, A) {
		int a; cin >> a;
		v.emplace_back(a, 0);
	}
	int B; cin >> B;
	FOR(i, 0, B) {
		int b; cin >> b;
		v.emplace_back(b, 1);
	}

	sort(ALL(v), [](const PII& x, const PII& y) {
		if (x.first == y.first)return x.second > y.second;
		return x.first > y.first;
	});

	ans = f(v);
	sort(ALL(v), [](const PII& x, const PII& y) {
		if (x.first == y.first)return x.second < y.second;
		return x.first > y.first;
	});

	ans = max(ans, f(v));
	cout << ans << "\n";

	return 0;
}