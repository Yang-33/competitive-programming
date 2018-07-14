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

/* -----  2018/07/14  Problem: edu47_d_codeforces / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

連結らしいよ

----解説ここまで---- */


/*最大公約数を求める関数(再帰版ユーグリッドの互除法)*/
long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }

/*最小公倍数を求める関数。最小公倍数の性質( a×b÷[aとbの最大公約数] )を利用。*/
long long  lcm(long long  a, long long  b) { return a / gcd(a, b) * b; }


LL N, M;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	if (M < N-1) {
		cout << "Impossible" << endl;
		return 0;
	}
	vector<PII>a;
	FOR(i, 1, N+1) {
		FOR(j, i+1,N+1) {
			if (gcd(i, j) == 1) {
				a.push_back(PII(i, j));
			}
		}
		if (SZ(a) >= M)break;
	}

	if (SZ(a) < M) {
		cout << "Impossible" << endl;
	}
	else {
		cout << "Possible" << endl;
		FOR(i, 0, M) {
			cout << a[i].first << " " << a[i].second << endl;
		}
	}

	return 0;
}
