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

/* -----  2017/11/29  Problem: 077_arc_c / Link: https://arc077.contest.atcoder.jp/tasks/arc077_a  ----- */
/* ------問題------

長さ n の数列 a1,…,an が与えられます。 空の数列 b に対して、以下の操作を n 回行うことを考えます。
i 回目には
数列の i 番目の要素 ai を b の末尾に追加する。
b を逆向きに並び替える。
この操作をしてできる数列 b を求めて下さい。

-----問題ここまで----- */
/* -----解説等-----

愚直にやるのは間に合わないが、dequeというデータ構造があるのでこれをする。
なくても自分で場合分けすればよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	deque<int>dq;
	cin >> N;
	FOR(i, 0, N) {
		int a; cin >> a;
		if (SZ(dq) % 2 == N%2) { dq.push_back(a); }
		else { dq.push_front(a); }
	}
	FOR(i, 0, N) {
		cout << dq.front() << (i != N - 1 ? ' ' : '\n');
		dq.pop_front();
	}

	return 0;
}
