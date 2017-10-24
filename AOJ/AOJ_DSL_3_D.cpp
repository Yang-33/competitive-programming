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

/* -----  2017/10/24  Problem: AOJ_DSL_3_D  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D&lang=jp  ----- */
/* ------問題------

Sliding Minimum Element
長さN の数列a1,a2,a3,...,aN と整数L が与えられます。
長さL の連続する部分列すべてについて、各部分列の中の最小の要素を先頭から順番に報告してください。
例えば、数列が{1,7,7,4,8,1,6} で、L が 3 の場合、長さL の部分列は{1,7,7},{7,7,4},{7,4,8},{4,8,1},{8,1,6} となりますが、
それぞれの部分列の最小値となる 1, 4, 4, 1, 1 を先頭の方から順番に出力してください。

-----問題ここまで----- */
/* -----解説等-----

セグ木でできるけどスライド最小値の練習だね

----解説ここまで---- */

LL N, L;

LL ans = 0LL;
vector<int> slideMinimum(const vector<int> &a, int k) {//indexのvecを返す
	int n = a.size();
	deque<int> deq;
	vector<int> res;
	for (int i = 0; i < n; i++) {
		while (deq.size() && a[deq.back()] >= a[i]) deq.pop_back();
		deq.push_back(i);
		if (i - k + 1 >= 0) {
			res.push_back(deq.front());
			if (deq.front() == i - k + 1) deq.pop_front();
		}
	}
	return res;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> L;
	VI a(N);
	FOR(i, 0, N)cin >> a[i];
	VI x = slideMinimum(a, L);
	FOR(i, 0, SZ(x)) {
		cout << a[x[i]]<< ((i != SZ(x) - 1) ? ' ' : '\n');
	}
	return 0;
}