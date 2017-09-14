#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/09/14  Problem: __CONTEST_NAME__ __ALPHA__  / Link: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&Itemid=99999999&category=388&page=show_problem&problem=3060  ----- */
/* ------問題------

Nim.
ただし各山について、半分より大きな数とってはいけない。(1の山はもうとれない)

-----問題ここまで----- */
/* -----解説等-----

grundy数を書くと気が付くこととして、
・二進数で1111...1111のものは0になる
・偶数はその値の半分がgrundy数になる
・奇数のgrungy数はその数を2で割り、割ったものはその数の二進数に対応するgrundy数になる(ex:17. 100001->10000(g=16/2))
したがってこれを求めるがA≦10^18なので二進数に着目すれば、偶数になるまで2で割り、偶数の半分の値がgrundy数であることが分かる

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(t, 0, T) {
		cin >> N;
		unsigned long long  grundy = 0;
		FOR(i, 0, N) {
			unsigned long long  a;
			cin >> a;
			while (a % 2) {
				a /= 2;
			}
			grundy ^= (a / 2);
		}
		cout << ((grundy!=0)?"YES":"NO") << endl;

	}


	return 0;
}
