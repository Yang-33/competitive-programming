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

/* -----  2017/10/20  Problem: uva 12397  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL N;

LL ans = 0LL;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VI num(4000);
	FOR(i, 0, 4000) {
		int n = i;
		if (n % 1000 >= 900)n += 200;
		if (n % 1000 <= 499 && n % 1000 >= 400)n += 200;
		if (n % 100 >= 90)n += 20;
		if (n % 100 <= 49 && n % 100 >= 40)n += 20;
		if (n % 10 == 4 || n % 10 == 9)n += 2;
		num[i] += (n / 1000)*4;
		n %= 1000;
		num[i] += (n / 500) * 3;
		n %= 500;
		num[i] += (n / 100) * 2;
		n %= 100;
		num[i] += (n / 50) * 2;
		n %= 50;
		num[i] += (n / 10) * 2;
		n %= 10;
		num[i] += (n / 5) * 2;
		n %= 5;
		num[i] += n;
	}
	/*FOR(i, 0, 20)cout << num[i] << " ";
	cout << endl;*/
	while (cin >> N) {
		cout << num[N] << endl;
	}


	return 0;
}
