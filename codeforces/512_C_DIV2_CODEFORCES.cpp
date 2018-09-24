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

/* -----  2018/09/23  Problem: CodeForces512 C div2 / Link: http://codeforces.com/contest/1058/problem/C  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	string s; cin >> s;
	VI a(N);
	int sum = 0;
	FOR(i, 0, N) {
		a[i] = s[i] - '0';
		sum += a[i];
	}
	FOR(k, 2, N+1) {
		int part = sum / k;
		if (part*k != sum)continue;
		// partで分割可能化をチェックする
		int subsum = 0;
		int cnt = 0;
		FOR(i, 0, N) {
			subsum += a[i];
			if (subsum == part) {
				subsum = 0;
				cnt++;
			}
			else if (subsum > part) {
				goto END;
			}
		}
		if (cnt == k) {
			ans = k;
			break;
		}

	END:;
	}
	if (ans) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
