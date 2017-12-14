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

/* -----  2017/10/11  Problem: 52_csacademy D  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */
int ask(int p) { cout << p << endl; int x; cin >> x; return x; }

void solve()
{
	vector <bool> was(100, 0), wasmod(100, 0);
	int cnt = 0, pos = 0;
	for (int i = 11; i > 0; --i) {
		int cur = ask(pos);
		if (cur) {
			++cnt;
			wasmod[pos % 10] = true;
			pos = (pos + 9) % 100;
		}
		pos = (pos + 1) % 100;
		if (cnt < 2 && i == 2) {
			while (!wasmod[pos % 10])
				pos = (pos + 1) % 100;
		}
		else {
			while (wasmod[pos % 10])
				pos = (pos + 1) % 100;
		}
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	FOR(_i, 0, T) {
		solve();
	}

	return 0;
}