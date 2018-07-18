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

/* -----  2018/07/23  Problem: AOJ 0517 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0517  ----- */
/* ------問題------

1 から n までの整数がそれぞれ 1 つずつ書かれた n 枚のカードと,1 枚の白紙の カードがある.これら n + 1 枚のカードの内,k 枚のカードが与えられる.ただし, 1 ≤ k ≤ n である.白紙のカードには 1 から n までの整数を 1 つ書くことができ る.与えられたカードだけで,できるだけ長い連続した整数列を作りたい.
与えられるカードが入力されたときに, 与えられたカードから作ることができる連 続した整数列の最大長を出力するプログラムを作成せよ.

-----問題ここまで----- */
/* -----解説等-----

列を区間として扱うことができれば、あとはその連続区間が隙間1であるかどうかを見ることになる。
これはO(NlogN)でできる。

----解説ここまで---- */

using LL = long long; template<class T> using V = vector<T>;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K;
	while (cin >> N >> K, N) {
		V<int>a(K);
		FOR(i, 0, K) {
			cin >> a[i];
		}
		SORT(a);
		int has = 0;
		if (a[0] == 0)has = 1;
		int ans = 0;
		using PII = pair<int, int>;
		V<PII>v;
		int s = has;
		FOR(i, has, K - 1) {
			if (a[i] + 1 == a[i + 1]) {
				continue;
			}
			else {
				v.push_back(PII(s, i));
				ans = max(ans, i - s + 1);
				s = i + 1;
			}
		}

		v.push_back(PII(s, K - 1));
		if (has)FOR(i, 0, SZ(v) - 1) {
			int LE = v[i].second;
			int RS = v[i + 1].first;
			if (a[LE] + 2 == a[RS]) {
				ans = max(ans, v[i + 1].second - v[i].first + 2);
			}
		}
		cout << ans << endl;
	}
	return 0;
}//