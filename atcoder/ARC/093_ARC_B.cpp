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

/* -----  2018/03/25  Problem: ARC 093 B / Link: http://arc093.contest.atcoder.jp/tasks/arc093_b  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

なんか左右に切って、適当に塗ると解ける

----解説ここまで---- */

LL N, A, B;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> A >> B;
	VVI m(100, VI(100, 0));
	FOR(i, 0, 100) {
		FOR(j, 50, 100) {
			m[i][j] = 1;
		}
	}

	//siro
	A--; B--;
	for (int i = 1; i < 100; i += 2) {
		for (int j = 51; j < 99; j += 2) {
			if (A > 0)m[i][j] = 0, A--;
		}
	}
	for (int i = 1; i < 100; i += 2) {
		for (int j = 1; j < 49; j += 2) {
			if (B > 0)m[i][j] = 1, B--;
		}
	}
	string str1 = ".#";
	cout << 100 << " " << 100 << endl;
	FOR(i, 0, 100) {
		FOR(j, 0, 100) {
			cout << str1[m[i][j]];
		}cout << endl;
	}

	return 0;
}
