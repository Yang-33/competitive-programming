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

/* -----  2018/05/02  Problem: AOJ 1302 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1302  ----- */
/* ------問題------

M(<12)桁の2進数がn(<129)個与えられる。これらに質問をして一意に定まるように質問をしたとき、何回質問をしなければならないか。

-----問題ここまで----- */
/* -----解説等-----

分割統治(昨日やったよね…)
2^Nだとおもったけどなんか3^Nらしい

----解説ここまで---- */

map<VI, int>Map;
int N, M;

int f(VI& a) {
	if (SZ(a) < 2)return 0;
	int &ret = Map[a];
	if (ret > 0)return ret;
	ret = M;
	FOR(i, 0, M) {
		VI a1, a0;
		FOR(j, 0, SZ(a)) {
			if (a[j] & (1 << i)) {
				a1.push_back(a[j]);
			}
			else {
				a0.push_back(a[j]);
			}
		}
		if (a1.empty() || a0.empty())continue;
		ret = min(ret, 1 + max(f(a1), f(a0)));
	}

	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (cin >> M >> N, N | M) {
		VI v;
		Map.clear();
		FOR(i, 0, N) {
			string s; cin >> s;
			v.push_back(stoi(s, 0, 2));
		}
		LL ans = f(v);
		cout << ans << "\n";
	}


	return 0;
}
