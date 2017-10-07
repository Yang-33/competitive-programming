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

/* -----  2017/10/06  Problem: CodeForces439 A div2 / Link: http://codeforces.com/contest/869/problem/A  ----- */
/* ------問題------

.

-----問題ここまで----- */
/* -----解説等-----

4ね

----解説ここまで---- */

LL N;

LL ans = 0LL;
LL x[2003];
LL y[2003];
bool used[5000005];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {
		cin >> x[i];
		used[x[i]] = 1;
	}
	FOR(i, 0, N) {
		cin >> y[i];
		used[y[i]] = 1;
	}
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			ans += used[x[i] ^ y[j]];
			//if (((x[i] ^ y[j]) <= 2 * N)&&(0<(x[i] ^ y[j])))ans++;
		}
	}
	//debug(ans);
	cout << ((ans%2==0)?"Karen":"Koyomi") << "\n";

	return 0;
}